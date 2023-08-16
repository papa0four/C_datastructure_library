#ifndef __LL_TEST_SUITE_H__
#define __LL_TEST_SUITE_H__

#include "llist.h"

typedef struct pass_fail
{
    int pass;
    int fail;
} pass_fail;

/**
 * @brief - destroys the pass_fail struct to clean memory
 * @param p_test - (struct pass_fail *): a pointer to the pass/fail struct
 * @return - None
 */
void destroy_test (pass_fail * p_test);

/**
 * @brief - initializes the pass/fail struct
 * @param - None
 * @return - (struct pass_fail *) a pointer to the heap allocated pass/fail structure
 */
pass_fail * init_pf ();

/**
 * @brief - allocates the pass/fail structure checks whether or not the passed linked list
 *          has been allocated to the heap and destroys the list container, free'ing its
 *          allocated memory. If both functionalities operate as intended, the console will
 *          print that the test passed, else it will dictate which portion failed.
 * @param p_list - (llist_t *): a pointer to the empty linked list structure
 * @return - None
 */
void test_init_and_cleanup(llist_t * p_list);

/**
 * @brief - attempts to add a single node to the linked list structure passed to it.
 *          If the append function works appropriately, a single node will be added to the list
 *          denoted the new head of the list. This function will print the list before
 *          destroying it and free'ing all allocated memory. If all functionality works
 *          as intended, the terminal will display that the tests have passed, otherwise
 *          the test will display as failed annotating which portion did not work as intended
 * @param p_list - (llist_t *): a pointer to the empty linked list structure
 * @return - None
 */
void test_add_one (llist_t * p_list);

/**
 * @brief - this function attempts to add 10 nodes with varying identifiers to the linked list structure
 *          passed. If at any point a node is not appropriate appended to the list, the
 *          test will print which iteration failed and the overall test is a fail. However,
 *          if the list is successfully populated, the new list will be printed to the user
 *          and the test will pass before attempting to destroy the list, free'ing all
 *          allocated memory
 * @param p_list - (llist_t *): a pointer to the empty linked list structure
 * @return - None
 */
void test_make_big_list (llist_t * p_list);

/**
 * @brief - this function is a duplicate of test_make_big_list(), however, it appends 100 nodes
 *          with three different identifiers. This is to display that the append function does not
 *          care about the value of the node data itself and only adds to the current data structure.
 * @param p_list - (llist_t *): a pointer to the empter linked list structure
 * @return - None
 */
void test_make_bigger_list (llist_t * p_list);

/**
 * @brief - This function is meant to test the parsing of a larger list returning a new list
 *          containig only the nodes relevant based upon a specific identifying data value.
 *          If the new list is appropriately created and populated, the new list will be printed to
 *          the terminal. If any portion of this test fails, the portion that failed will be annotated
 *          within the terminal output and the test will fail.
 * @param p_list - (llist_t *): a pointer to the empty linked list structure to be populated and parsed
 * @return - None
 */
void test_get_relevant (llist_t * p_list);

/**
 * @brief - This function is nearly identical to the test_get_relevant() function. However,
 *          this function appends 100 nodes with varying identifying data to ensure that
 *          only the relevant nodes are added to the new list from a larger data set. The functionality
 *          remains the same as test_get_relevant().
 * @param p_list - (llist_t *): a pointer to the empty linked list structure to be populated and parsed
 * @return - None
 */
void test_more_get_relevant (llist_t * p_list);

/**
 * @brief - This function tests the ability to delete any/all relevant nodes from the linked list.
 *          If the delete_nodes() function works as intended, then the test will print that the test passed
 *          to the terminal output. Otherwise, the output printed will annotate which portion failed and the
 *          test, itself, will fail
 * @param p_list - (llist_t *): a pointer to the empty linked list structure to be populated and parsed
 * @return - None
 */
void test_delete_nodes (llist_t * p_list);

/**
 * @brief - this function is an exact duplicate of test_delete_nodes(). The only difference
 *          is that it searches for a different identifying value
 * @param p_list - (llist_t *): a poitner to the empty linked list structure to e populated and parsed
 * @return - None
 */
void test_delete_nodes_again (llist_t * p_list);

#endif