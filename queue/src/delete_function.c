//
// Created by jsabs on 11/29/21.
//

#include "../include/delete_function.h"

void delete_node (void * data)
{
    if (NULL == data)
    {
        return;
    }

    free(data);
    data = NULL;
}

/*** end delete_function.c ***/