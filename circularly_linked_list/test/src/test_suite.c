#include <stddef.h>
#define _GNU_SOURCE

#include "../include/test_suite.h"
#include "../include/helper.h"

void print_suite (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    fprintf(stdout, "\n############################### ");
    fprintf(stdout, "TEST SUITE");
    fprintf(stdout, " ###############################\n\n");
    print_pass_fail(pass_fail);
    fprintf(stdout, "\nTests Ran - %ld\t\tTotal Passed: %ld/%ld\t\tTotal Failed: %ld/%ld\n",
                    pass_fail->total, pass_fail->num_passed, pass_fail->total,
                    pass_fail->num_failed, pass_fail->total);
}

void print_pass_fail(pf_t * pass_fail)
{
    for (size_t i = 0; i < pass_fail->tests_ran; i++)
    {
        if (0 == pass_fail->pf_flags[i])
        {
            fprintf(stdout, "\tTEST %ld: %s - \033[0;31mFAIL \033[0m \n",
                            (i + 1), pass_fail->tests[i]);
        }
        else if (1 == pass_fail->pf_flags[i])
        {
            fprintf(stdout, "\tTEST %ld: %s - \033[0;32mPASS \033[0m \n",
                            (i + 1), pass_fail->tests[i]);
        }
        else
        {
            fprintf(stderr, " Test Suite Error Occurred, exiting...\n");
            exit(1);
        }
    }
}

void test_init (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    char * test_name    = "test_init\0";
    size_t fname_sz     = get_namelen(test_name);
    pass_fail->tests_ran++;

    pass_fail->tests[pass_fail->tests_ran - 1] = calloc(fname_sz + 1, sizeof(char));
    if (NULL == pass_fail->tests[pass_fail->tests_ran - 1])
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not initialize test array index: %s\n",
                        __func__, strerror(errno));
        return;
    }
    memcpy(pass_fail->tests[pass_fail->tests_ran - 1], test_name, fname_sz);

    cll_t * cll = init(INT_T);
    if (NULL == cll
    || NULL == cll->memcmp_func
    || NULL == cll->compare_func
    || NULL == cll->delete_func
    || NULL == cll->print_func)
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
    }
    else
    {
        test_verbose_init(test_name, cll);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }

    destroy_list(cll);
    return;
}

void test_append (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    char * test_name    = "test_append\0";
    size_t fname_sz     = get_namelen(test_name);
    pass_fail->tests_ran++;

    pass_fail->tests[pass_fail->tests_ran - 1] = calloc(fname_sz + 1, sizeof(char));
    if (NULL == pass_fail->tests[pass_fail->tests_ran - 1])
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not initialize test array index: %s\n",
                        __func__, strerror(errno));
        return;
    }
    memcpy(pass_fail->tests[pass_fail->tests_ran - 1], test_name, fname_sz);

    cll_t * cll = init_int_cll();
    if (NULL == cll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    test_verbose_append(test_name, cll);
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(cll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
            pass_fail->num_failed++;
            destroy_list(cll);
            return;
        }
        
        node_t * tail = find_by_index(cll, (cll->size - 1));
        if ((NULL == tail)
            || (*number != *(int *)cll->tail->data)
            || (-1 == cll->compare_func(cll->head->data, cll->tail->next->data)))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
            pass_fail->num_failed++;
            destroy_list(cll);
            return;
        }
    }

    test_verbose_append(test_name, cll);
    pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
    pass_fail->num_passed++;

    destroy_list(cll);
}

void test_add_head (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    char * test_name    = "test_insert_new_head\0";
    size_t fname_sz     = get_namelen(test_name);
    pass_fail->tests_ran++;

    pass_fail->tests[pass_fail->tests_ran - 1] = calloc(fname_sz + 1, sizeof(char));
    if (NULL == pass_fail->tests[pass_fail->tests_ran - 1])
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not initialize test array index: %s\n",
                        __func__, strerror(errno));
        return;
    }
    memcpy(pass_fail->tests[pass_fail->tests_ran - 1], test_name, fname_sz);

    cll_t * cll = init_int_cll();
    if (NULL == cll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(cll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(cll);
            return;
        }
    }
    
    int     * new_head = gen_random();
    node_t  * old_head = cll->head;
    test_verbose_new_head(test_name, cll, new_head);
    insert_new_head(cll, new_head, INT_T);

    if ((*new_head != *(int *)cll->head->data)
        && (6 != cll->size)
        && (-1 == cll->compare_func(cll->head->next->data, old_head->data)))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(cll);
    }
    else if ((*new_head == *(int *)cll->head->data)
            && (6 == cll->size)
            && (0 == cll->compare_func(cll->head->next->data, old_head->data)))
    {
        test_verbose_new_head(test_name, cll, new_head);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else 
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;  
    }

    destroy_list(cll);
}

