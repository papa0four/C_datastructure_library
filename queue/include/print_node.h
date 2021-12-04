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

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: INT values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_int (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: FLOAT values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_float (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: DOUBLE values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_double (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: STRING values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_string (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: UINT8_T values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_uint8 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: INT8_T values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_int8 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: UINT16_T values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_uint16 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: INT16_T values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_int16 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: UINT32_T values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_uint32 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: UINT64_T values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_uint64 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: INT64_T values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_int64 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          an individual queue node by displaying node's memory address as well
 *          as its data: BOOL values NOTE: this function is called within the peek
 *          function, therefore its initial intent is to show only the node currently
 *          at position 0 or the queue head. If the user wishes to use the pnode_func
 *          member within the node container, they will be to see the memory address
 *          of the data and the data itself. If the user wishes to view the node's
 *          queue position, they will have to define their own print statement to
 *          do so.
 * @param data - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_bool (void * data);

#endif //QUEUE_PRINT_NODE_H
