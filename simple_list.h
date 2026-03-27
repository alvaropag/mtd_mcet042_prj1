//
// Created by alvaropag on 24/03/2026.
//

#ifndef PRJ1_SIMPLE_LIST_H
#define PRJ1_SIMPLE_LIST_H

#include "list_node.h"

ListNode *create_node(TypeInfo type, ValueUnion value, int size);

void print_list(const ListNode *head);
void print_list_type(const ListNode *head, TypeInfo type);
void print_list_top(const ListNode *head, int top);

#endif //PRJ1_SIMPLE_LIST_H