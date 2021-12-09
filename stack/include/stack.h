//
// Created by jsabs on 12/9/21.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <errno.h>

#define CLEAN(a); if (a) free(a);(a)=NULL;

typedef struct __stack_node node_t;
typedef struct __stack_container stack_t;
typedef void (*del_f) (void * node_t);
typedef void (*print_f) (stack_t * stack);

typedef struct __stack_node
{
    void                  * data;
    size_t                  index;
    struct __stack_node   * next;
} node_t;

typedef struct __stack_container
{
    node_t * top;
    node_t * bottom;
    size_t   size;
    del_f    delete_func;
    print_f  print_func;
} stack_t;

stack_t * init (del_f del_func_t);

#endif //STACK_STACK_H
