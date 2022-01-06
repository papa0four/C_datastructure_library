//
// Created by jsabs on 12/9/21.
//

#ifndef STACK_DELETE_NODE_H
#define STACK_DELETE_NODE_H

#include <stdlib.h>

/**
 * @brief - a function meant to take in data, free the allocated heap memory
 *          and set the pointer variable to NULL, to ensure the inability of use
 *          after the item is free'd. If the data parameter passed is NULL,
 *          delete_node has no effect and simply returns.
 * @param data - a generic pointer to a heap allocated memory location meant to
 *               be free'd and set to NULL.
 * @return - None
 */
void delete_node (void * node);

#endif //STACK_DELETE_NODE_H
