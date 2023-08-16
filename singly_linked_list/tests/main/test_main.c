#include "ll_test_suite.h"

int main(void)
{
    /* TEST 1 */
    llist_t * linked_list = init();
    test_init_and_cleanup(linked_list);

    /* TEST 2 */
    linked_list = init();
    test_add_one(linked_list);

    /* TEST 3 */
    linked_list = init();
    test_make_big_list(linked_list);

    /*TEST 4 */
    linked_list = init();
    test_make_bigger_list(linked_list);

    /* TEST 5 */
    linked_list = init();
    test_get_relevant(linked_list);

    /* TEST 6 */
    linked_list = init();
    test_more_get_relevant(linked_list);

    /* TEST 7 */
    linked_list = init();
    test_delete_nodes(linked_list);
    destroy(linked_list);

    /* TEST 8 */
    linked_list = init();
    test_delete_nodes_again(linked_list);
    destroy(linked_list);

    return 0;
}