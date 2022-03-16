#ifndef __DOUBLY_LINKED_LIST_MACROS_H__
#define __DOUBLY_LINKED_LIST_MACROS_H__

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#define ARG_1   1
#define ARG_2   2
#define ARG_3   3
#define ARG_4   4
#define ARG_5   5

#define INT_T       0x00
#define FLT_T       0x01
#define DBL_T       0x02
#define STR_T       0x03
#define UINT8_T     0x04
#define INT8_T      0x05
#define UINT16_T    0x06
#define INT16_T     0x07
#define UINT32_T    0x08
#define UINT64_T    0x09
#define INT64_T     0x0a
#define BOOL_T      0x0b

/* reserved for custom node data types i.e. structs */
#define CUSTOM_T    0x0c

/* used if the user creates their own node print function */
#define USR_DEFINE_T 0x0d

/* ERROR Log output used for parameter checking in functions */
#define ERR_LOG(idx,file,line,err) fprintf(stderr, "\nERROR:\nparameter %d passed is NULL: %s\n" \
                            "Source: %s - line %d\nProgram exiting...\n", \
                            idx, strerror(err), file, line)

/* checks parameter for NULL, sets errno, calls log and exits program */
#define CHECK(idx,file,line,param) do { \
    if (NULL == param) { \
        errno = EINVAL; \
        ERR_LOG(idx, file, line, errno); \
        exit(1); \
        } \
    } while (0)

/**
 * @brief - (void) gathers information about the calling function
 *          and its arguments before passing data to error macros
 *          to determine validity.
 * @param fname - (const char *) __FILE__ preprocessor directive for the source
 *                file where the function resides
 * @param line_no - (int) line number within the calling function where the error
 *                  check function is called
 * @param n_args - (int) number of arguments passed to the calling function
 * @param ... - (variadic) names of the arguments passed to the parent function
 * @return - exit(1) exiting the program after printing error log 
 */
void param_check (const char * fname, int line_no, int n_args, ...);

/* FREE/NULL Macro for ease of use */
#define CLEAN(a) do { \
    if (a) { \
        free(a); \
        (a)=NULL; \
        } \
    } while (0)

#endif