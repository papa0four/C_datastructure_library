//
// Created by jsabs on 11/17/21.
//

#ifndef CIRCULARLY_LINKED_LIST_CIRCULARLY_LINKED_LIST_H
#define CIRCULARLY_LINKED_LIST_CIRCULARLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>
#include <stdarg.h>
#include "macros.h"

void param_check (const char * fname, int line_no, int n_args, ...);

// declaration of the linked list node struct container
typedef struct cll_node node_t;
// declaration of the linked list struct container
typedef struct cl_list cll_t;
// declaration of the linked list node compare function pointer
typedef int (*cmp_f) (const void * a, const void * b);
// declaration of the linkled list node memory compare function pointer
typedef int (*memcmp_f) (const void * a, const void * b);
// declaration of the linked list node delete function pointer
typedef void (*del_f) (void * node_t);
// declaration of the linked list print list function pointer
typedef void (*print_f) (cll_t * cll);
// declaration of the linked list print node function pointer
typedef void (*print_n) (void * data);

typedef struct cll_node
{
    size_t            index;    // the current index of the node within the list
    void            * data;     // a pointer to the node's data
    print_n           pnode_func; // the linked list print formatted node function pointer
    struct cll_node * next;     // a pointer to the next node in the list
} node_t;

typedef struct cl_list
{
    node_t * head;      // 0th index suggesting first node within the list
    node_t * tail;      // nth index suggesting last node within the list
    size_t   size;      // the total number of nodes contained within the list
    memcmp_f memcmp_func; // the linked lists's node memory comparison function pointer
    cmp_f    compare_func; // the linked list compare node's data function pointer
    del_f    delete_func; // the linked list delete node function pointer
    print_f  print_func; // the linked list print formatted list function pointer
} cll_t;

/**
 * @brief - initializes an empty singly linked list structure. Set the HEAD and TAIL to NULL
 *          and sets the initial size to 0. NOTE: This does not allocate any nodes or node data.
 * @param memcmp_t - (memcmp_f) the specified node memory comparison function pointer
 * @param cmp_func_t - (cmp_f) the specified node data compare function pointer
 * @param del_func_t - (del_f) function pointer to all the list to appropriately free and NULL'ify
 *                     the specified node
 * @param print_func_t - (print_f) a function pointer to allow the list to perform a formatted
 *                       print on the entirety of the current list
 * @return - (struct cl_list *) ON SUCCESS: a pointer to the heap allocated singly linked list structure.
 *           There are two instances where the init function may fail. If any one of the function
 *           pointer parameters passed are invalid or NULL, errno will be set to EINVAL and init will
 *           return a NULL pointer. The second cause for failure is if the call to calloc (allocates
 *           memory on the heap for the container) fails, in which, errno will be set to ENOMEM and
 *           init will return a NULL pointer. In both instances, an appropriate error message will be
 *           displayed via STDERR. NOTE: it is up to the user to appropriately handle a NULL return
 *           as the data structure will be unusable potentially causing SEGMENTATION FAULTS, crashing
 *           the user's program.
 */
 cll_t * init(uint16_t node_type);


 /**
  * @brief - appends a newly allocated node to an existing linked list. If there are currently no
  *          nodes within the list, append() will add the new node to the list, setting the list
  *          HEAD and TAIL and updating the index member. If the list is populated, append() will
  *          add the node to the end of the list and update the index appropriately.
  * @param cll - (cll_t *) a pointer to the current linked list storage container
  * @param node_data - (void *) a generic pointer meant to contain the data to be stored within the
  *                    linked list node
  * @param pnode_func_t - (print_n) a function pointer to allow the list to perform a formatted
  *                       print on a specific node
  * @return - (int) ON SUCCESS: 0 will be returned, signifying that the new node has been added to the list.
  *           There are two instances of failure that may occur when calling append. If the linked list container
  *           parameter or the node data parameter are NULL when passed to append, errno will be set to
  *           EINVAL and append will return -1. Internally, append calls a static helper function to
  *           appropriately allocate heap memory and pack the linked list node. If the call to this
  *           internal helper function fails, the node_t pointer will be NULL and append will return a
  *           value of 1, however, errno will not be set. In both instances, an appropriate error message
  *           will be displayed to the user via STDERR. NOTE: in the second instance, it is up to the user
  *           check the return value of append before moving on to prevent crashing their program.
  */
int append(cll_t * cll, void * node_data, uint16_t node_type);

