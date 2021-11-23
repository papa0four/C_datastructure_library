#ifndef __LLIST_H__
#define __LLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>
#include <stdbool.h>

#define CLEAN(a) if (a) free(a);(a)=NULL;

typedef struct ll_node
{
    uint32_t id;
    uint32_t data;
    struct ll_node * next;
} ll_node_t;

typedef struct llist
{
    ll_node_t * head;
    size_t size;
} llist_t;

/**
 * @brief - initializes an empty, singly linked list structure
 * @param - None
 * @return - (struct llist_t *) a pointer to the heap allocated linked list structure
 */
llist_t * init ();

/**
 * @brief - appends a newly allocated node to the current linked list
 * @param p_list - (struct llist_t *): a pointer to the current linked list structure
 * @param p_id - (void *): a pointer to the node identifier NOTE: can be index or any other
 *               identifier for the node. It is current assumed that this value is intended
 *               to be a (uint32_t), however, this can be changed to suit the user's needs.
 * @param p_data - (void *): a pointer to the data that the linked list node will
 *                 store
 * @return - (bool): true if the node was successfully appended to the current linked
 *           list or false upon error
 */
bool append(llist_t * p_list, void * p_id, void * p_data);

/**
 * @brief - gets the current size of the linked list
 * @param p_list - (struct llist_t *): a pointer to the current linked list
 * @return - (size_t): the current number of nodes contained within the linked
 *           list
 */
size_t get_list_size (llist_t * p_list);

/**
 * @brief - deletes all relevant nodes based upon the node identifier NOTE:
 *          this function is meant to iterate over the entire list, removing
 *          all found nodes that share the identifier passed as the second
 *          parameter. This function DOES NOT delete the entire list of nodes
 * @param p_list - (struct llist_t *): a pointer to the current linked list structure
 * @param p_data_to_rm - (void *): a pointer to the identifier contained within the node
 *                       in which the function searches for to determine if the node
 *                       will be removed and then restructures the list. NOTE: for this
 *                       implementation, it is assumed that the identifying data type is
 *                       a (uint32_t), however, this can be change to suit the user's needs.
 * @return - (int): if any errors occur, this function will return a -1.
 *                  if there are no nodes within the list that contain the identifying
 *                  data, the function will return a 1.
 *                  on success, the function will return a 0.
 */
int delete_nodes (llist_t * p_list, void * p_data_to_rm);

/**
 * @brief - this function iterates over the entire list, searching for nodes that
 *          contain the specific identifier passed as the second parameter
 * @param p_list - (struct llist_t *): a pointer to the current linked list structure
 * @param p_find - (void *): a pointer to the identifying information contained within
 *                 any number of nodes of the list. NOTE: for this implementation, it is assumed
 *                 that the identifying data type is a (uint32_t), however, this can
 *                 be change to suit the user's needs
 */
void * get_relevant_nodes (llist_t * p_list, void * p_find);

/**
 * @brief - prints the newly created linked list that only contains the relevant nodes
 *          EXAMPLE:
 *          [ JOB: id ]: [ data ] --> [ data ] --> [ data ] --> [ data ] --|
 *          NOTE: the generic print_list function could be used, where the parameter is the
 *          "relevant" list, however, the format present within the definition is slightly
 *          different allowing for a cleaner format
 * @param p_list - (void *): a pointer to the generic "array" or list intended to be printed.
 *                 NOTE: this fucntion currently assumes that the data structure is a linked list
 *                 from this library, thus, casts p_list to a (struct llist_t *). This can be
 *                 changed by the user if the intent is to print a different data struct. However,
 *                 it should be noted that this is meant for this library and its structure(s)
 * @param p_id - (void *): the id to display at the beginning of the printed display. NOTE: it is
 *               assumed that this data is the identifying data within this library's linked list
 *               node structure, therefore it is casted to a (uint32_t). However, this may be changed
 *               by the user at a later time if deemed necessary.
 * @return - None
 */
void print_relevant_array (void * p_list, void * p_id);

/**
 * @brief - iterates over the entire list and deletes each node before destorying the linked list
 *          container, free'ing all memory allocated
 * @param p_list - (struct llist_t *): a pointer to the current linked list intended on being
 *                 destroyed
 * @return - (bool): false upon any errors or true if all nodes and the container are successfully
 *           destroyed and free'd.
 */
bool destroy (llist_t * p_list);

/**
 * @brief - a generic list print function that iterates over the entire linked list structure
 *          printing each node's relevant data. EXAMPLE:
 *          [ HEAD ] --> [ (id, data) ] -> [ (id, data) ] -> [ (id, data) ] --|
 *          NOTE: the "--|" denotes the end or tail of the list and no nodes follow. Additionally,
 *          the "[ HEAD ] -->" output shows what node the linked list's head pointer points to.
 * @param p_list - (llist_t *): a pointer to the current linked list structure to print its contents
 * @return None
 */
void print_list (llist_t * p_list);

#endif
