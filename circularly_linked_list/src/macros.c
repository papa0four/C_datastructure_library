#include <stdlib.h>
#include "../include/macros.h"

void param_check (const char * fname, int line_no, int n_args, ...)
{
    va_list var_list;
    va_start(var_list, n_args);
   
    for (int i = 0; i < n_args; i++)
    {
        char * param = va_arg(var_list, char *);
        CHECK((i + 1), fname, line_no, param);
    }

    va_end(var_list);
}

/*** end macros.c ***/

