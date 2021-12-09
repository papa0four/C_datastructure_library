//
// Created by jsabs on 12/9/21.
//

#ifndef STACK_PRINT_STACK_H
#define STACK_PRINT_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "stack.h"

void print_stack_int (stack_t * stack);

void print_stack_float (stack_t * stack);

void print_stack_double (stack_t * stack);

void print_stack_str (stack_t * stack);

void print_stack_uint8 (stack_t * stack);

void print_stack_int8 (stack_t * stack);

void print_stack_uint16 (stack_t * stack);

void print_stack_int16 (stack_t * stack);

void print_stack_uint32 (stack_t * stack);

void print_stack_uint64 (stack_t * stack);

void print_stack_int64 (stack_t * stack);

void print_stack_bool (stack_t * stack);

#endif //STACK_PRINT_STACK_H
