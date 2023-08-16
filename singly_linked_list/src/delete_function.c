//
// Created by jsabs on 11/22/21.
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