/**
 * @brief - inserts a newly allocated node to an existing or empty linked list. If there are currently no
 *          nodes within the list, insert_new_head will appropriately create a new node and insert it into
 *          the first position within the list. If the linked list is currently populated, insert_new_head
 *          will add the new node to the list, setting the list head appropriately and update each following
 *          node's index.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @param data - (const void *) a generic pointer to the data meant to be stored within the node to be inserted
 *               at the head of the list.
 * @param pnode_func_t - (print_n) a function pointer to allow the list to perform a formatted
 *                       print on a specific node
 * @return - None. There are three instances in which insert_new_head may fail. The initial failure may arise when
 *           one or both of the parameters passed are NULL, in which, errno will be set to EINVAL and no node
 *           will be inserted at the head of the list. The second potential failure may occur when trying to insert
 *           a new head to an empty list as insert_new_head relies on an internal call to the append function. In
 *           this instance, the return value for append is checked and depending on the error message displayed to
 *           the user via STDERR will determine whether or no errno was set, and by which error. The last instance
 *           that may arise would occur during an attempt to insert a new head to a currently populated list. This
 *           functionality relies on a call to the internal helper function create_node, which could potentially
 *           return a NULL pointer, however, this is handled within insert_new_head and the appropriate error message
 *           will be displayed via STDERR and errno will be set based upon the error that occurred.
 */
void insert_new_head (cll_t * cll, const void * data, uint16_t node_type);

/**
 * @brief - this function is meant to iterate over an existing list, and determine the appropriate insertion
 *          location for the node before inserting it into that location and updating the index of every affected
 *          node appropriately. If the current list is empty, insert_at_index will insert an new head for the list,
 *          however, that implies that the index parameter passed was equal to 0. If the index passed is 0 or equivalent
 *          to the current size of the list - 1 (tail index) a new node will be appropriately placed and the node's
 *          indices will be updated accordingly. If the index specified, falls between 0 and list size - 1,
 *          insert_at_index will locate the appropriate position, create a newly heap allocated node, and insert it
 *          at its respective location, updating all affected indices after the insertion.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @param data - (void *) a generic pointer to the data to be stored within the node
 * @param index - (size_t) the location within the list to insert the new node (0 - (n - 1)) where n is current list size
 * @return - None. There are five instances in which insert_at_index may fail. The first is if the linked list container
 *           and or the data pointer parameters passed are NULL, in which, insert_at_index will set errno to EINVAL, send
 *           the appropriate error message to STDERR, and return without inserting the node. The second instance is if the
 *           user attempts to insert a node at an index value greater than the current list size - 1, in which, insert_at_index
 *           will set errno to EINVAL, an appropriate error message will be displayed via STDERR, and the function will
 *           return without inserting the new node. The third instance is if the user tries to insert a new node into
 *           an empty list where the desired index is greater than 0, in which, errno will be set to EINVAL, the
 *           appropriate message will be displayed via STDERR, and the function will return. The fourth and fifth instances
 *           will be a result of a failed call to either insert_new_head or the internal helper function, create_node,
 *           in which, the appropriate errno value will be set, as well as the appropriate error message will be displayed
 *           where the desired node will not be added to the linked list. ON SUCCESS: the node will be inserted into the list
 *           at the desired location. NOTE: the user may check for success by calling the print_func member within the list
 *           container, to display all nodes currently within list.
 */
void insert_at_index (cll_t * cll, void * data, size_t index, uint16_t node_type);

/**
 * @brief - the intent of this function is for the user to provide a specific node that currently exists within the list
 *          and insert a new linked list node before it. This allows a user who does not currently know a node's specific
 *          index value insert new node into the linked list container by providing the data value for an already existing
 *          node, in order for the function place a new node before it. Additionally, the user may call insert_before to
 *          add a new head node to the list as it calls the insert_new_head function if the start_node parameter provided
 *          is equivalent to the current head of the list.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @param start_node - (node_t *) a pointer to the node desired to insert the new node before
 * @param data - (void *) a generic pointer to the data to be stored within the new node
 * @param pnode_func_t - (print_n) a function pointer to allow the list to perform a formatted
 *                       print on a specific node
 * @return - ON SUCCESS: the new node will be inserted into the linked list structure before the desired node, updating
 *           the index of all subsequently effected nodes. NOTE: the user will be able to verify the insertion occurred by
 *           printing the list to see its placement, or print the new node inserted to see its information. There are four
 *           instanced in which insert_before may fail. The first instance is if any combination of the three parameters
 *           passed are NULL, in which, errno will be set to EINVAL, an appropriate error message will be displayed to the
 *           user via STDERR, and the new node will not be inserted into the linked list container. The second instance in
 *           which insert_before may fail is to its internal call to insert_new_head, in which errno will be set appropriately,
 *           the corresponding error message will be displayed to the user via STDERR, and the node will not be inserted into
 *           the linked list container. The third instance in which insert_before may fail would be if the desired start node
 *           data passed could not be found. In this instance errno will not be set, however, the appropriate error message
 *           will be displayed to the user via STDERR and the requested node will not be inserted into the linked list
 *           container. The last instance in which insert_before may fail stems from its internal call to create_node. In
 *           this instance, errno will be set to the corresponding error, an appropriate error message will be displayed to
 *           the user and the desired node will not be inserted into the linked list container.
 */
