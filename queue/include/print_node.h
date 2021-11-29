//
// Created by jsabs on 11/29/21.
//

#ifndef QUEUE_PRINT_NODE_H
#define QUEUE_PRINT_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

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

#endif //QUEUE_PRINT_NODE_H
