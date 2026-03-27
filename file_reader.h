//
// Created by alvaropag on 24/03/2026.
//

#ifndef PRJ1_FILE_READER_H
#define PRJ1_FILE_READER_H

#include <stdio.h>
#include "list_node.h"

DataValue *read_value(FILE *file);
ListNode *load_file(const char* path);

#endif //PRJ1_FILE_READER_H