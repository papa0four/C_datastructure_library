#ifndef __DETECTION_H__
#define __DETECTION_H__

#include "circularly_linked_list.h"

/**
  * @brief - a helper function used to determine what data is meant to be
  *          stored within the linked list data structure
  * @param (cll_t *) cll - a pointer to the current circularly linked list
  *                         data structure
  * @param (uint16_t) flag - a macro defined 16 bit unsigned integer used within
  *                          a switch statement to determine which compare and
  *                          list print functions will be set within the linked
  *                          list structure
  *
  *                   TYPES:
  *                         INT_T         - used when the data is of type int
  *                         FLT_T         - used when the data is of type float
  *                         DBL_T         - used when the data is of type double
  *                         STR_T         - used when the data is of type char *
  *                         UINT8_T       - used when the data is of type uint8_t
  *                         INT8_T        - used when the data is of type int8_t
  *                         UINT16_T      - used when the data is of type uint16_t
  *                         INT16_T       - used when the data is of type int16_t
  *                         UINT32_T      - used when the data is of type uint16_t
  *                         UINT64_T      - used when the data is of type uint64_t
  *                         INT64_T       - used when the data is of type int64_t
  *                         BOOL_T        - used when the data is of type bool
  *                         CUSTOM_T      - used when the data is a struct defined by the user
  *                         USR_DEFINE_T  - used when the user wants to create custom list print
  * @return (cll_t *) - returns a pointer to the current circularly linked list
  *                     data structure containing a pointer to the appropriate compare
  *                     and/or print list functions. Upon ERROR, this function will
  *                     return a NULL pointer to the linked list data structure, causing
  *                     the program to fail.
  */
cll_t * det_func (cll_t * cll, uint16_t flag);

/**
  * @brief - a helper function used to determine what data will be stored within
  *          each node of the linked list data structure
  * @param (node_t *) node - a pointer to the current node to be stored within
  *                          the linked list data structure
  * @param (uint16_t) flag - a macro defined 16 bit usinged integer used within
  *                          a switch statement to determine which print node_t
  *                          function will be set within the node container
  *
  *                   TYPES:
  *                         INT_T         - used when the data is of type int
  *                         FLT_T         - used when the data is of type float
  *                         DBL_T         - used when the data is of type double
  *                         STR_T         - used when the data is of type char *
  *                         UINT8_T       - used when the data is of type uint8_t
  *                         INT8_T        - used when the data is of type int8_t
  *                         UINT16_T      - used when the data is of type uint16_t
  *                         INT16_T       - used when the data is of type int16_t
  *                         UINT32_T      - used when the data is of type uint16_t
  *                         UINT64_T      - used when the data is of type uint64_t
  *                         INT64_T       - used when the data is of type int64_t
  *                         BOOL_T        - used when the data is of type bool
  *                         CUSTOM_T      - used when the data is a struct defined by the user
  *                         USR_DEFINE_T  - used when the user wants to create custom list print
  * @return (node_t *) - returns a pointer to the current node to be stored within
  *                      the circularly linked list data structure with the appropriate 
  *                      node print function set within the node container. Upon ERROR,
  *                      this function will return a NULL pointer to the new node
  *                      created, causing the program to fail.
  */
  node_t * det_node_func (node_t * node, uint16_t flag);

#endif
