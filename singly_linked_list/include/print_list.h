//
// Created by jsabs on 11/22/21.
//

#ifndef SINGLY_LINKED_LIST_PRINT_LIST_H
#define SINGLY_LINKED_LIST_PRINT_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "singly_linked_list.h"

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: INT values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_int (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: FLOAT values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_float (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: DOUBLE values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_double (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: STRING values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_str (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: UINT8_T values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_uint8 (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: INT8_T values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_int8 (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: UINT16_T values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_uint16 (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: INT16_T values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_int16 (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: UINT32_T values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_uint32 (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: UINT64_T values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_uint64 (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: INT64_T values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_int64 (sll_t * sll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: BOOL values
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_bool (sll_t * sll);

#endif //SINGLY_LINKED_LIST_PRINT_LIST_H
