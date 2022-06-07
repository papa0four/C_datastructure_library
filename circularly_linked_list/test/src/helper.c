#include "../include/helper.h"

size_t get_namelen (char * fname)
{
    int idx = 0;

    while (fname[idx] != '\0')
    {
        idx++;
    }

    return idx;
}

int * gen_random (void)
{
    int min = 1;
    int max = 100; 
    int * result = calloc (1, sizeof(int));
    *result = (rand() % (max - min) + min);
    return result;
}

size_t gen_index ()
{
    int min     = 1;
    int max     = 4;
    int result  = -1;

    srand(time(NULL));
    result = (rand() % (max - min) + min);
    return result;
}

void test_verbose_init (char * fname, cll_t * cll)
{
    param_check(__FILE__, __LINE__, ARG_2, fname, cll);

    fprintf(stdout, "TEST 1: %s - ", fname);
    fprintf(stdout, "Testing Initialization of Empty List\n");
    cll->print_func(cll);
    fprintf(stdout, "\n");
}

cll_t * init_int_cll(void)
{
    cll_t * cll = init(INT_T);
    if (NULL == cll)
    {
        fprintf(stderr, "%s(): could not initialize empty structure\n", __func__);
        return NULL;
    }

    return cll;
}

void test_verbose_append (char * fname, cll_t * cll)
{
    param_check(__FILE__, __LINE__, ARG_2, fname, cll);

    if (NULL == cll->head)
    {
        fprintf(stdout, "TEST 2: %s - ", fname);
        fprintf(stdout, "Testing Appending Nodes To List\n\n");
        fprintf(stdout, "BEFORE:\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stdout, "AFTER:\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
}

void test_verbose_new_head (char * fname, cll_t * cll, int * data)
{
    param_check(__FILE__, __LINE__, ARG_2, fname, cll);

    if (5 == cll->size)
    {
        fprintf(stdout, "TEST 3: %s - ", fname);
        fprintf(stdout, "Testing Inserting New Head To List\n\n");
        fprintf(stdout, "Inserting %d into Index 0:\n", *data);
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else if (6 == cll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "size: %ld\n", cll->size);
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_at_idx (char * fname, cll_t * cll, int * data, size_t index)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, cll, data);

    if (5 == cll->size)
    {
        fprintf(stdout, "TEST 4: %s - ", fname);
        fprintf(stdout, "Testing Insert At Specified Index\n\n");
        fprintf(stdout, "Inserting %d into Index %ld:\n", *data, index);
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else if (6 == cll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_before (char * fname, cll_t * cll, int * data, node_t * node)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, cll, data, node);

    if (5 == cll->size)
    {
        fprintf(stdout, "TEST 5: %s - ", fname);
        fprintf(stdout, "Testing Insert Before Specified Node\n\n");
        fprintf(stdout, "Inserting %d before node %d:\n", *data, *(int *)node->data);
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else if (6 == cll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Ocurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_before_at_head (char * fname, cll_t * cll, int * data, node_t * node)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, cll, data, node);

    if (5 == cll->size)
    {
        fprintf(stdout, "TEST 6: %s - ", fname);
        fprintf(stdout, "Testing Insert Before, Head Node\n\n");
        fprintf(stdout, "Inserting %d before node %d:\n", *data, *(int *)node->data);
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else if (6 == cll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_after (char * fname, cll_t * cll, int * data, node_t * node)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, cll, data, node);

    if (5 == cll->size)
    {
        fprintf(stdout, "TEST 7: %s - ", fname);
        fprintf(stdout, "Testing Insert After Specified Node\n\n");
        fprintf(stdout, "Inserting %d after node %d:\n", *data, *(int *)node->data);
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else if (6 == cll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_after_at_tail (char * fname, cll_t * cll, int * data, node_t * node)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, cll, data, node);

    if (5 == cll->size)
    {
        fprintf(stdout, "TEST 8: %s - ", fname);
        fprintf(stdout, "Testing Insert After Tail\n\n");
        fprintf(stdout, "Inserting %d after tail node %d:\n", *data, *(int *)node->data);
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else if (6 == cll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_by_index (char * fname, cll_t * cll, node_t * found, size_t index)
{
    param_check(__FILE__, __LINE__, ARG_2, fname, cll);

    if ((5 == cll->size)
        && (NULL == found))
    {
        fprintf(stdout, "TEST 9 : %s - ", fname);
        fprintf(stdout, "Testing Find Node by Index\n\n");
        fprintf(stdout, "Searching for node at index %ld:\n", index);
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else if ((5 == cll->size)
            && (NULL != found))
    {
        node_t * prev = find_by_index(cll, found->index - 1);
        if (NULL == prev)
        {
            fprintf(stderr, "Internal Structure Error, exiting...\n");
            exit(1);
        }

        fprintf(stdout, "Node found!\n\n");
        found->pnode_func(found);
        fprintf(stdout, "\n");
        fprintf(stdout, "Node found validation:\n\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
        prev->pnode_func(prev);
        prev->pnode_func(prev->next);
        found->pnode_func(found->next);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_by_data (char * fname, cll_t * cll, node_t * found, void * data)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, cll, data);

    if ((5 == cll->size)
        && (NULL == found))
    {
        fprintf(stdout, "TEST 10 : %s - ", fname);
        fprintf(stdout, "Testing Find Node by Data\n\n");
        fprintf(stdout, "Searching for node %d:\n", *(int *)data);
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else if ((5 == cll->size)
            && (NULL != found))
    {
        node_t * prev = find_by_index(cll, found->index - 1);
        if (NULL == prev)
        {
            fprintf(stderr, "Internal Structure Error, exiting...\n");
            exit(1);
        }

        fprintf(stdout, "Node found!\n\n");
        found->pnode_func(found);
        fprintf(stdout, "\n");
        fprintf(stdout, "Node found validation:\n\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
        prev->pnode_func(prev);
        prev->pnode_func(prev->next);
        found->pnode_func(found->next);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_delete_node (char * fname, cll_t * cll, node_t * node, int * data)
{
    param_check(__FILE__, __LINE__, ARG_2, cll, data);

    if ((5 == cll->size)
        && (NULL != node))
    {
        fprintf(stdout, "TEST 11 : %s - ", fname);
        fprintf(stdout, "Testing Delete Node From List\n\n");
        fprintf(stdout, "Deleting node %d from list:\n", *(int *)data);
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else if ((4 == cll->size)
            && (NULL == node))
    {
        fprintf(stdout, "Node successfully removed from list\n\n");
        cll->print_func(cll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "\n\nsize: %ld\tnode: %p\n\n", cll->size, (void *)node);
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

/*** end helper.c ***/

