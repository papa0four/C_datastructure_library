//
// Created by jsabs on 11/17/21.
// updated by jsabs on 03/08/22.
//
#include <stddef.h>
#define _GNU_SOURCE

#include "../include/print_list.h"
#include "../include/print_node.h"
#include "../include/compare_functions.h"
#include "../include/delete_function.h"
#include "../include/mod_index.h"
#include "../include/detection.h"

cll_t * init (uint16_t node_type)
{
    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    cll_t * cll = calloc(1, sizeof(cll_t));
    if (NULL == cll)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate list container: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    cll = det_func(cll, node_type);
    if (NULL == cll)
    {
        fprintf(stderr, "%s(): error occurred setting up list: functions could not be determined\n",
                        __func__);
        return NULL;
    }
    

    cll->head = NULL;
    cll->tail = NULL;
    cll->size = 0;

    return cll;
}

/**
 * @brief - allocates a node_t structure pointer to the heap, creating the new node to
 *          insert into the singly linked list structure. NOTE: this is an internal
 *          helper function that the user should not have to interact with, unless needed
 *          for special cases.
 * @param data - (void *) a generic pointer to the data to be stored within the node
 * @param pnode_func_t - (print_n) a function pointer to allow the list to perform a formatted
 *                       print on a specific node
 * @return - (node_t *) ON SUCCESS: returns a heap allocated node structure to insert
 *           into the singly linked list. There are two instances where create_node may fail.
 *           If the data parameter pointer passed is NULL, errno will be set to EINVAL and
 *           create_node will return a NULL pointer. The other instance that may occur is when the
 *           call to calloc fails (system level failure) in which, errno will be set to ENOMEM
 *           and create_node will return a NULL pointer.
 */
static node_t * create_node (void * data, uint16_t node_type)
{
    node_t * node = calloc(1, sizeof(node_t));
    if (NULL == node)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate memory for new node: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    node = det_node_func(node, node_type);

    node->index         = 0;
    node->data          = data;
    node->next          = NULL;

    return node;
}

int append (cll_t * cll, void * node_data, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_2, cll, node_data);

    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return -1;
    }

    node_t * new = NULL;
    new = create_node(node_data, node_type);
    if (NULL == new)
    {
        fprintf(stderr, "%s: could not create new node\n", __func__);
        return -1;
    }
   
    if (NULL == cll->head)
    {
        cll->head = new;
        cll->tail = new;
        new->next = new;
        cll->size++;
    }
    else
    {
        new->index      = cll->size;
        cll->tail->next = new;
        cll->tail       = new;
        new->next       = cll->head;
        cll->size++;
    }

    return 0;
}

void insert_new_head (cll_t * cll, const void * data, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_2, cll, data);

    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == cll->head)
    {
        int ret_val = append(cll, (void *)data, node_type);
        if (-1 == ret_val)
        {
            return;
        }
    }
    else
    {
        node_t * old_head = cll->head;
        node_t * new_head = create_node((void *)data, node_type);
        if (NULL == new_head)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return;
        }
        new_head->next    = cll->head;
        cll->head         = new_head;
        cll->tail->next   = cll->head;
        cll->size++;
        increment_index(cll, old_head);
    }
}

void insert_at_index (cll_t * cll, void * data, size_t index, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_2, cll, data);

    if (index > cll->size - 1)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: index value passed cannot exceed list size: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if ((index > 0) && (NULL == cll->head))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: current list is empty, insert at index 0 is the only"
                                " permissible location: %s\n", __func__, strerror(errno));
        return;
    }

    if (0 == index)
    {
        insert_new_head(cll, (const void *)data, node_type);
        return;
    }

    node_t * current = cll->head;
    node_t * prev    = NULL;
    while (cll->head != current->next)
    {
        if (index == current->next->index)
        {
            prev    = current;
            current = current->next;

            node_t * new_node = create_node(data, node_type);
            if (NULL == new_node)
            {
                fprintf(stderr, "%s: could not create new node to insert\n",
                                __func__);
                return;
            }
            prev->next   = new_node;
            new_node->index = current->index;
            new_node->next  = current;
            cll->size++;
            increment_index(cll, current);
            break;
        }

        current = current->next;
    }

    if (NULL == current)
    {
        fprintf(stderr, "%s: error occurred inserting new node\n", __func__);
    }
}

void insert_before (cll_t * cll, node_t * start_node, void * data, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_3, cll, start_node, data);

    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (0 == cll->memcmp_func(cll->head, start_node))
    {
        insert_new_head(cll, data, node_type);
    }
    else
    {
        node_t * current = cll->head;
        node_t * next    = NULL;
        while (cll->head != current->next)
        {
            if (0 == cll->memcmp_func(current->next, start_node))
            {
                next = current->next;
                break;
            }

            current = current->next;
        }

        if (NULL == current)
        {
            fprintf(stderr, "%s: could not find node to insert before\n",
                            __func__);
            return;
        }

        node_t * new_node = create_node(data, node_type);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create node to be inserted\n",
                    __func__);
            return;
        }

        current->next   = new_node;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(cll, next);
        cll->size++;
    }
}

