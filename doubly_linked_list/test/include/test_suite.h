#ifndef __TEST_SUITE_H__
#define __TEST_SUITE_H__

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

#define SLEEP   1000000

typedef struct pass_fail
{
    size_t     num_passed;
    size_t     num_failed;
    size_t     tests_ran;
    size_t     total;
    ssize_t  * pf_flags;
    char    ** tests;

} pf_t;

void print_suite (pf_t * pass_fail);

void print_pass_fail(pf_t * pass_fail);

void test_init (pf_t * pass_fail);

void test_append (pf_t * pass_fail);

void test_add_head (pf_t * pass_fail);

void test_insert_at_idx (pf_t * pass_fail);

void test_insert_before (pf_t * pass_fail);

void test_insert_before_at_head (pf_t * pass_fail);

void test_insert_after (pf_t * pass_fail);

void test_insert_after_at_tail (pf_t * pass_fail);

void test_find_by_index (pf_t * pass_fail);

#endif
