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

/* free/NULL macro to avoid redundancies */
#define CLEAN(a); if (a) free(a);(a)=NULL;

/* declare stack node struct */
typedef struct __stack_node node_t;
/* declare stack container struct */
typedef struct __stack_container stack_t;
/* declare delete node function pointer */
typedef void (*del_f) (void * node_t);
/* declare print stack data structure function pointer */
typedef void (*print_f) (stack_t * stack);
/* declare print node data function pointer */
typedef void (*print_n) (void * node);

/**
 * @brief - defined stack node date container
 * @member data - (void *) a generic pointer to store stack node data
 * @member index - (size_t) the current position a node holds within the stack container
 * @member next - (struct __stack_node *) a pointer to the next node within the stack container
 * @member pnode_func - (print_n) function pointer to the print node data function
 */
typedef struct __stack_node
{
    void                  * data;
    size_t                  index;
    struct __stack_node   * next;
    print_n                 pnode_func;
} node_t;

/**
 * @brief - defined stack data structure container
 * @member top - (node_t *) a pointer to the node currently residing at the top of the stack
 *               container
 * @member bottom - (node_t *) a pointer to the bottom most node within the stack container
 * @member size - (size_t) the current count of nodes within the stack container
 * @member delete_func - (del_f) function pointer to the delete node function
 * @member print_func - (print_f) function pointer to the print data within entire stack function
 *                      NOTE: this function will print the data of each node currently residing
 *                      within the stack container
 */
typedef struct __stack_container
{
    node_t * top;
    node_t * bottom;
    size_t   size;
    del_f    delete_func;
    print_f  print_func;
} stack_t;

/**
 * @brief - this function is intended to initialize and allocate memory to the heap, in order to
 *          allow the user to create an empty stack data structure container before beginning to
 *          create and store stack nodes. Both the top and bottom pointers are initialized to NULL
 *          and the size is set to 0. NOTE: it is important that the user determine the type of data
 *          desired to store within each node in order to utilize the correct print function prototype.
 *          To see the list of print prototypes, see the print_stack.c file.
 * @param del_func_t - (del_f) a function pointer, pointing to the delete node function prototype. This
 *                     allows the user, if need be, to delete a particular node out of the stack
 *                     container. NOTE: this function pointer is used within the destroy_stack function
 *                     to appropriate clean up memory allocated for each stack node.
 * @param print_func_t - (print_f) a function pointer, pointing to the appropriate stack node data print
 *                       print prototype, allowing the user to see all nodes and their data currently
 *                       residing within the stack container
 * @return - (struct stack_t *) ON SUCCESS: returns a pointer to the heap allocated stack container. The
 *           initial data structure returned is empty, where the pointer to top and bottom are NULL and the
 *           current size is 0, however, the del_f and print_f function pointers are pointing to the appropriate
 *           function prototypes. There are two instances in which init may fail. If one or both function
 *           pointer parameters passed are NULL, errno will be set to EINVAL, an appropriate error message will
 *           be displayed to the user via STDERR, and init will return a NULL pointer. The second instance would
 *           be the result of a failed call to the calloc function, in which the user's system is unable to
 *           allocate memory onto the heap in order to create and store the stack data structure. In this instance
 *           errno will be set to ENOMEM, the appropriate error message will be displayed to the user via STDERR,
 *           and init will return a NULL pointer. NOTE: it is important that the user check the return value
 *           immediately after calling the init function to determine whether or not the stack_t pointer value is
 *           NULL. This check will also allow the user to determine why the call to init failed for mitigation and
 *           debugging purposes.
 */
stack_t * init (del_f del_func_t, print_f print_func_t);

/**
 * @brief - this function is meant to place a newly created stack node onto the top of the stack. Given the
 *          nature of a stack data structure (FILO or first in last out) the more nodes pushed onto the stack,
 *          the more nodes will have to be removed from the stack in order to obtain the data from the first
 *          node placed within. NODE: similarly to the initialization of the stack data structure, it is
 *          important that the user determines the type of data they wish to store within the node in order to
 *          choose the correct print node function prototype. To find the list of the print node prototypes
 *          please see the print_node.c file.
 * @param stack - (stack_t *) a pointer to the current stack data structure container
 * @param data - (void *) a generic pointer to the data desired to be stored within the stack node
 * @param pnode_func_t - (print_n) a function pointer to the appropriate print node function
 * @return - (int) ON SUCCESS: the push function will allocate a newly created stack node onto the heap, store
 *           the data parameter passed and place the node at the top or first in a series of nodes. Once placed,
 *           every successive node's index will be updated (if they exist) and the size of the stack will be
 *           incremented by 1, resulting in a return value of 0. There are four instances in which push may fail. The first is if the user passes
 *           a NULL stack_t * pointer, suggesting no existing stack data storage container exists. The second is
 *           if the data pointer passed is NULL, suggesting not data exists to store within the node. The third
 *           is if the print_n function pointer passed is NULL, suggesting that the user did not select an
 *           appropriate print node function prototype. In all three cases, push will return a value of -1,
 *           setting errno to EINVAL, and display an appropriate error message to the user via STDERR. The fourth
 *           instance in which push may fail is during an internal call to create_node, in which the requesting node
 *           is not properly created and the return value is checked. Upon failure, create_node and push will display
 *           an appropriate error message to the user via STDERR and return a value of 1. NOTE: It is important
 *           for the user to check the return value after calling push in order to determine success/failure before
 *           proceeding.
 */