void insert_after (cll_t * cll, node_t * start_node, void * data, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_3, cll, start_node, data);

    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (0 == cll->compare_func(cll->head->data, start_node->data))
    {
        node_t * next = cll->head->next;
        node_t * new_node = create_node(data, node_type);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create new node to be inserted\n",
                            __func__);
            return;
        }
        cll->head->next = new_node;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(cll, next);
        cll->size++;
    }
    else if (0 == cll->compare_func(cll->tail->data, start_node->data))
    {
        int ret_val = append(cll, data, node_type);
        if ((-1 == ret_val) || (1 == ret_val))
        {
            fprintf(stderr, "%s: could not insert new node\n",
                            __func__);
            return;
        }
    }
    else
    {
        node_t * find = find_node(cll, start_node->data);
        if (NULL == find)
        {
            fprintf(stderr, "%s: could not find desired node to insert after\n",
                            __func__);
            return;
        }
        node_t * next = find->next;

        node_t * new_node = create_node(data, node_type);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create new node to be inserted\n",
                            __func__);
            return;
        }

        find->next = new_node;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(cll, next);
        cll->size++;
    }
}

node_t * find_by_index (cll_t * cll, size_t index)
{
    if (NULL == cll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    if (NULL == cll->head)
    {
        fprintf(stderr, "%s: current list container is empty\n",
                        __func__);
        return NULL;
    }

    if (index > cll->size - 1)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: index value passed cannot exceed list size: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    node_t * current = cll->head;
    while (cll->head != current->next)
    {
        if (index == current->index)
        {
            break;
        }

        current = current->next;
    }

    return current;
}

node_t * find_node (cll_t * cll, const void * data)
{
    param_check(__FILE__, __LINE__, ARG_2, cll, data);

    node_t * current = cll->head;

    while (cll->head != current->next)
    {
        if (0 == cll->compare_func(current->data, data))
        {
            break;
        }

        current = current->next;
    }

    if (NULL == current)
    {
        fprintf(stderr, "%s(): could not find specified node in list\n", __func__);
    }

    return current;
}

size_t get_list_size (cll_t * cll)
{
    if (NULL == cll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return 0;
    }
    return cll->size;
}

void remove_head (cll_t * cll)
{
    param_check(__FILE__, __LINE__, ARG_1, cll);

    node_t * prev     = cll->head;
    node_t * current  = cll->head;

    if (NULL == cll->head)
    {
        fprintf(stderr, "%s(): Current list is empty\n", __func__);
        return;
    }

    /* if only one node exists */
    if ((1 == cll->size)
        || (prev->next == prev))
    {
        cll->delete_func(cll->head->data);
        cll->delete_func(cll->head);
        cll->head = NULL;
        cll->tail = NULL;
        cll->size--;
    }
    else
    {
        while (cll->head != current->next)
        {
            current = current->next;
        }

        current->next = prev->next;
        cll->head     = current->next;
        cll->delete_func(prev->data);
        cll->delete_func(prev);
        decrement_index(cll, cll->head->index);
        cll->size--;
    }
}

void remove_tail (cll_t * cll)
{
    param_check(__FILE__, __LINE__, ARG_1, cll);
    
    node_t * current = cll->head;
    node_t * prev    = NULL;

    if ((1 == cll->size)
        || (NULL == cll->head))
    {
        fprintf(stderr, "%s(): Current list is empty\n", __func__);
        return;
    }

    /* if only one node exists */
    if (current->next == current)
    {
        remove_head(cll);
        return;
    }

    while (cll->head != current->next)
    {
        prev      = current;
        current   = current->next;
    }

    prev->next = current->next;
    cll->tail  = prev;
    cll->tail  = prev->next;
    cll->delete_func(current->data);
    cll->delete_func(current);
    cll->size--;    
}

void remove_node (cll_t * cll, const void * data)
{
    param_check(__FILE__, __LINE__, ARG_2, cll, data);
    
    if (NULL == cll->head)
    {
        fprintf(stderr, "%s(): Current list is empty\n", __func__);
        return;
    }

    /* check if node exists in list */
    node_t * find = find_node(cll, data);
    if (NULL == find)
    {
        fprintf(stderr, "%s(): Data passed does not exist in list\n",
                        __func__);
    }
    else if (0 == cll->compare_func(data, cll->head->data))
    {
        remove_head(cll);
    }
    else if (0 == cll->compare_func(data, cll->tail->data))
    {
        remove_tail(cll);
    }
    else
    {
        node_t * find = find_node(cll, data);
        if (NULL == find)
        {
            fprintf(stderr, "%s(): Data not found in current list\n", __func__);
            return;
        }

        node_t * prev = find_by_index(cll, find->index - 1);
        if (NULL == prev)
        {
            fprintf(stderr, "%s(): Could not find previous node\n", __func__);
            return;
        }

        node_t * next   = prev->next->next;
        size_t   index  = prev->index + 1;
        prev->next      = next;
        cll->delete_func(find->data);
        cll->delete_func(find);
        decrement_index(cll, index);
        cll->size--;
    }
}

void destroy_list (cll_t * cll)
{
    if (NULL == cll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == cll->head)
    {
        CLEAN(cll);
        return;
    }

    node_t * current    = cll->head;
    node_t * temp       = NULL;
    while (current)
    {
        if (cll->head == current->next)
        {
            cll->delete_func(current->data);
            cll->delete_func(current);
            break;
        }
        temp    = current;
        current = current->next;
        cll->delete_func(temp->data);
        cll->delete_func(temp);
    }
    
    cll->head           = NULL;
    cll->tail           = NULL;
    cll->memcmp_func    = NULL;
    cll->compare_func   = NULL;
    cll->delete_func    = NULL;
    cll->print_func     = NULL;
    cll->size           = 0;
    CLEAN(cll);
}

/*** end singly_linked_list.c ***/
