//
// Created by jsabs on 11/19/21.
//

#ifndef SINGLY_LINKED_LIST_COMPARE_FUNCTIONS_H
#define SINGLY_LINKED_LIST_COMPARE_FUNCTIONS_H

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

/**
 * @brief - compares signed 32-bit integer values
 * @param a - (const void *) a generic pointer value converted to an integer
 * @param b - (const void *) a generic pointer value converter to an integer
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_int_t (const void * a, const void * b);

/**
 * @brief - compares signed floating point integer values
 * @param a - (const void *) a generic pointer value converted to a float
 * @param b - (const void *) a generic pointer value converter to a float
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_flt_t (const void * a, const void * b);

/**
 * @brief - compares signed double values
 * @param a - (const void *) a generic pointer value converted to a double
 * @param b - (const void *) a generic pointer value converter to a double
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_dbl_t (const void * a, const void * b);

/**
 * @brief - compares string or character array values
 * @param a - (const void *) a generic pointer value converted to a
 *            character array
 * @param b - (const void *) a generic pointer value converter to a
 *            character array
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_str_t (const void * a, const void * b);

/**
 * @brief - compares unsigned 8-bit integer values
 * @param a - (const void *) a generic pointer value converted to an
 *            unsigned 8-bit integer
 * @param b - (const void *) a generic pointer value converter to an
 *            unsigned 8-bit integer
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_uint8_t (const void * a, const void * b);

/**
 * @brief - compares signed 8-bit integer values
 * @param a - (const void *) a generic pointer value converted to a
 *            signed 8-bit integer
 * @param b - (const void *) a generic pointer value converter to a
 *            signed 8-bit integer
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_int8_t (const void * a, const void * b);

/**
 * @brief - compares unsigned 16-bit integer values
 * @param a - (const void *) a generic pointer value converted to an
 *            unsigned 16-bit integer
 * @param b - (const void *) a generic pointer value converter to an
 *            unsigned 16-bit integer
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_uint16_t (const void * a, const void * b);

/**
 * @brief - compares signed 16-bit integer values
 * @param a - (const void *) a generic pointer value converted to a
 *            signed 16-bit integer
 * @param b - (const void *) a generic pointer value converter to a
 *            signed 16-bit integer
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_int16_t (const void * a, const void * b);

/**
 * @brief - compares unsigned 32-bit integer values
 * @param a - (const void *) a generic pointer value converted to an
 *            unsigned 32-bit integer
 * @param b - (const void *) a generic pointer value converter to an
 *            unsigned 32-bit integer
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_uint32_t (const void * a, const void * b);

/**
 * @brief - compares unsigned 64-bit integer values
 * @param a - (const void *) a generic pointer value converted to an
 *            unsigned 64-bit integer
 * @param b - (const void *) a generic pointer value converter to an
 *            unsigned 64-bit integer
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_uint64_t (const void * a, const void * b);

/**
 * @brief - compares signed 64-bit integer values
 * @param a - (const void *) a generic pointer value converted to a
 *            signed 64-bit integer
 * @param b - (const void *) a generic pointer value converter to a
 *            signed 64-bit integer
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_int64_t (const void * a, const void * b);

/**
 * @brief - compares bool values
 * @param a - (const void *) a generic pointer value converted to a
 *            boolean value
 * @param b - (const void *) a generic pointer value converter to a
 *            boolean
 * @return - performs a boolean operation between value a and b, checking if
 *           a is greater than b and subtracting that from another check to see if
 *           b is greater than a. If the values are equal, this function returns
 *           a 0 value, otherwise -1 is returned indicating a and b are not the
 *           same.
 */
int cmp_bool_t (const void * a, const void * b);

#endif //SINGLY_LINKED_LIST_COMPARE_FUNCTIONS_H