void insert_before (cll_t * cll, node_t * start_node, void * data, uint16_t node_type);

/**
 * @brief - the purpose of this function is to insert a new linked list node into the container after a specified,
 *          existing node. This allows a user who does not currently know a node's specific list index value to insert
 *          a desired node after the specified one. If the location desired is after the existing tail node, the user
 *          may call insert_after rather than append, as insert_after calls the append function internally to create a
 *          new list tail node.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @param start_node - (node_t *) a pointer to the node desired to insert the new node before
 * @param data - (void *) a generic pointer to the data to be stored within the new node
 * @param pnode_func_t - (print_n) a function pointer to allow the list to perform a formatted
 *                       print on a specific node
 * @return - ON SUCCESS: the new node will be inserted into the linked list structure after the desired node, updating
 *           the index of all subsequently effected nodes. NOTE: the user will be able to verify the insertion occurred by
 *           printing the list to see its placement, or print the new node inserted to see its information. There are four
 *           instances in which insert_after may fail. The first instance would be if any combination of the parameters
 *           passed are NULL, in which, errno will be set to EINVAL, an appropriate error message will be displayed to the
 *           user, and the desired node will not be inserted into the linked list container. The second instance in which
 *           insert_after may fail would be to either internal call to create_node while trying to insert the new node.
 *           In this instance, errno will be set to the corresponding error, the appropriate error message will be displayed
 *           to the user via STDERR, create_node itself will return a NULL pointer, and no node will be inserted into the
 *           linked list storage container. The third instance in which insert_after would fail would be its internal call
 *           to the append function when trying to add a new tail to the linked list structure. Again, the corresponding
 *           errno value will be set along with the appropriate error message being displayed to the user and no node will
 *           be inserted into the linked list container. The last instance in which insert_after may fail is its internal
 *           call to find_node when searching for the specific node to insert after. In this instance, find_node will return
 *           a NULL pointer, errno will be set appropriately with its corresponding error message being displayed to the
 *           user, and no node will be inserted into the linked list.
 */
void insert_after (cll_t * cll, node_t * start_node, void * data, uint16_t node_type);

/**
 * @brief - this function allows the user to search for a specific node based upon its location within the linked list
 *          storage container. Because each node stores its index value as a member of the node struct, the user has
 *          the ability to view and retrieve a specific data value by index. find_by_index simply iterates over the
 *          current linked list until the passed index location is found and returns the specific node at that location.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @param index - (size_t) the requested index within the linked list, at which the desired node resides
 * @return - ON SUCCESS: (node_t *) a pointer to the node found at the specified index. There are three instances
 *           where find_by_index may fail. The first instance is when the linked list storage container parameter
 *           passed is NULL, in which, errno is set to EINVAL, an appropriate error message will be displayed via
 *           STDERR, and a NULL pointer will be returned to the function call. The second instance is when the
 *           current linked list container passed is emtpy, in which, an error message will be displayed to the
 *           user via STDERR and a NULL pointer will be returned to the function call, however, errno will not be set.
 *           The last instance in which find_by_index may fail is if the index parameter passed is greater than the
 *           current node count - 1 (size - 1) as this will cause an out of bounds error and cause the program to crash.
 *           Because of this potential issue, find_by_index will catch this situation setting errno to EINVAL, print
 *           the appropriate error message to the user via STDERR, and return a NULL pointer. NOTE: it is up to the user
 *           to catch the return value of find_by_index and check for NULL before proceeding with their use case.
 */
node_t * find_by_index (cll_t * cll, size_t index);

/**
 * @brief - this function is intended to find a node within a linked list by its value or node data. find_node uses the
 *          linked list value compare function pointer to compare the value stored within the node to the value passed
 *          as a function parameter. Because the node data is passed as a void * selecting the appropriate predefined
 *          compare function for the data is necessary when initializing the linked list storage container and passing
 *          it as the 1st parameter function pointer.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @param data - (void *) a generic point to the data to be compared and found stored within a linked list node
 * @return - ON SUCCESS: (node_t *) a pointer to the linked list node that contains the data requested by the user. If
 *           the requested data does not match that of any node currently stored within the linked list container,
 *           find_node will return a NULL pointer and errno will not be set. NOTE: it is up to the user to check the
 *           return value of find_node to determine whether or not the data requested was found. Additionally, there
 *           is one instance in which find_node may fail. If either the linked list pointer parameter or the requested
 *           data pointer parameter passed is NULL, find_node will return a NULL pointer, errno will be set to EINVAL,
 *           and an appropriate error message will displayed to the user via STDERR.
 */
