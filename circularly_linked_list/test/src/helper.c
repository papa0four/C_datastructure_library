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


int check_previous_head (cll_t * cll, node_t * node)
{
    param_check(__FILE__, __LINE__, ARG_2, cll, node);

    if (node == cll->head)
    {
        return 1;
    }
    
    return 0;
}

int check_previous_tail (cll_t * cll, node_t * node)
{
    param_check(__FILE__, __LINE__, ARG_2, cll, node);

    size_t len = get_list_size(cll);
    if (1 == len)
    {
        int ret = check_previous_head(cll, node);
        if (1 == ret)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
   
    if (len > 1)
    {
        node_t * find = find_by_index(cll, (len - 2));
        if (NULL == find)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    return 0;
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

/*** end helper.c ***/

