//
// Created by alvaropag on 24/03/2026.
//
#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"
#include "simple_list.h"

//funções iniciam com static para ficarem "privadas"
static DataValue *create_float_value(const float value)
{
    DataValue *novo = malloc(sizeof(DataValue));
    if (novo == NULL) return NULL;
    novo->type = TYPE_FLOAT;
    novo->v.f = value;
    novo->size = sizeof(float);
    return novo;
}

static DataValue *create_int_value(const int value)
{
    DataValue *novo = malloc(sizeof(DataValue));
    if (novo == NULL) return NULL;
    novo->type = TYPE_INT;
    novo->v.i = value;
    novo->size = sizeof(int);
    return novo;
}

static DataValue *create_char_value(const char value)
{
    DataValue *novo = malloc(sizeof(DataValue));
    if (novo == NULL) return NULL;
    novo->type = TYPE_CHAR;
    novo->v.c = value;
    novo->size = sizeof(char);
    return novo;
}

static DataValue *create_string_value(const int size, char *value)
{
    DataValue *novo = malloc(sizeof(DataValue));
    if (novo == NULL) return NULL;
    novo->type = TYPE_STRING;
    novo->v.s = value;
    novo->size = size;
    return novo;
}

DataValue *read_value(FILE *file)
{
    //buffers
    char c;
    int size;
    int value_int;
    float value_float;
    char value_char;

    //lÊ o tipo e o tamanho, se retornou os dados, faz a leitura do valor
    if (fread(&c,sizeof(char),1,file) == 1 &&
        fread(&size,sizeof(int),1,file) == 1)
    {
        switch (c)
        {
            case TYPE_INT:
                {
                    fread(&value_int,sizeof(int),1,file);
                    return create_int_value(value_int);
                }

            case TYPE_FLOAT:
                {
                    fread(&value_float,sizeof(float),1,file);
                    return create_float_value(value_float);
                }

            case TYPE_CHAR:
                {

                    fread(&value_char,sizeof(char),1,file);
                    return create_char_value(value_char);
                }

            case TYPE_STRING:
                {
                    char* value_string = malloc(size + 1); // +1 para o finalizador de string '\0'
                    if (value_string == NULL) return NULL;
                    fread(value_string, 1, size, file);
                    value_string[size] = '\0'; // finaliza a string
                    return create_string_value(size, value_string);
                }

            default:
                return NULL;
        }
    }
    return NULL;
}

ListNode *load_file(const char* path)
{
    /*cria as variáveis auxiliares*/
    ListNode *head = NULL;
    ListNode *current = NULL;
    DataValue *current_value = NULL;

    /*auxiliar para melhorar a performance de inserção append*/
    ListNode *tail = NULL;

    /*carrega o arquivo para leitura em modo binário*/
    FILE *file = fopen(path, "rb");

    if (file == NULL) return NULL;

    /*força posição de início 0*/
    fseek(file,0,SEEK_SET);

    /*enquanto conseguir ler do arquivo*/
    while ((current_value = read_value(file)) != NULL)
    {
        /*Adiciona o valor retornado na lista*/
        current = create_node(current_value->type, current_value->v, current_value->size);
        free(current_value);

        if (head == NULL)
        {
            head = current;
            tail = current;
        }
        else
        {
            tail->next = current;
            tail = current;
        }
    }

    fclose(file);

    return head;
}