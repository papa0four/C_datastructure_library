#include "ll_test_suite.h"

/* see test suite header for function documentation */
void destroy_test (pass_fail * p_test)
{
    CLEAN(p_test);
}

/* see test suite header for function documentation */
pass_fail * init_pf ()
{
    pass_fail * p_test = calloc(1, sizeof(pass_fail));
    if (NULL == p_test)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate test suite: %s\n", __func__, strerror(errno));
        return NULL;
    }

    p_test->pass = 0;
    p_test->fail = 0;

    return p_test;
}

void test_init_and_cleanup(llist_t * p_list)
{
    pass_fail * p_test = init_pf();
    printf("TEST 1: initialize empty list:\n");

    if (NULL == p_list)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not initialize data structure\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - linked list initialized\n");
        p_test->pass++;
    }

    bool destroyed = destroy(p_list);
    if (false == destroyed)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not destroy data structure\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - linked list destroyed\n");
        p_test->pass++;
    }

    if (0 == p_test->fail)
    {
        printf("\t[\033[0;32m PASSED \033[0m] - TEST 1\n");
    }
    else
    {
        printf("\t[\033[0;31m FAILED \033[0m] - TEST 1\n");
    }

    destroy_test(p_test);
}

void test_add_one (llist_t * p_list)
{
    pass_fail * p_test = init_pf();
    printf("TEST 2: append one node:\n");

    uint32_t    id      = 876543;
    uint32_t    data    = 1337;
    bool        added   = append(p_list, (void *)&id, (void *)&data);
    if (false == added)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not list node\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", data);
        p_test->pass++;
    }

    size_t current_sz = get_list_size(p_list);
    if (1 != current_sz)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - mistmatch size: should be 1\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - only one node exists!\n");
        p_test->pass++;
    }

    print_list(p_list);

    bool destroyed = destroy(p_list);
    if (false == destroyed)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not destroy data structure\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - linked list destroyed\n");
        p_test->pass++;
    }

    if (0 == p_test->fail)
    {
        printf("\t[\033[0;32m PASSED \033[0m] - TEST 2\n");
    }
    else
    {
        printf("\t[\033[0;31m FAILED \033[0m] - TEST 2\n");
    }

    destroy_test(p_test);
}

