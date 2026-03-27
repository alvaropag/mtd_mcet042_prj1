#include <stdio.h>
#include <string.h>
#include "simple_list.h"
#include "file_reader.h"

const ListNode *load_file_prompt(void)
{
    char filename[512];
    printf("Digite o caminho do arquivo (Enter para usar './myfile.dat'): ");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    if (filename[0] == '\0')
    {
        strcpy(filename, "./myfile.dat");
    }

    const ListNode *head = load_file(filename);
    if (head != NULL)
        printf("Arquivo '%s' carregado com sucesso!\n", filename);
    else
        printf("Erro ao carregar o arquivo '%s'!\n", filename);

    return head;
}

void list_data(const int type, const ListNode * head)
{
    print_list_type(head, type);
}

void list_data_top(const int top, const ListNode * head)
{
    if (head == NULL)
    {
        printf("Lista vazia!\n");
        printf("Por favor, carregue uma lista para usar esta função!\n");
    }
    else
    {
        print_list_top(head, top);
    }
}

void list_file_data(const ListNode * head)
{
    if (head == NULL)
    {
        printf("Lista vazia!\n");
        printf("Por favor, carregue uma lista para usar esta função!\n");
    }
    else
    {
        printf("Qual tipo de dados deseja visualizar?\n");
        printf("1 - Inteiros\n");
        printf("2 - Reais\n");
        printf("3 - Strings\n");
        printf("4 - Caracter\n\n");
        printf("0 - Cancelar operação\n");
        int tipo;
        scanf("%d", &tipo);
        switch (tipo)
        {
            case 1:
                printf("Inteiros:\n");
                print_list_type(head, TYPE_INT);
                break;
            case 2:
                printf("Reais:\n");
                print_list_type(head, TYPE_FLOAT);
                break;
            case 3:
                printf("Strings:\n");
                print_list_type(head, TYPE_STRING);
                break;
            case 4:
                printf("Caracteres:\n");
                print_list_type(head, TYPE_CHAR);
                break;
            default:
                break;
        }

    }
}

int main(void)
{
    const ListNode *head = NULL;
    int numero;

    while (1)
    {

        if (head == NULL)
        {
            printf("1 - Carregar arquivo\n");
        }
        else
        {
            printf("2 - Listar dados do Arquivo\n");
            printf("3 - Listar TOP(20) dados do Arquivo\n");
        }
        printf("0 - Sair\n");

        scanf("%d", &numero);
        switch (numero)
        {
            case 1:
                head = load_file_prompt();
                break;
            case 2:
                list_file_data(head);
                break;
            case 3:
                print_list_top(head, 20);
                break;

            case 0:
                printf("Finalizando programa...\n");
                return 0;

            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }

        printf("\n---------------------------------------------------------------\n");
    }
}

