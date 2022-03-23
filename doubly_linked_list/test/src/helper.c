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

void test_verbose_init (char * fname, dll_t * dll)
{
    param_check(__FILE__, __LINE__, ARG_2, fname, dll);

    fprintf(stdout, "TEST 1: %s - ", fname);
    fprintf(stdout, "Testing Initialization of Empty List\n");
    dll->print_func(dll);
    fprintf(stdout, "\n");
}

dll_t * init_int_dll(void)
{
    dll_t * dll = init(INT_T);
    if (NULL == dll)
    {
        fprintf(stderr, "%s(): could not initialize empty structure\n", __func__);
        return NULL;
    }

    return dll;
}

void test_verbose_append (char * fname, dll_t * dll)
{
    param_check(__FILE__, __LINE__, ARG_2, fname, dll);

    if (NULL == dll->head)
    {
        fprintf(stdout, "TEST 2: %s - ", fname);
        fprintf(stdout, "Testing Appending Nodes To List\n\n");
        fprintf(stdout, "BEFORE:\n");
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stdout, "AFTER:\n");
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
}

void test_verbose_new_head (char * fname, dll_t * dll, int * data)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, dll, data);

    if (5 == dll->size)
    {
        fprintf(stdout, "TEST 3: %s - ", fname);
        fprintf(stdout, "Testing Insert New Head To List\n\n");
        fprintf(stdout, "Inserting %d into Index 0:\n", *data);
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
    else if (6 == dll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_at_idx (char * fname, dll_t * dll, int * data, size_t index)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, dll, data);

    if (5 == dll->size)
    {
        fprintf(stdout, "TEST 4: %s - ", fname);
        fprintf(stdout, "Testing Insert At Specified Index\n\n");
        fprintf(stdout, "Inserting %d into Index %ld:\n", *data, index);
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
    else if (6 == dll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_before (char * fname, dll_t * dll, int * data, node_t * node)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, dll, data, node);

    if (5 == dll->size)
    {
        fprintf(stdout, "TEST 5: %s - ", fname);
        fprintf(stdout, "Testing Insert Before Specified Node\n\n");
        fprintf(stdout, "Inserting %d before node %d:\n", *data, *(int *)node->data);
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
    else if (6 == dll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}

void test_verbose_before_at_head (char * fname, dll_t * dll, int * data, node_t * node)
{
    param_check(__FILE__, __LINE__, ARG_3, fname, dll, data, node);

    if (5 == dll->size)
    {
        fprintf(stdout, "TEST 6: %s - ", fname);
        fprintf(stdout, "Testing Insert Before Head Node\n\n");
        fprintf(stdout, "Inserting %d before node %d:\n", *data, *(int *)node->data);
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
    else if (6 == dll->size)
    {
        fprintf(stdout, "After Insertion:\n");
        dll->print_func(dll);
        fprintf(stdout, "\n");
    }
    else
    {
        fprintf(stderr, "Testing Error Occurred, exiting...\n");
        exit(1);
    }
}