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

    dll_t * dll = init(INT_T);
    if (NULL == dll
    || NULL == dll->memcmp_func
    || NULL == dll->compare_func
    || NULL == dll->delete_func
    || NULL == dll->print_func)
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
    }
    else
    {
        test_verbose_init(test_name, dll);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }

    destroy_list(dll);
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

    dll_t * dll = init_int_dll();
    if (NULL == dll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    test_verbose_append(test_name, dll);
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(dll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
            pass_fail->num_failed++;
            destroy_list(dll);
            return;
        }

        if (0 == check_previous_tail(dll, dll->tail))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
            pass_fail->num_failed++;
            destroy_list(dll);
            return;
        }
    }

    test_verbose_append(test_name, dll);
    pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
    pass_fail->num_passed++;

    destroy_list(dll);
}

void test_add_head (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    char * test_name    = "test_add_head\0";
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

    dll_t * dll = init_int_dll();
    if (NULL == dll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(dll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(dll);
            return;
        }
    }

    int * new_head = gen_random();
    test_verbose_new_head(test_name, dll, new_head);
    insert_new_head(dll, new_head, INT_T);

    if ((*new_head != *(int *)dll->head->data)
        && (6 != dll->size)
        && (0 == check_previous_head(dll, dll->head)))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(dll);
    }
    else if ((*new_head == *(int *)dll->head->data)
            && (6 == dll->size)
            && (1 == check_previous_head(dll, dll->head)))
    {
        test_verbose_new_head(test_name, dll, new_head);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }
    
    destroy_list(dll);
}

void test_insert_at_idx (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    char * test_name    = "test_insert_at_idx\0";
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

    dll_t * dll = init_int_dll();
    if (NULL == dll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(dll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(dll);
            return;
        }
    }

    int     * new   = gen_random();
    size_t    index = gen_index();

    /* for previous check */
    node_t * get_prev = find_by_index(dll, (index - 1));
    if (NULL == get_prev)
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
        destroy_list(dll);
        return;
    }

    test_verbose_at_idx(test_name, dll, new, index);
    insert_at_index(dll, new, index, INT_T);

    node_t * find = find_by_index(dll, index);
    if ((NULL == find)
        || (6 != dll->size)
        || (*new != *(int *)find->data)
        || (0 == check_previous_in_list(get_prev, find)))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(dll);
    }
    else if ((*new == *(int *)find->data)
            && (6 == dll->size)
            && (index == find->index)
            && (1 == check_previous_in_list(get_prev, find)))
    {
        test_verbose_at_idx(test_name, dll, new, index);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }
    
    destroy_list(dll);
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

    dll_t * dll = init_int_dll();
    if (NULL == dll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(dll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(dll);
            return;
        }
    }

    int    * new            = gen_random();
    size_t   index          = gen_index();
    node_t * find_before    = find_by_index(dll, index);
    if (NULL == find_before)
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
        destroy_list(dll);
        return;
    }
    test_verbose_before(test_name, dll, new, find_before);
    insert_before(dll, find_before, new, INT_T);

    node_t * find = find_node(dll, new);
    if ((NULL == find)
        || (6 != dll->size)
        || (*new != *(int *)find->data))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(dll);
    }
    else if ((*new == *(int *)find->data)
            && (6 == dll->size)
            && (*(int *)find->next->data == *(int *)find_before->data))
    {
        test_verbose_before(test_name, dll, new, find);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }
    
    destroy_list(dll);
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

    dll_t * dll = init_int_dll();
    if (NULL == dll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(dll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(dll);
            return;
        }
    }

    int    * new        = gen_random();
    node_t * old_head   = dll->head;
    test_verbose_before_at_head(test_name, dll, new, dll->head);
    insert_before(dll, dll->head, new, INT_T);
    node_t * new_head   = dll->head;
    if ((*new != *(int *)dll->head->data)
        || (6 != dll->size)
        || (0 == check_previous_head(dll, dll->head)))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(dll);
    }
    else if ((*new == *(int *)dll->head->data)
            && (6 == dll->size)
            && (new_head->next == old_head)
            && (1 == check_previous_head(dll, dll->head)))
    {
        test_verbose_before(test_name, dll, new, old_head);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }
    
    destroy_list(dll);
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

    dll_t * dll = init_int_dll();
    if (NULL == dll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(dll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(dll);
            return;
        }
    }

    int    * new            = gen_random();
    size_t   index          = gen_index();
    node_t * find_after     = find_by_index(dll, index);
    if (NULL == find_after)
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
        destroy_list(dll);
        return;
    }
    test_verbose_after(test_name, dll, new, find_after);
    insert_after(dll, find_after, new, INT_T);

    node_t * find = find_node(dll, new);
    if ((NULL == find)
        || (6 != dll->size)
        || (*new != *(int *)find->data)
        || (0 == check_previous_in_list(find_after, find)))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(dll);
    }
    else if ((*new == *(int *)find->data)
            && (6 == dll->size)
            && (1 == check_previous_in_list(find_after, find)))
    {
        test_verbose_after(test_name, dll, new, find);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }
    
    destroy_list(dll);
}

void test_insert_after_at_tail (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    char * test_name    = "test_insert_after_at_tail\0";
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

    dll_t * dll = init_int_dll();
    if (NULL == dll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(dll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(dll);
            return;
        }
    }

    int * new = gen_random();
    test_verbose_after_at_tail(test_name, dll, new, dll->tail);
    insert_after(dll, dll->tail, new, INT_T);

    node_t * find = find_node(dll, new);
    if ((NULL == find)
        || (6 != dll->size)
        || (*new != *(int *)find->data)
        || (0 == check_previous_tail(dll, find)))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(dll);
    }
    else if ((*new == *(int *)find->data)
            && (6 == dll->size)
            && (1 == check_previous_tail(dll, find)))
    {
        test_verbose_after_at_tail(test_name, dll, new, find);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }
    
    destroy_list(dll);
}


void test_find_by_index (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);
    
    char * test_name    = "test_find_by_index\0";
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

    dll_t * dll = init_int_dll();
    if (NULL == dll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(dll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
            destroy_list(dll);
            return;
        }
    }

    size_t    index    = gen_index();
    node_t  * find     = find_by_index(dll, index);

    test_verbose_by_index(test_name, dll, NULL, index);
    node_t * check = find_node(dll, (int *)find->data);
    if ((NULL == find)
        || (NULL == check)
        || (5 != dll->size)
        || (0 == check_previous_in_list(check->prev,find)))
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
        destroy_list(dll);
    }
    else if ((NULL != find)
            && (1 == check_previous_in_list(check->prev, find)))
    {
        test_verbose_by_index(test_name, dll, find, index);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }   
    else
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = -1;
    }
    
    destroy_list(dll);
}
