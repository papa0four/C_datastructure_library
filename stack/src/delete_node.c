//
// Created by jsabs on 12/9/21.
//

#include "../include/delete_node.h"

void delete_node (void * node)
{
    if (NULL == node)
    {
        return;
    }

    free(node);
    node = NULL;
}
