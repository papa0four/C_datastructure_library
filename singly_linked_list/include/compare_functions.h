//
// Created by jsabs on 11/19/21.
//

#ifndef SINGLY_LINKED_LIST_COMPARE_FUNCTIONS_H
#define SINGLY_LINKED_LIST_COMPARE_FUNCTIONS_H

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

int cmp_int_t (const void * a, const void * b);

int cmp_flt_t (const void * a, const void * b);

int cmp_dbl_t (const void * a, const void * b);

int cmp_str_t (const void * a, const void * b);

int cmp_uint8_t (const void * a, const void * b);

int cmp_int8_t (const void * a, const void * b);

int cmp_uint16_t (const void * a, const void * b);

int cmp_int16_t (const void * a, const void * b);

int cmp_uint32_t (const void * a, const void * b);

int cmp_uint64_t (const void * a, const void * b);

int cmp_int64_t (const void * a, const void * b);

int cmp_bool_t (const void * a, const void * b);

#endif //SINGLY_LINKED_LIST_COMPARE_FUNCTIONS_H