void test_insert_at_idx (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    char * test_name    = "test_insert_at_index\0";
    size_t fname_sz     = get_namelen(test_name);
    pass_fail->tests_ran++;

    pass_fail->tests[pass_fail->tests_ran - 1] = calloc(fname_sz + 1, sizeof(char));
    if (NULL == pass_fail->tests[pass_fail->tests_ran - 1])
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not initialize test array index: %s\n",
                        __func__, strerror(errno));
        return;
    }
    memcpy(pass_fail->tests[pass_fail->tests_ran - 1], test_name, fname_sz);

    cll_t * cll = init_int_cll();
    if (NULL == cll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(cll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(cll);
            return;
        }
    }
    
    int     * new = gen_random();
    size_t    index = gen_index();

    test_verbose_at_idx(test_name, cll, new, index);
    insert_at_index(cll, new, index, INT_T);

    node_t * find = find_by_index(cll, index);

    if ((NULL == find)
        || (6 != cll->size)
        || (*new != *(int *)find->data))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(cll);
    }
    else if ((*new == *(int *)find->data)
            && (6 == cll->size)
            && (index == find->index))
    {
        test_verbose_at_idx(test_name, cll, new, index);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }

    destroy_list(cll);
}

void test_insert_before (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    char * test_name    = "test_insert_before\0";
    size_t fname_sz     = get_namelen(test_name);
    pass_fail->tests_ran++;

    pass_fail->tests[pass_fail->tests_ran - 1] = calloc(fname_sz + 1, sizeof(char));
    if (NULL == pass_fail->tests[pass_fail->tests_ran - 1])
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not initialize test array index: %s\n",
                        __func__, strerror(errno));
        return;
    }
    memcpy(pass_fail->tests[pass_fail->tests_ran - 1], test_name, fname_sz);

    cll_t * cll = init_int_cll();
    if (NULL == cll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(cll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(cll);
            return;
        }
    }

    int     * new         = gen_random();
    size_t    index       = gen_index();
    node_t  * find_before = find_by_index(cll, index);
    if (NULL == find_before)
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
        destroy_list(cll);
        return;
    }
    test_verbose_before(test_name, cll, new, find_before);
    insert_before(cll, find_before, new, INT_T);

    node_t * find = find_node(cll, new);
    if ((NULL == find)
        || (6 != cll->size)
        || (*new != *(int *)find->data))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(cll);
    }
    else if ((*new == *(int *)find->data)
            && (6 == cll->size)
            && (*(int *)find->next->data == *(int *)find_before->data))
    {
        test_verbose_before(test_name, cll, new, find);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;  
    }

    destroy_list(cll);
}


void test_insert_before_at_head (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);
  
    char * test_name    = "test_insert_before_at_head\0";
    size_t fname_sz     = get_namelen(test_name);
    pass_fail->tests_ran++;

    pass_fail->tests[pass_fail->tests_ran - 1] = calloc(fname_sz + 1, sizeof(char));
    if (NULL == pass_fail->tests[pass_fail->tests_ran - 1])
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not initialize test array index: %s\n",
                        __func__, strerror(errno));
        return;
    }
    memcpy(pass_fail->tests[pass_fail->tests_ran - 1], test_name, fname_sz);

    cll_t * cll = init_int_cll();
    if (NULL == cll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(cll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(cll);
            return;
        }
    }

    int     * new       = gen_random();
    node_t  * old_head  = cll->head;
    test_verbose_before_at_head(test_name, cll, new, cll->head);
    insert_before(cll, cll->head, new, INT_T);
    node_t  * new_head  = cll->head;
    if ((*new != *(int *)cll->head->data)
        || (6 != cll->size)
        || (-1 == cll->compare_func(new_head->data, cll->tail->next->data)))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(cll);
    }
    else if ((*new == *(int *)cll->head->data)
            && (6 == cll->size)
            && (new_head->next == old_head)
            && (0 == cll->compare_func(new_head->data, cll->tail->next->data)))
    {
        test_verbose_before_at_head(test_name, cll, new, old_head);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }

    destroy_list(cll);
}

void test_insert_after (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    char * test_name    = "test_insert_after\0";
    size_t fname_sz     = get_namelen(test_name);
    pass_fail->tests_ran++;

    pass_fail->tests[pass_fail->tests_ran - 1] = calloc(fname_sz + 1, sizeof(char));
    if (NULL == pass_fail->tests[pass_fail->tests_ran - 1])
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not initialize test array index: %s\n",
                        __func__, strerror(errno));
        return;
    }
    memcpy(pass_fail->tests[pass_fail->tests_ran - 1], test_name, fname_sz);

    cll_t * cll = init_int_cll();
    if (NULL == cll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(cll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(cll);
            return;
        }
    }

    int    * new          = gen_random();
    size_t   index        = gen_index();
    node_t * find_after   = find_by_index(cll, index);
    if (NULL == find_after)
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
        destroy_list(cll);
        return;
    }
    test_verbose_after(test_name, cll, new, find_after);
    insert_after(cll, find_after, new, INT_T);

    node_t * find = find_node(cll, new);
    if ((NULL == find)
        || (6 != cll->size)
        || (*new != *(int *)find->data)
        || (-1 == cll->compare_func(find_after->next->data, find->data)))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(cll);
    }
    else if ((*new == *(int *)find->data)
            && (6 == cll->size)
            && (0 == cll->compare_func(find_after->next->data, find->data)))
    {
        test_verbose_after(test_name, cll, new, find);
        pass_fail->pf_flags[pass_fail->tests_ran -1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }

    destroy_list(cll);
}

/*** end test_suite.c ***/

