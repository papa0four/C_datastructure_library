#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include "hashtable_tests.c"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    CU_pSuite pSuite = CU_add_suite("graph_tests", NULL, NULL);

    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // 3. _add tests to the suite
    if ((NULL == CU_add_test(pSuite, "Hashtable delete", test_hashtable_delete)) ||
        (NULL == CU_add_test(pSuite, "Hashtable insert", test_hashtable_insert)) ||
        (NULL == CU_add_test(pSuite, "Hashtable duplicate", test_hashtable_insert_duplicate)) ||
        (NULL == CU_add_test(pSuite, "Hashtable overwrite", test_hashtable_insert_overwrite)) ||
        (NULL == CU_add_test(pSuite, "Hashtable insert to Null", test_hashtable_insert_to_null)) ||
        (NULL == CU_add_test(pSuite, "Hashtable get valid value", test_hashtable_get_with_valid_value)) ||
        (NULL == CU_add_test(pSuite, "Hashtable get invalid value", test_hashtable_get_with_invalid_value)) ||
        (NULL == CU_add_test(pSuite, "Hashtable get with Null", test_hashtable_get_null_table)) ||
        (NULL == CU_add_test(pSuite, "Hashtable delete NULL ", test_hashtable_del_null)) ||
        (NULL == CU_add_test(pSuite, "Hashtable delete value from table at valid index", test_hashtable_del_key_at_valid_index)) ||
        (NULL == CU_add_test(pSuite, "Hashtable delete value at invalid index", test_hashtable_del_key__at_invalid_index)) ||
        (NULL == CU_add_test(pSuite, "Hashtable expand table", test_hashtable_expand_size)) ||
        (NULL == CU_add_test(pSuite, "Hashtable new", test_hashtable_new)))
    {
        CU_cleanup_registry();
        CU_get_error();
        return -1;
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);

    if (argc >= 1)
    {
        CU_set_output_filename(argv[0]);
    }

    CU_automated_enable_junit_xml(CU_TRUE);
    CU_automated_run_tests();
    CU_list_tests_to_file();

    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