void test_make_big_list (llist_t * p_list)
{
    pass_fail * p_test = init_pf();
    printf("TEST 3: append multiple nodes:\n");

    bool        added   = false;
    uint32_t    id      = 12345;
    uint32_t    id_2    = 54321;

    for (uint32_t iter = 1; iter <= 10; iter++)
    {
        if (0 == iter % 2)
        {
            added = append(p_list, (void *)&id, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else if (1 == iter % 2)
        {
            added = append(p_list, (void *)&id_2, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
    }

    size_t current_sz = get_list_size(p_list);
    if (10 != current_sz)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - mistmatch size: should be 10\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - all nodes added successfully!\n");
        p_test->pass++;
    }

    print_list(p_list);

    bool destroyed = destroy(p_list);
    if (false == destroyed)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not destroy data structure\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - linked list destroyed\n");
        p_test->pass++;
    }

    if (0 == p_test->fail)
    {
        printf("\t[\033[0;32m PASSED \033[0m] - TEST 3\n");
    }
    else
    {
        printf("\t[\033[0;31m FAILED \033[0m] - TEST 3\n");
    }

    destroy_test(p_test);
}

void test_make_bigger_list (llist_t * p_list)
{
    pass_fail * p_test = init_pf();
    printf("TEST 4: append too many nodes:\n");

    bool     added  = false;
    uint32_t id     = 12345;
    uint32_t id_2   = 54321;
    uint32_t id_3   = 98765;
    uint32_t id_4   = 45678;

    for (uint32_t iter = 1; iter <= 100; iter++)
    {
        if (0 == (iter % 2))
        {
            added = append(p_list, (void *)&id, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else if (0 == (iter % 3))
        {
            added = append(p_list, (void *)&id_2, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else if (0 == (iter % 5))
        {
            added = append(p_list, (void *)&id_3, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else
        {
            added = append(p_list, (void *)&id_4, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
    }

    size_t current_sz = get_list_size(p_list);
    if (100 != current_sz)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - mistmatch size: should be 100\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - all nodes added successfully!\n");
        p_test->pass++;
    }

    print_list(p_list);

    bool destroyed = destroy(p_list);
    if (false == destroyed)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not destroy data structure\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - linked list destroyed\n");
        p_test->pass++;
    }

    if (0 == p_test->fail)
    {
        printf("\t[\033[0;32m PASSED \033[0m] - TEST 4\n");
    }
    else
    {
        printf("\t[\033[0;31m FAILED \033[0m] - TEST 4\n");
    }

    destroy_test(p_test);
}

void test_get_relevant (llist_t * p_list)
{
    pass_fail * p_test = init_pf();
    printf("TEST 5: get relevant data:\n");

    bool     added  = false;
    uint32_t id     = 12345;
    uint32_t id_2   = 54321;

    for (uint32_t iter = 1; iter <= 10; iter++)
    {
        if (0 == (iter % 2))
        {
            added = append(p_list, (void *)&id, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else if (1 == (iter % 2))
        {
            added = append(p_list, (void *)&id_2, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
    }

    size_t current_sz = get_list_size(p_list);
    if (10 != current_sz)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - mistmatch size: should be 10\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - all nodes added successfully!\n");
        p_test->pass++;
    }

    void    * p_nodes   = get_relevant_nodes(p_list, (void *)&id);
    llist_t * p_linked  = (llist_t *) p_nodes;
    if ((NULL == p_linked) || (NULL == p_linked->head))
    {
        fprintf(stderr, "%s: could not retrieve data\n", __func__);
        CLEAN(p_linked);
    }
    else
    {
        print_relevant_array(p_linked, (void *)&id);
        destroy(p_linked);
    }

    print_list(p_list);

    bool destroyed = destroy(p_list);
    if (false == destroyed)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not destroy data structure\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - linked list destroyed\n");
        p_test->pass++;
    }

    if (0 == p_test->fail)
    {
        printf("\t[\033[0;32m PASSED \033[0m] - TEST 5\n");
    }
    else
    {
        printf("\t[\033[0;31m FAILED \033[0m] - TEST 5\n");
    }

    destroy_test(p_test);
}

void test_more_get_relevant (llist_t * p_list)
{
    pass_fail * p_test = init_pf();
    printf("TEST 6: get more relevant data:\n");

    bool     added  = false;
    uint32_t id     = 12345;
    uint32_t id_2   = 54321;
    uint32_t id_3   = 98765;
    uint32_t id_4   = 45678;

    for (uint32_t iter = 1; iter <= 100; iter++)
    {
        if (0 == (iter % 2))
        {
            added = append(p_list, (void *)&id, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else if (0 == (iter % 3))
        {
            added = append(p_list, (void *)&id_2, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else if (0 == (iter % 5))
        {
            added = append(p_list, (void *)&id_3, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else
        {
            added = append(p_list, (void *)&id_4, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
    }

    size_t current_sz = get_list_size(p_list);
    if (100 != current_sz)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - mistmatch size: should be 100\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - all nodes added successfully!\n");
        p_test->pass++;
    }

    void    * p_nodes   = get_relevant_nodes(p_list, (void *)&id_3);
    llist_t * p_linked  = (llist_t *) p_nodes;
    if ((NULL == p_linked) || (NULL == p_linked->head))
    {
        fprintf(stderr, "%s: could not retrieve data\n", __func__);
        CLEAN(p_linked);
    }
    else
    {
        print_relevant_array(p_linked, (void *) &id);
        destroy(p_linked);
    }

    print_list(p_list);

    bool destroyed = destroy(p_list);
    if (false == destroyed)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not destroy data structure\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - linked list destroyed\n");
        p_test->pass++;
    }

    if (0 == p_test->fail)
    {
        printf("\t[\033[0;32m PASSED \033[0m] - TEST 6\n");
    }
    else
    {
        printf("\t[\033[0;31m FAILED \033[0m] - TEST 6\n");
    }

    destroy_test(p_test);
}

void test_delete_nodes (llist_t * p_list)
{
    pass_fail * p_test = init_pf();
    printf("TEST 7: remove specified nodes:\n");

    bool     added  = false;
    uint32_t id     = 12345;
    uint32_t id_2   = 54321;

    for (uint32_t iter = 1; iter <= 10; iter++)
    {
        if (0 == (iter % 2))
        {
            added = append(p_list, (void *)&id, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else if (1 == (iter % 2))
        {
            added = append(p_list, (void *)&id_2, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
    }

    size_t old_sz = get_list_size(p_list);
    if (10 != old_sz)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - mistmatch size: should be 10\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - all nodes added successfully!\n");
        p_test->pass++;
    }

    printf("\tBEFORE REMOVAL:\n");
    print_list(p_list);

    int removed = delete_nodes(p_list, (void *)&id);
    if (-1 == removed)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not remove nodes\n");
        p_test->fail++;
    }
    else if (0 == removed)
    {
        p_test->pass++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - no nodes to remove\n");
        p_test->pass++;
    }

    printf("\tAFTER REMOVAL:\n");
    print_list(p_list);

    size_t new_sz = get_list_size(p_list);
    if ((5 != new_sz) || (new_sz == old_sz))
    {
        printf("\t[\033[0;31m FAIL \033[0m] - mistmatch size: should be 5\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - nodes successfully removed\n");
        p_test->pass++;
    }

    if (0 == p_test->fail)
    {
        printf("\t[\033[0;32m PASSED \033[0m] - TEST 7\n");
    }
    else
    {
        printf("\t[\033[0;31m FAILED \033[0m] - TEST 7\n");
    }

    destroy_test(p_test);
}

void test_delete_nodes_again (llist_t * p_list)
{
    pass_fail * p_test = init_pf();
    printf("TEST 8: remove specified nodes ... again:\n");

    bool     added  = false;
    uint32_t id     = 12345;
    uint32_t id_2   = 54321;

    for (uint32_t iter = 1; iter <= 10; iter++)
    {
        if (0 == (iter % 2))
        {
            added = append(p_list, (void *)&id, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
        else if (1 == (iter % 2))
        {
            added = append(p_list, (void *)&id_2, (void *)&iter);
            if (false == added)
            {
                printf("\t[\033[0;31m FAIL \033[0m] - could not append node %u\n", iter);
                p_test->fail++;
            }
            else
            {
                printf("\t[\033[0;32m OK \033[0m] - linked list node %u added\n", iter);
                p_test->pass++;
            }
        }
    }

    size_t old_sz = get_list_size(p_list);
    if (10 != old_sz)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - mistmatch size: should be 10\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - all nodes added successfully!\n");
        p_test->pass++;
    }

    printf("\tBEFORE REMOVAL:\n");
    print_list(p_list);

    int removed = delete_nodes(p_list, (void *)&id_2);
    if (-1 == removed)
    {
        printf("\t[\033[0;31m FAIL \033[0m] - could not remove nodes\n");
        p_test->fail++;
    }
    else if (0 == removed)
    {
        p_test->pass++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - no nodes to remove\n");
        p_test->pass++;
    }

    printf("\tAFTER REMOVAL:\n");
    print_list(p_list);

    size_t new_sz = get_list_size(p_list);
    if ((5 != new_sz) || (new_sz == old_sz))
    {
        printf("\t[\033[0;31m FAIL \033[0m] - mistmatch size: should be 5\n");
        p_test->fail++;
    }
    else
    {
        printf("\t[\033[0;32m OK \033[0m] - nodes successfully removed\n");
        p_test->pass++;
    }

    if (0 == p_test->fail)
    {
        printf("\t[\033[0;32m PASSED \033[0m] - TEST 8\n");
    }
    else
    {
        printf("\t[\033[0;31m FAILED \033[0m] - TEST 8\n");
    }

    destroy_test(p_test);
}

/*** end ll_test_suite.c ***/
