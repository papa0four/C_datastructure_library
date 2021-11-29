//
// Created by jsabs on 11/29/21.
//

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

typedef struct q_node qnode_t;
typedef struct queue queue_t;
typedef int (*cmp_f) (const void * a, const void * b);
typedef void (*del_f) (void * node_t);
typedef void (*print_f) (struct queue * sll);
typedef struct q_node
{
    size_t         pos;
    void         * data;
    struct qnode * next;
} qnode_t;

typedef struct queue
{
    qnode_t * head;
    qnode_t * tail;
    size_t size;
    cmp_f compare_func;
    del_f delete_func;
    print_f print_func;
} queue_t;

#define CLEAN(a) if (a) free(a);(a)=NULL;



/**
 * @brief -
 * @param cmp_func_t
 * @param del_func_t
 * @param print_func_t
 * @return
 */
queue_t init (cmp_f cmp_func_t,
              del_f del_func_t,
              print_f print_func_t);

#endif //DATASTRUCTURES_QUEUE_H
