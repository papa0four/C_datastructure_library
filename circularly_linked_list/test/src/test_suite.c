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

    cll_t * cll = init(INT_T);
    if (NULL == cll
    || NULL == cll->memcmp_func
    || NULL == cll->compare_func
    || NULL == cll->delete_func
    || NULL == cll->print_func)
    {
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
        pass_fail->num_failed++;
    }
    else
    {
        test_verbose_init(test_name, cll);
        pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
        pass_fail->num_passed++;
    }

    destroy_list(cll);
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

    cll_t * cll = init_int_cll();
    if (NULL == cll)
    {
        fprintf(stderr, "internal error, exiting...\n");
        exit(1);
    }

    test_verbose_append(test_name, cll);
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        usleep(SLEEP);
        int * number = gen_random();
        if (-1 == append(cll, number, INT_T))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
            pass_fail->num_failed++;
            destroy_list(cll);
            return;
        }

        if (0 == check_previous_tail(cll, cll->tail))
        {
            pass_fail->pf_flags[pass_fail->tests_ran - 1] = 0;
            pass_fail->num_failed++;
            destroy_list(cll);
            return;
        }
    }

    test_verbose_append(test_name, cll);
    pass_fail->pf_flags[pass_fail->tests_ran - 1] = 1;
    pass_fail->num_passed++;

    destroy_list(cll);
}

/*** end test_suite.c ***/

