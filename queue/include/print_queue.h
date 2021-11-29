//
// Created by jsabs on 11/29/21.
//

#ifndef QUEUE_PRINT_QUEUE_H
#define QUEUE_PRINT_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "queue.h"

void print_queue_int (queue_t * sll);

void print_queue_float (queue_t * sll);

void print_queue_double (queue_t * sll);

void print_queue_str (queue_t * sll);

void print_queue_uint8 (queue_t * sll);

void print_queue_int8 (queue_t * sll);

void print_queue_uint16 (queue_t * sll);

void print_queue_int16 (queue_t * sll);

void print_queue_uint32 (queue_t * sll);

void print_queue_uint64 (queue_t * sll);

void print_queue_int64 (queue_t * sll);

void print_queue_bool (queue_t * sll);

#endif //QUEUE_PRINT_QUEUE_H
