//
// Created by jsabs on 11/17/21.
//

#ifndef SINGLY_LINKED_LIST_SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h> // tentative
#include <errno.h>

#include "compare_functions.h"
#include "delete_function.h"

/* FREE/NULL Macro for ease of use */
#define CLEAN(a) if (a) free(a);(a)=NULL;

typedef struct sll_node node_t;
typedef struct sl_list sll_t;
typedef int (*cmp_f) (const void * a, const void * b);
typedef void (*del_f) (void * node_t);
typedef void (*print_f) (sll_t * sll);

typedef struct sll_node
{
    size_t            index;
    void            * data;
    struct sll_node * next;
} node_t;

typedef struct sl_list
{
    node_t * head;
    node_t * tail;
    size_t   size;
    cmp_f    compare_func;
    del_f    delete_func;
    print_f  print_func;
} sll_t;

/**
 * @brief - initializes an empty singly linked list structure. Set the HEAD and TAIL to NULL
 *          and sets the initial size to 0. NOTE: This does not allocate any nodes or node data
 * @param - None
 * @return - (struct sl_list *) a pointer to the heap allocated singly linked list structure
 */
 sll_t * init(cmp_f cmp_func_t,
              del_f del_func_t,
              print_f print_func_t);

 /**
  * @brief - allocates a node_t structure pointer to the heap, creating the new node to
  *          insert into the singly linked list structure
  * @param data - (void *) a generic pointer to the data to be stored within the node
  * @return - a heap allocated node structure to insert into the singly linked list or
  *           returns NULL on error setting errno for specific error
  */
 node_t * create_node(void * data);

 /**
  * @brief - appends a newly allocated node to an existing linked list. If there are currently no
  *          nodes within the list, append() will add the new node to the list, setting the list
  *          HEAD and TAIL and updating the index member. If the list is populated, append() will
  *          add the node to the end of the list and update the index appropriately.
  * @param sll
  * @param node_data
  * @return
  */
int append(sll_t * sll, void * node_data);

/**
 * @brief -
 * @param sll -
 * @param data -
 * @param flag_t -
 * @return -
 */
node_t * find_singular_node (sll_t * sll, const void * data);

/**
 *
 * @param sll -
 *
 */
void print_list (sll_t * sll, char * specifier);

/**
 * @brief -
 * @param sll -
 * @param n_to_rmv -
 * @return - None
 */
void remove_node (sll_t * sll, const void * data);

/**
 *
 *
 *
 */
 void destroy_list (sll_t * sll);

#endif //SINGLY_LINKED_LIST_SINGLY_LINKED_LIST_H
