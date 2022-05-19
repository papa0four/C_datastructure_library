#include "../include/mod_index.h"

void decrement_index (cll_t * cll, size_t start_pos)
{
    if (start_pos > (cll->size - 1))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: start_pos parameter cannot exceed the current number of list nodes: %s\n",
                        __func__, strerror(errno));
        return;
    }

    node_t * current = cll->head;
    while (current->next != cll->head)
    {
        if (current->index >= start_pos)
        {
            current->index--;
        }

        current = current->next;
    }
}

void increment_index (cll_t * cll, node_t * start_node)
{
    if (NULL == start_node)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: start_node parameter passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    node_t * node = find_node(cll, start_node->data);
    if (NULL == node)
    {
        fprintf(stderr, "%s: could not find specified node\n",
                        __func__);
        return;
    }

    while (node)
    {
        node->index++;
        if (cll->head == node->next)
        {
            break;
        }
        node = node->next;
    }
}

/*** end mod_index.c ***/

