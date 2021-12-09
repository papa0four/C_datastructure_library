//
// Created by jsabs on 12/9/21.
//

#ifndef STACK_PRINT_NODE_H
#define STACK_PRINT_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

void print_int (void * data);

void print_float (void * data);

void print_double (void * data);

void print_string (void * data);

void print_uint8 (void * data);

void print_int8 (void * data);

void print_uint16 (void * data);

void print_int16 (void * data);

void print_uint32 (void * data);

void print_uint64 (void * data);

void print_int64 (void * data);

void print_bool (void * data);

#endif //STACK_PRINT_NODE_H