int push (stack_t * stack, void * data, print_n pnode_func_t);

/**
 * @brief - this function removes the top node from the stack data storage container, allowing the user to
 *          utilize its data per their specifications. Once the node is removed from the top of the stack,
 *          the list indices and overall stack size are updated automatically, allowing for ease of use on
 *          the user.
 * @param stack - (stack_t *) a pointer to the current stack data structure storage container
 * @return - (node_t *) ON SUCCESS: a pointer to the most recent node that was residing on the top of the stack
 *           storage container. Once extracted, the top pointer is updated to the next top most node and all
 *           subsequent node indices are updated and the overall stack size is decremented by 1. There are two
 *           instances in which pop may fail. The first is if the stack_t * parameter pointer passed is NULL, in
 *           which errno will be set to EINVAL, an appropriate error message will be displayed to the user via
 *           STDERR, and a NULL pointer will be returned. The second instance is if the current stack container
 *           is empty, holding no nodes. If pop is called on an empty stack data structure, errno will not be set,
 *           however, an appropriate error message is displayed to the user via STDERR and a NULL pointer is returned.
 *           NOTE: It is important for the user to check the return value immediately after calling the pop function.
 *           This will allow the user to determine success/failure before proceeding.
 */
node_t * pop (stack_t * stack);

/**
 * @brief - this function is meant to give the user the ability to view the top most node on the stack, by
 *          displaying its data via the print node function pointer.
 * @param stack - (stack_t *) a pointer to the current stack data structure storage container
 * @return - (None) ON SUCCESS: peek will determine whether or not nodes exist within the stack storage container.
 *           If the current stack container is empty, peek will display a message via STDOUT suggesting that there
 *           is no top node and will inform the user that the stack is empty. If the current stack container
 *           contains at least one node, the top-most node's data will be displayed to the user via STDOUT. There
 *           is one instance in which peek may fail. If the stack_t parameter pointer passed is NULL, errno will
 *           be set to EINVAL, an appropriate message will be displayed to the user via STDERR, and peek will
 *           return. There is no return type for the peek function, therefore it is up to the user to view the
 *           displayed output to determine success or failure of the peek function call.
 */
void peek (stack_t * stack);

/**
 * @brief - this function allows the user to determine the amount of data (nodes) currently residing within the
 *          stack data structure storage container.
 * @param stack - (stack_t *) a pointer to the current stack data structure storage container
 * @return - (size_t) ON SUCCESS: get_stack_size will return an integer value (size_t) determining the number of
 *           nodes currently stored within the stack storage container. If the stack is currently empty,
 *           get_stack_size will return 0. There is one instance where get_stack_size may fail. If the stack_t
 *           parameter pointer passed is NULL, errno will be set to EINVAL, an appropriate error message will be
 *           displayed to the user via STDERR, and a value of 0 will be returned. NOTE: upon error and if the stack
 *           is empty will both return a value of 0, however, upon error, a message will be displayed. Therefore,
 *           it is important for the user to pay attention to the output to determine success or failure when dealing
 *           with an empty stack.
 */
size_t get_stack_size (stack_t * stack);

/**
 * @brief - this function allows the user to appropriately manage all memory allocated while utilizing the stack
 *          data structure. Regardless of the capacity status of the stack storage container, destroy_stack
 *          appropriately removes all nodes, free'ing and nullifying the allocated heap memory, before doing the
 *          same to the actual stack container.
 * @param stack - (stack_t *) a pointer to the current stack data structure storage container
 * @return - (None) ON SUCCESS: destroy_stack will iteratively remove each node (1 or more) and clean the allocated
 *           heap memory before nullifying the top and bottom pointers, zeroing the capacity, and cleaning the heap
 *           allocated memory for the stack container. There is one instance where destroy_stack may fail. If the
 *           stack_t pointer parameter passed is NULL, errno will be set to EINVAL, an appropriate error message will
 *           be displayed to the user via STDERR, and destroy_stack will return without cleaning up the data.
 */
void destroy_stack (stack_t * stack);

#endif //STACK_STACK_H
