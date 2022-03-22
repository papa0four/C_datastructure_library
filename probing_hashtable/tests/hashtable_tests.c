#include "../include/hashtable.h"
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>

static void test_hashtable_new(void)
{
    // CU_CATCH_ASSERTIONS();
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    destroy_ht(table);
}

static void test_hashtable_delete(void)
{
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    char **strings = calloc(10, sizeof(char*));
    int **nums = calloc(10, sizeof(int *));
    for(int i = 0; i < 10; i++)
    {
        char* dest = calloc(10,  sizeof(char));
        int* c = calloc(10, sizeof(int));
        char str[10];
        *c = i;
        strncpy(dest, "testing", 8);
        sprintf(str, "%d", i);
        strcat(dest, str);
        insert_key(table, dest, c, 0);
        strings[i] = dest;
        nums[i] = c;
    
    }
    for(int i = 0; i < 10; i++)
    {
        void * get = NULL;
        get = get_value(table, strings[i]);
        CU_ASSERT_EQUAL_FATAL(*((int *) get), *nums[i]);
    }
    CU_ASSERT_PTR_NOT_NULL(table);
    for(int i = 0; i < 10; i++)
    {
        free(strings[i]);
        free(nums[i]);
    }
    free(strings);
    free(nums);
    destroy_ht(table);
}

static void test_hashtable_insert(void)
{
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    char **strings = calloc(10, sizeof(char*));
    int **nums = calloc(10, sizeof(int *));
    for(int i = 0; i < 10; i++)
    {
        char* dest = calloc(10,  sizeof(char));
        int* c = calloc(10, sizeof(int));
        char str[10];
        *c = i;
        strncpy(dest, "testing", 8);
        sprintf(str, "%d", i);
        strcat(dest, str);
        insert_key(table, dest, c, 0);
        strings[i] = dest;
        nums[i] = c;
    
    }
    for(int i = 0; i < 10; i++)
    {
        void * get = NULL;
        get = get_value(table, strings[i]);
        CU_ASSERT_EQUAL_FATAL(*((int *) get), *nums[i]);
    }
    CU_ASSERT_PTR_NOT_NULL(table);
    for(int i = 0; i < 10; i++)
    {
        free(strings[i]);
        free(nums[i]);
    }
    free(strings);
    free(nums);
    destroy_ht(table);
}

static void test_hashtable_insert_duplicate(void)
{
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    for(int i = 0; i < 10; i++)
    {
        insert_key(table, "testing", (void *) i, 0);
    }
    CU_ASSERT_PTR_NOT_NULL(table);
    CU_ASSERT_EQUAL(table->length, 1);
    destroy_ht(table);
}

static void test_hashtable_insert_overwrite(void)
{
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    for(int i = 0; i < 10; i++)
    {
        insert_key(table, "testing",(void *) i, 1);
    }
    CU_ASSERT_PTR_NOT_NULL(table);
    CU_ASSERT_EQUAL(table->length, 1);
    CU_ASSERT_EQUAL((int) get_value(table, "testing"), 9);
    destroy_ht(table);
}

static void test_hashtable_insert_to_null(void)
{
    CU_ASSERT_EQUAL(insert_key(NULL, "testing",(void *) 10, 1), -1);
}

static void test_hashtable_get_with_valid_value(void)
{
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    insert_key(table, "testing",(void *) 10, 0);
    CU_ASSERT_EQUAL(table->length, 1);
    void * get = NULL;
    get = get_value(table, "testing");
    CU_ASSERT_EQUAL((int) get, 10);
    destroy_ht(table);
}

static void test_hashtable_get_with_invalid_value(void)
{
    // CU_CATCH_ASSERTIONS();
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    insert_key(table, "testing",(void *) 10, 0);
    CU_ASSERT_EQUAL(table->length, 1);
    void * get = NULL;
    get = get_value(table, "sandwhich");
    CU_ASSERT_EQUAL(get, NULL);
    destroy_ht(table);
}

static void test_hashtable_get_null_table(void)
{
    void * get = NULL;
    get = get_value(NULL, "sandwhich");
    CU_ASSERT_EQUAL(get, NULL);
}


static void test_hashtable_del_null(void)
{
    CU_ASSERT_EQUAL(delete_key(NULL, "sandwhich"), -1);
}

static void test_hashtable_del_key_at_valid_index(void)
{
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    char* str = calloc(10,  sizeof(char));
    strncpy(str, "testing", 8);
    insert_key(table, str,(void *) 10, 0);
    CU_ASSERT_EQUAL(table->length, 1);
    CU_ASSERT_EQUAL(delete_key(table, "testing"), 1);
    CU_ASSERT_EQUAL(table->length, 0);
    free(str);
    destroy_ht(table);
}

static void test_hashtable_del_key__at_invalid_index(void)
{
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    char* str = calloc(10,  sizeof(char));
    strncpy(str, "testing", 8);
    insert_key(table, str,(void *) 10, 0);
    CU_ASSERT_EQUAL(table->length, 1);
    CU_ASSERT_EQUAL(delete_key(table, "sandwhich"), -1);
    CU_ASSERT_EQUAL(table->length, 1);
    free(str);
    destroy_ht(table);
}

static void test_hashtable_expand_size(void)
{
    int cap = DEFAULT_SIZE * 2;
    ht *table = NULL;
    table = create_ht();
    CU_ASSERT_PTR_NOT_NULL(table);
    char **strings = calloc(cap, sizeof(char*));
    int **nums = calloc(cap, sizeof(int *));
    for(int i = 0; i < cap; i++)
    {
        char* dest = calloc(8 + 4,  sizeof(char));
        int* c = calloc(10, sizeof(int));
        char str[10];
        *c = i;
        strncpy(dest, "testing", 8);
        sprintf(str, "%d", i);
        strcat(dest, str);
        insert_key(table, dest, c, 0);
        strings[i] = dest;
        nums[i] = c;
    }
    for(int i = 1; i < cap; i++)
    {
        void * get = NULL;
        get = get_value(table, strings[i]);
        CU_ASSERT_EQUAL_FATAL(*((int *) get), *nums[i]);
    }
    CU_ASSERT_PTR_NOT_NULL(table);
    CU_ASSERT_EQUAL(table->length, cap);
    for(int i = 0; i < cap; i++)
    {
        free(strings[i]);
        free(nums[i]);
    }
    free(strings);
    free(nums);
    destroy_ht(table);
}