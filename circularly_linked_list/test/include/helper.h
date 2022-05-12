#ifndef __HELPER_H__
#define __HELPER_H__

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>

#include "../../include/circularly_linked_list.h"
#include "../../include/print_list.h"
#include "../../include/print_node.h"
#include "../../include/compare_functions.h"
#include "../../include/delete_function.h"

size_t get_namelen (char * fname);

int * gen_random (void);

size_t gen_index (void);

int check_previous_head (cll_t * cll, node_t * node);

int check_previous_tail (cll_t * cll, node_t * node);

int check_previous_in_list (node_t * inserted, node_t * new);

void test_verbose_init (char * fname, cll_t * cll);

cll_t * init_int_cll(void);

void test_verbose_append (char * fname, cll_t * cll);

void test_verbose_new_head (char * fname, cll_t * cll, int * data);

void test_verbose_at_idx (char * fname, cll_t * cll, int * data, size_t index);

void test_verbose_before (char * fname, cll_t * cll, int * data, node_t * node);

void test_verbose_before_at_head (char * fname, cll_t * cll, int * data, node_t * node);

void test_verbose_after (char * fname, cll_t * cll, int * data, node_t * node);

void test_verbose_after_at_tail (char * fname, cll_t * cll, int * data, node_t * node);

void test_verbose_by_index(char * fname, cll_t * cll, node_t * found, size_t index);

#endif
