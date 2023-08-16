//
// Created by jsabs on 03/08/22
//

#include "../include/delete_function.h"

void delete_node (void * data)
{
    if (NULL == data)
    {
        return;
    }

    CLEAN(data);
}

/*** end delete_function.h ***/
