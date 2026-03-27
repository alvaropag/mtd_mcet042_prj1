//
// Created by alvaropag on 24/03/2026.
//
#include <stdlib.h>
#include <stdio.h>
#include "simple_list.h"


ListNode *create_node(const TypeInfo type, const ValueUnion value, const int size)
{
    ListNode *novo = malloc(sizeof(ListNode));
    if (novo == NULL) return NULL;
    novo->value.type = type;
    novo->value.v = value;
    novo->value.size = size;
    novo->next = NULL;
    return novo;
}

void print_list(const ListNode *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->value.v.i);
        head = head->next;
    }
}

void print_list_type(const ListNode *head, const TypeInfo type)
{
    while (head != NULL)
    {
        TypeInfo tipo = head->value.type;
        if (tipo != type)
        {
            head = head->next;
            continue;
        }

        switch (tipo)
        {
            case TYPE_INT:
                printf("Int: %d\n", head->value.v.i);
                break;
            case TYPE_FLOAT:
                printf("Float: %f\n", head->value.v.f);
                break;
            case TYPE_CHAR:
                printf("Char: %c\n", head->value.v.c);
                break;
            case TYPE_STRING:
                printf("String: %s\n", head->value.v.s);
                break;
            default:
                break;
        }

        head = head->next;
    }
}

void print_list_top(const ListNode *head, const int top)
{
    int i = 1;
    while (head != NULL && i <= top)
    {
        switch (head->value.type)
        {
            case TYPE_INT:
                printf("%c %d %d\n", head->value.type, head->value.size, head->value.v.i);
                break;
            case TYPE_FLOAT:
                printf("%c %d %f\n", head->value.type, head->value.size, head->value.v.f);
                break;
            case TYPE_CHAR:
                printf("%c %d %c\n", head->value.type, head->value.size, head->value.v.c);
                break;
            case TYPE_STRING:
                printf("%c %d %s\n", head->value.type, head->value.size, head->value.v.s);
                break;
            default:
                break;
        }

        head = head->next;
        i++;
    }
}