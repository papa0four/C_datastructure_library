//
// Created by jsabs on 11/22/21.
//

#ifndef DOUBLY_LINKED_LIST_PRINT_LIST_H
#define DOUBLY_LINKED_LIST_PRINT_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include "doubly_linked_list.h"

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: INT values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_int (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: FLOAT values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_float (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: DOUBLE values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_double (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: STRING values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_str (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: UINT8_T values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_uint8 (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: INT8_T values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_int8 (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: UINT16_T values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_uint16 (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: INT16_T values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_int16 (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: UINT32_T values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_uint32 (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: UINT64_T values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_uint64 (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: INT64_T values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_int64 (dll_t * dll);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the entire linked list currently in use by displaying each node's current
 *          position within the list container as well as its data: BOOL values
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @return - None. If the list container parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_list_bool (dll_t * dll);

/**
 * @brief 
 * 
 */
void print_list_custom_default (dll_t * dll);

#endif //DOUBLY_LINKED_LIST_PRINT_LIST_H