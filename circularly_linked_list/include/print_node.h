//
// Created by jsabs on 11/29/21.
//

#ifndef CIRCULARLY_LINKED_LIST_PRINT_NODE_H
#define CIRCULARLY_LINKED_LIST_PRINT_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include "../include/circularly_linked_list.h"

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (INT value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_int (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (FLOAT value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_float (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (DOUBLE value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_double (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (STRING value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_string (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (UINT8_T value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_uint8 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (INT8_T value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_int8 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (UINT16_T value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_uint16 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (INT16_T value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_int16 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (UINT32_T value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_uint32 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (UINT64_T value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_uint64 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (INT64_T value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_int64 (void * data);

/**
 * @brief - the intent of this function is to give the user the ability to print
 *          the specified linked list node by displaying its memory address. current
 *          position within the list container (index), its data (BOOL value), as well
 *          as the memory address of the next node (NULL if no next exists).
 * @param data - (void *) a pointer to the current linked list container
 * @return - None. If the data parameter passed is NULL, an error message
 *           will be sent to STDERR and errno will be set to EINVAL.
 */
void print_bool (void * data);

/**
 * @brief 
 * 
 */
void print_custom_default (void * data);

#endif //CIRCULARLY_LINKED_LIST_PRINT_NODE_H
