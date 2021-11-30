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

// struct declaration for the queue node storage container
typedef struct q_node qnode_t;
// struct declaration for the queue storage container
typedef struct queue queue_t;
// function pointer for queue node data comparison
typedef int (*cmp_f) (const void * a, const void * b);
// function pointer for queue node deletion/memory deallocation
typedef void (*del_f) (void * node_t);
// function pointer for queue formatted print
typedef void (*print_f) (struct queue * sll);
// function pointer for queue node formatted print
typedef void (*print_n) (void * data);

// queue node struct definition
typedef struct q_node
{
    size_t         pos;
    void         * data;
    qnode_t      * next;
    print_n        pnode_func;
} qnode_t;

// queue container struct definition
typedef struct queue
{
    qnode_t     * head;
    qnode_t     * tail;
    size_t        size;
    cmp_f         compare_func;
    del_f         delete_func;
    print_f       print_func;
} queue_t;

// free/NULL macro for redundancy removal
#define CLEAN(a) if (a) free(a);(a)=NULL;

/**
 * @brief - initializes and empty queue container and allocates it to the heap.
 *          If any of the function pointers passed are NULL, init will set errno to
 *          EINVAL, print an error message to STDERR, and return a NULL pointer.
 * @param cmp_func_t - (cmp_f) the data type specific compare function to be used by the user
 * @param del_func_t - (del_f) the delete function pointer contained within the queue
 * @param print_func_t - (print_f) the appropriate print function pointer to display the queue
 *                       and its contents in a digestible format
 * @return - returns a pointer to the heap allocated queue container with the appropriate
 *           queue function pointers assigned and an initial size of 0, signifying an empty
 *           queue. On heap allocation error, init will return NULL and errno will be set to
 *           ENOMEM.
 */
queue_t * init (cmp_f cmp_func_t,
              del_f del_func_t,
              print_f print_func_t);

/**
 * @brief - adds a new queue node to the container at the end (queues are FIFO). This function
 *          calls a static helper function that allocates a new node container to the heap,
 *          store the data within the data member and assigns the appropriate node print function
 *          based upon the data type stored within the node.
 * @param queue - (queue_t *) a pointer to the currently allocated queue container
 * @param data - (void *) an arbitrary pointer to the specific data to be stored within the queue node
 * @param pnode_func_t - (print_n) a function pointer to the specific print function meant for the data
 *                       type that is stored within the node. NOTE: if the data to be stored within
 *                       the node is a user define struct, then it is advised that the user also
 *                       create a print function to pass within this parameter that is able to print
 *                       the data appropriately
 * @return - on success, enqueue returns 0, indicating that the node has been added to the queue. If
 *           any one of the parameters passed are invalid, then this function will return -1 with errno
 *           set to EINVAL, letting the user know that a parameter passed was not valid. If enqueue cannot
 *           successfully create a new queue node, the function call will return 1 and errno will not be set.
 *           However, the static create_node function will print an error message to STDERR, and more than
 *           likely, errno will be set to EINVAL or ENOMEM depending on where the function failed.
 */
int enqueue (queue_t * queue, void * data, print_n pnode_func_t);

/**
 * @brief - successfully grabs the first node within the queue pointed to by queue->head. Because this
 *          function returns a pointer to a qnode_t type it is up to the user to determine how they want
 *          to extract the node's data a free up the allocated memory held by the queue node container.
 *          Additionally, the index member of the qnode_t struct will be decremented appropriately by a
 *          static helper function called within dequeue. NOTE: The user does not have to interact with the
 *          position member of the queue nodes as they are automatically assigned and updated as the queue
 *          is populated and as nodes are removed. Additionally, dequeue automatically resizes the queue
 *          to reflect the removal of a node.
 * @param queue - (queue_t *) a pointer to the queue container
 * @return - a pointer to the the node that was at the front of the queue that has been removed. This node is
 *           no longer stored within the queue, however, the node is still allocated and the data is still
 *           accessible until the user manages the memory allocated.
 */
qnode_t * dequeue (queue_t * queue);

/**
 * @brief - a boolean function meant to determine if the current queue storage container is empty.
 *          If the queue container pointer passed is NULL, errno will be set to EINVAL and is_empty
 *          will return false.
 * @param queue - (queue_t *) a pointer to the current queue storage container
 * @return - if the current queue container is empty, is_empty returns a true boolean value, else
 *           it returns false and errno is not set.
 */
bool is_empty(queue_t * queue);

/**
 * @brief - this function looks at the current head node stored within the queue container and calls the
 *          formatted print node function to let the user know about the data stored within the head node.
 *          If the queue container pointer passed is NULL, the function will not print the node data and
 *          errno will be set to EINVAL. If no errors occur, the head node's data will print to STDOUT.
 * @param queue - (queue_t *) a pointer to the current queue storage container
 * @return - None, on error, errno will be set to EINVAL.
 */
void peek (queue_t * queue);

/**
 * @brief - this function is meant to the return the current size of the queue based upon the current number
 *          of nodes stored within tracked by the size member of the queue storage container struct. NOTE: If the
 *          queue parameter passed is NULL, get_queue_size will return 0 with errno set to EINVAL. If the queue
 *          is empty, get_queue_size will also return 0, however, errno will not be set. Otherwise,
 * @param queue - (queue_t *) a pointer to the current queue storage container
 * @return -
 */
size_t get_queue_size (queue_t * queue);

/**
 * @biref - this function is meant to iteratively delete each node from a populated queue and appropriately
 *          manage the allocated memory for each node, free'ing it and setting it to NULL before doing the same
 *          to the queue container itself. If the current queue container passed is empty, destroy_queue simply
 *          deallocates the memory for the container and sets the pointer to NULL. If the queue parameter passed
 *          is already NULL, destroy_queue will return and errno will be set to EINVAL and an error message will
 *          be sent to STDERR. NOTE: this function also sets size to 0 before destroying the container, even though
 *          this is not necessary.
 * @param queue - (queue_t *) a pointer to the current queue storage container
 * @return - None, however, on error a message will be presented to the user and errno will be set to EINVAL.
 */
void destroy_queue (queue_t * queue);

#endif //DATASTRUCTURES_QUEUE_H
