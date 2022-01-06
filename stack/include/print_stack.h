//
// Created by jsabs on 12/9/21.
//

#ifndef STACK_PRINT_STACK_H
#define STACK_PRINT_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#include "stack.h"

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: INT values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_int (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: FLOAT values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_float (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: DOUBLE values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_double (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: STRING values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_str (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: UINT8_T values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_uint8 (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: INT8_T values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_int8 (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: UINT16_T values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_uint16 (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: INT16_T values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_int16 (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: UINT32_T values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_uint32 (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: UINT64_T values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_uint64 (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: INT64_T values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_int64 (stack_t * stack);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire stack currently in use by displaying each node's current
 *          position within the stack container as well as its data: BOOL values
 * @param stack - (stack_t *) a pointer to the current stack container
 * @return - None. If the stack_t container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_stack_bool (stack_t * stack);

#endif //STACK_PRINT_STACK_H
