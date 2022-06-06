
#include "../include/test_suite.h"
#include "../include/helper.h"
#include "../include/test_main.h"

pf_t * init_suite ()
{
    pf_t * pass_fail = calloc(1, sizeof(pf_t));
    if (NULL == pass_fail)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not allocate test suite struct: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    pass_fail->tests = calloc(NUM_TESTS, sizeof(char *));
    if (NULL == pass_fail->tests)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not allocate test suite name array: %s\n",
                        __func__, strerror(errno));
        CLEAN(pass_fail);
        return NULL;
    }

    pass_fail->pf_flags = calloc(NUM_TESTS, sizeof(ssize_t));
    if (NULL == pass_fail->pf_flags)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s(): could not allocate test suite p/f flags array: %s\n",
                        __func__, strerror(errno));
        CLEAN(pass_fail->tests);
        CLEAN(pass_fail);
        return NULL;
    }

    pass_fail->total        = NUM_TESTS;
    pass_fail->tests_ran    = 0;
    pass_fail->num_failed   = 0;
    pass_fail->num_passed   = 0;

    return pass_fail;
}

void delete_test_suite (pf_t * pass_fail)
{
    param_check(__FILE__, __LINE__, ARG_1, pass_fail);

    for (size_t i = 0; i < pass_fail->tests_ran; i++)
    {
        CLEAN(pass_fail->tests[i]);
    }

    CLEAN(pass_fail->tests);
    CLEAN(pass_fail->pf_flags);
    pass_fail->num_failed = 0;
    pass_fail->num_passed = 0;
    pass_fail->total      = 0;
    pass_fail->tests_ran  = 0;
    CLEAN(pass_fail);
}

int main (void)
{
    pf_t * pass_fail = init_suite();
    if (NULL == pass_fail)
    {
        fprintf(stderr, "%s(): could not initialize test suite\n", __func__);
        return EXIT_FAILURE;
    }

    /* run test suite */
    test_init(pass_fail);
    test_append(pass_fail);
    test_add_head(pass_fail);
    test_insert_at_idx(pass_fail);
    test_insert_before(pass_fail);
    test_insert_before_at_head(pass_fail);
    test_insert_after(pass_fail);
    test_insert_after_at_tail(pass_fail);

    /* print test suite results */
    print_suite(pass_fail);

    /* completely delete and free test suite */
    delete_test_suite(pass_fail);

    return EXIT_SUCCESS;
}
