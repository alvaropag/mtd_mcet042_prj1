//
// Created by alvaropag on 27/03/2026.
//

#ifndef PRJ1_LIST_NODE_H
#define PRJ1_LIST_NODE_H

typedef enum TypeInfo
{
    TYPE_INT = 'I',
    TYPE_STRING = 'S',
    TYPE_FLOAT = 'F',
    TYPE_CHAR = 'C'
} TypeInfo;

typedef union
{
    int i;
    char c;
    float f;
    char *s;
} ValueUnion;

typedef struct DataValue
{
    TypeInfo type;
    ValueUnion v;
    int size;
} DataValue;

typedef struct ListNode {
    DataValue value;
    struct ListNode *next;
} ListNode;

#endif //PRJ1_LIST_NODE_H
