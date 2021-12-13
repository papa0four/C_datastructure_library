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
typedef void (*print_n) (void * node);

typedef struct __stack_node
{
    void                  * data;
    size_t                  index;
    struct __stack_node   * next;
    print_n                 pnode_func;
} node_t;

typedef struct __stack_container
{
    node_t * top;
    node_t * bottom;
    size_t   size;
    del_f    delete_func;
    print_f  print_func;
} stack_t;

/**
 * @brief -
 * @param del_func_t
 * @param print_func_t
 * @return
 */
stack_t * init (del_f del_func_t, print_f print_func_t);

/**
 * @brief -
 * @param stack
 * @param data
 * @param pnode_func_t
 * @return
 */
int push (stack_t * stack, void * data, print_n pnode_func_t);

/**
 * @brief -
 * @param stack
 * @return
 */
node_t * pop (stack_t * stack);

/**
 * @brief -
 * @param stack -
 * @return -
 */
void peek (stack_t * stack);

/**
 * @brief -
 * @param stack
 * @return
 */
size_t get_stack_size (stack_t * stack);

/**
 * @brief -
 * @param stack -
 * @return -
 */
void destroy_stack (stack_t * stack);

#endif //STACK_STACK_H