node_t * find_node (cll_t * cll, const void * data);

/**
 * @brief - the intent of this function is to return the current size of the linked list structure based upon its
 *          current number of nodes.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @return - ON SUCCESS: an unsigned integral type (integer value, but not of type int) of the current number of nodes
 *           stored within the linked list container. NOTE: if empty, get_list_size will return a 0. ON FAILURE:
 *           get_list_size will also return a value of 0, however, errno will be set to EINVAL (given that the error
 *           that occurred was due to a NULL pointer to the linked list container being passed) and an appropriate
 *           error message will be displayed to the user via STDERR.
 */
size_t get_list_size (cll_t * cll);

/**
 * @brief - the intent of this function is to remove the head of the list based upon user specified data. This
 *          function will determine if the data presented matches the data stored within the list's head node
 *          and remove it, free'ing it from memory before restoring the integrity of the list appropriately.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @param data - (void *) a generic pointer to the data to be compared and found stored within a linked list node
 * @return - ON SUCCESS: the node containing the desired data to be removed will not longer be stored within
 *           the container, free'ing the heap allocated space in memory and setting it to NULL. Additionally,
 *           the list links will be rearranged to point to the appropriate next node. If the desired node to
 *           remove from the linked list container does not current exist, an error message will be displayed
 *           to the user via STDERR and no node will be removed from the list. If any combination of the parameters
 *           passed to remove_node are NULL, errno will be set to EINVAL, an appropriate error message will be
 *           displayed to the user via STDERR, and no node will be removed from the linked list container.
 */
void remove_head (cll_t * cll);

/**
 * @brief - the intent of this function is to remove the tail of the list based upon user specified data. This
 *          function will determine if the data presented matches the data stored within the list's head node
 *          and remove it, free'ing it from memory before restoring the integrity of the list appropriately.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @return - ON SUCCESS: the node containing the desired data to be removed will not longer be stored within
 *           the container, free'ing the heap allocated space in memory and setting it to NULL. Additionally,
 *           the list links will be rearranged to point to the appropriate next node. If the desired node to
 *           remove from the linked list container does not current exist, an error message will be displayed
 *           to the user via STDERR and no node will be removed from the list. If any combination of the parameters
 *           passed to remove_node are NULL, errno will be set to EINVAL, an appropriate error message will be
 *           displayed to the user via STDERR, and no node will be removed from the linked list container.
 */
void remove_tail (cll_t * cll);

/**
 * @brief - the intent of this function is to remove a single node from the list based upon user specified data. This
 *          function iterates over the current list looking for the node that contains the matching data to that
 *          passed by the user before removing the node, free'ing it from memory and reconnecting the list links
 *          appropriately.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @return - ON SUCCESS: the node containing the desired data to be removed will not longer be stored within
 *           the container, free'ing the heap allocated space in memory and setting it to NULL. Additionally,
 *           the list links will be rearranged to point to the appropriate next node. If the desired node to
 *           remove from the linked list container does not current exist, an error message will be displayed
 *           to the user via STDERR and no node will be removed from the list. If any combination of the parameters
 *           passed to remove_node are NULL, errno will be set to EINVAL, an appropriate error message will be
 *           displayed to the user via STDERR, and no node will be removed from the linked list container.
 */
void remove_node (cll_t * cll, const void * data);

/**
 * @brief - the intent of this function is to appropriately remove all nodes stored within the linked list container,
 *          free'ing and NULLifying all the corresponding heap allocated memory before doing the same to the storeage
 *          container itself disallowing and further use on its contents. NOTE: if the user does not wish to lose all
 *          of their current linked list container data and or pointers, it is advised to use the remove_node function
 *          or call the linked list delete_func function pointer to remove the desired node(s) rather than destroy_list
 *          as to not lose access to their current linked list data structure.
 * @param cll - (cll_t *) a pointer to the current linked list storage container
 * @return - ON SUCCESS: the entirety of the linked list structure will be erased from heap memory, preventing any
 *           unnecessary memory leaks before exiting the program or after the user is completely finished utilizing
 *           the data structure. Whether or not the current list is populated, the overarching container and all of its
 *           nodes will be removed from memory and no longer able to use. ON FAILURE: if the linked list container pointer
 *           parameter is NULL, errno will be set to EINVAL, an appropriate error message will be displayed to the user
 *           via STDERR, and the current linked list container will not be destroyed.
 */
 void destroy_list (cll_t * cll);

#endif //CIRCULARLY_LINKED_LIST_CIRCULARLY_LINKED_LIST_H
