#ifndef __MOD_INDEX_H__
#define __MOD_INDEX_H__

#include "circularly_linked_list.h"

/**
 * @brief - the intent of this helper function is to decrement all node indices without user interaction
 *          when removing a node from the linked list container.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @param start_pos - (size_t) a numeric representation of the current node's index (n - 1) in the list
 * @return - None. NOTE: if the linked list pointer parameter is NULL or the start_pos parameter passed
 *           is greater than the current number of nodes stored within the linked list container, errno
 *           will be set EINVAL, the appropriate error message will be displayed to the user, and the indices
 *           will not be modified.
 */
void decrement_index (cll_t * cll, size_t start_pos);

/**
 * @brief - the intent of this helper function is to increment all node indices without user interaction
 *          when inserting a node into the linked list container while not calling the append function.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @param start_node - (node_t *) a pointer to the node, in which, itself and all subsequent nodes will have
 *                      their indices incremented
 * @return - None. NOTE: if any combination of the parameters passed are NULL, errno will be set EINVAL,
 *           the appropriate error message will be displayed to the user, and the indices will not be modified.
 */
void increment_index (cll_t * cll, node_t * start_node);

#endif
