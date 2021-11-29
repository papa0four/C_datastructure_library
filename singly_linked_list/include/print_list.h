//
// Created by jsabs on 11/22/21.
//

#ifndef SINGLY_LINKED_LIST_PRINT_LIST_H
#define SINGLY_LINKED_LIST_PRINT_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "singly_linked_list.h"


void print_list_int (sll_t * sll);

void print_list_float (sll_t * sll);

void print_list_double (sll_t * sll);

void print_list_str (sll_t * sll);

void print_list_uint8 (sll_t * sll);

void print_list_int8 (sll_t * sll);

void print_list_uint16 (sll_t * sll);

void print_list_int16 (sll_t * sll);

void print_list_uint32 (sll_t * sll);

void print_list_uint64 (sll_t * sll);

void print_list_int64 (sll_t * sll);

void print_list_bool (sll_t * sll);

#endif //SINGLY_LINKED_LIST_PRINT_LIST_H
