#ifndef __HELPER_H__
#define __HELPER_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>

#include "../../include/doubly_linked_list.h"
#include "../../include/print_list.h"
#include "../../include/print_node.h"
#include "../../include/compare_functions.h"
#include "../../include/delete_function.h"

size_t get_namelen (char * fname);

int * gen_random (void);

void test_verbose_init (char * fname, dll_t * dll);

dll_t * init_int_dll(void);

void test_verbose_append (char * fname, dll_t * dll);

void test_verbose_new_head (char * fname, dll_t * dll, int * data);

void test_verbose_at_idx (char * fname, dll_t * dll, int * data, size_t index);

void test_verbose_before (char * fname, dll_t * dll, int * data, node_t * node);

void test_verbose_before_at_head (char * fname, dll_t * dll, int * data, node_t * node);

#endif