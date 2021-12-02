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

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: INT values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_int (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: FLOAT values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_float (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: DOUBLE values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_double (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: STRING values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_str (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: UINT8_T values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_uint8 (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: INT8_T values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_int8 (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: UINT16_T values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_uint16 (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: INT16_T values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_int16 (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: UINT32_T values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_uint32 (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: UINT64_T values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_uint64 (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: INT64_T values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_int64 (queue_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire queue currently in use by displaying each node's current
 *          position within the queue container as well as its data: BOOL values
 * @param sll - (queue_t *) a pointer to the current queue container
 * @return - None. If the queue container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_queue_bool (queue_t * sll);

#endif //QUEUE_PRINT_QUEUE_H
