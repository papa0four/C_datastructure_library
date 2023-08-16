//
// Created by jsabs on 11/17/21.
//

#include "../include/print_list.h"
#include "../include/print_node.h"
#include "../include/compare_functions.h"
#include "../include/delete_function.h"

sll_t * init (cmp_f cmp_func_t,
             del_f del_func_t,
             print_f print_func_t,
             print_n pnode_func_t)
{
    if ((NULL == cmp_func_t) ||
        (NULL == del_func_t) ||
        (NULL == print_func_t) ||
        (NULL == pnode_func_t))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more of the function pointer passed are NULL: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    sll_t * sll = calloc(1, sizeof(sll_t));
    if (NULL == sll)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate list container: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    sll->head = NULL;
    sll->tail = NULL;
    sll->size = 0;

    sll->compare_func = cmp_func_t;
    sll->delete_func  = del_func_t;
    sll->print_func   = print_func_t;
    sll->pnode_func   = pnode_func_t;

    return sll;
}

/**
 * @brief - allocates a node_t structure pointer to the heap, creating the new node to
 *          insert into the singly linked list structure. NOTE: this is an internal
 *          helper function that the user should not have to interact with, unless needed
 *          for special cases.
 * @param data - (void *) a generic pointer to the data to be stored within the node
 * @return - (node_t *) ON SUCCESS: returns a heap allocated node structure to insert
 *           into the singly linked list. There are two instances where create_node may fail.
 *           If the data parameter pointer passed is NULL, errno will be set to EINVAL and
 *           create_node will return a NULL pointer. The other instance that may occur is when the
 *           call to calloc fails (system level failure) in which, errno will be set to ENOMEM
 *           and create_node will return a NULL pointer.
 */
static node_t * create_node (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data passed is NULL: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    node_t * node = calloc(1, sizeof(node_t));
    if (NULL == node)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate memory for new node: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    node->index = 0;
    node->data  = data;
    node->next  = NULL;

    return node;
}

int append (sll_t * sll, void * node_data)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list pointer passed is NULL: %s\n",
                __func__, strerror(errno));
        return -1;
    }

    if (NULL == node_data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data pointer passed is NULL: %s\n",
                __func__, strerror(errno));
        return -1;
    }

    node_t * new = NULL;
    if (NULL == sll->head)
    {
        new = create_node(node_data);
        if (NULL == new)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return 1;
        }
        sll->head = new;
        sll->tail = new;
        sll->size++;
    }
    else
    {
        new = create_node(node_data);
        if (NULL == new)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return 1;
        }

        sll->tail->next = new;
        new->index      = sll->size;
        sll->tail       = new;
        sll->size++;
    }
    return 0;
}

/**
 * @brief - the intent of this helper function is to decrement all node indices without user interaction
 *          when removing a node from the linked list container.
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @param start_pos - (size_t) a numeric representation of the current node's index (n - 1) in the list
 * @return - None. NOTE: if the linked list pointer parameter is NULL or the start_pos parameter passed
 *           is greater than the current number of nodes stored within the linked list container, errno
 *           will be set EINVAL, the appropriate error message will be displayed to the user, and the indices
 *           will not be modified.
 */
static void decrement_index (sll_t * sll, size_t start_pos)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (start_pos > (sll->size - 1))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: start_pos parameter cannot exceed the current number of list nodes: %s\n",
                        __func__, strerror(errno));
        return;
    }

    node_t * current = sll->head;
    while (current)
    {
        if (current->index >= start_pos)
        {
            current->index--;
        }

        current = current->next;
    }
}

/**
 * @brief - the intent of this helper function is to increment all node indices without user interaction
 *          when inserting a node into the linked list container while not calling the append function.
 * @param sll - (sll_t *) a pointer to the current linked list storage container
 * @param start_node - (node_t *) a pointer to the node, in which, itself and all subsequent nodes will have
 *                      their indices incremented
 * @return - None. NOTE: if any combination of the parameters passed are NULL, errno will be set EINVAL,
 *           the appropriate error message will be displayed to the user, and the indices will not be modified.
 */
static void increment_index (sll_t * sll, node_t * start_node)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == start_node)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: start_node parameter passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    node_t * node = find_node(sll, start_node->data);
    if (NULL == node)
    {
        fprintf(stderr, "%s: could not find specified node\n",
                        __func__);
        return;
    }

    while (node)
    {
        node->index++;
        node = node->next;
    }
}

void insert_new_head (sll_t * sll, const void * data)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data pointer passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        int ret_val = append(sll, (void *)data);
        if ((-1 == ret_val) || (1 == ret_val))
        {
            return;
        }
    }
    else
    {
        node_t * old_head = sll->head;
        node_t * new_head = create_node((void *)data);
        if (NULL == new_head)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return;
        }
        sll->head       = new_head;
        new_head->next  = old_head;
        sll->size++;
        increment_index(sll, old_head);
    }
}

void insert_at_index (sll_t * sll, void * data, size_t index)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data parameter passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (index > sll->size - 1)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: index value passed cannot exceed list size: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if ((index > 0) && (NULL == sll->head))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: current list is empty, insert at index 0 is the only"
                                " permissible location: %s\n", __func__, strerror(errno));
        return;
    }

    if (0 == index)
    {
        insert_new_head(sll, (const void *)data);
        return;
    }

    node_t * current    = sll->head;
    node_t * prev       = NULL;
    while (current)
    {
        if (index == current->next->index)
        {
            prev    = current;
            current = current->next;

            node_t * new_node = create_node(data);
            if (NULL == new_node)
            {
                fprintf(stderr, "%s: could not create new node to insert\n",
                                __func__);
                return;
            }

            prev->next      = new_node;
            new_node->index = current->index;
            new_node->next  = current;
            sll->size++;
            increment_index(sll, current);
            break;
        }

        current = current->next;
    }

    if (NULL == current)
    {
        fprintf(stderr, "%s: error occurred inserting new node\n", __func__);
    }
}

void insert_before (sll_t * sll, node_t * start_node, void * data)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: linked list parameter passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == start_node)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: start_node parameter passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data parameter passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (0 == sll->compare_func(sll->head->data, start_node->data))
    {
        insert_new_head(sll, data);
    }
    else
    {
        node_t * current = sll->head;
        node_t * next    = NULL;
        while (current)
        {
            if (0 == sll->compare_func(current->next->data, start_node->data))
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

        node_t * new_node = create_node(data);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create node to be inserted\n",
                    __func__);
            return;
        }

        current->next   = new_node;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(sll, next);
        sll->size++;
    }
}

void insert_after (sll_t * sll, node_t * start_node, void * data)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: linked list parameter passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == start_node)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: start_node parameter passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data parameter passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (0 == sll->compare_func(sll->head->data, start_node->data))
    {
        node_t * next = sll->head->next;
        node_t * new_node = create_node(data);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create new node to be inserted\n",
                            __func__);
            return;
        }
        sll->head->next = new_node;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(sll, next);
        sll->size++;
    }
    else if (0 == sll->compare_func(sll->tail->data, start_node->data))
    {
        int ret_val = append(sll, data);
        if ((-1 == ret_val) || (1 == ret_val))
        {
            fprintf(stderr, "%s: could not insert new node\n",
                            __func__);
            return;
        }
    }
    else
    {
        node_t * find = find_node(sll, start_node->data);
        if (NULL == find)
        {
            fprintf(stderr, "%s: could not find desired node to insert after\n",
                            __func__);
            return;
        }
        node_t * next = find->next;

        node_t * new_node = create_node(data);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create new node to be inserted\n",
                            __func__);
            return;
        }

        find->next = new_node;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(sll, next);
        sll->size++;
    }
}

node_t * find_by_index (sll_t * sll, size_t index)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    if (NULL == sll->head)
    {
        fprintf(stderr, "%s: current list container is empty\n",
                        __func__);
        return NULL;
    }

    if (index > sll->size - 1)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: index value passed cannot exceed list size: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    node_t * current = sll->head;
    while (current)
    {
        if (index == current->index)
        {
            break;
        }

        current = current->next;
    }

    return current;
}

node_t * find_node (sll_t * sll, const void * data)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data pointer passed is NULL: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    node_t * node_to_find = sll->head;

    while (node_to_find)
    {
        if (0 == sll->compare_func(node_to_find->data, data))
        {
            break;
        }

        node_to_find = node_to_find->next;
    }

    if (NULL == node_to_find)
    {
        fprintf(stderr, "%s: node requested does not exist in list\n", __func__);
        return node_to_find;
    }

    return node_to_find;
}

size_t get_list_size (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return 0;
    }
    return sll->size;
}

void remove_node (sll_t * sll, const void * data)
{
    if ((NULL == sll) || (NULL== data))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more parameters passed are NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (0 == sll->compare_func(sll->head->data, data))
    {
        node_t * old_head = sll->head;
        sll->head         = old_head->next;
        sll->delete_func(old_head);
        sll->size--;
        decrement_index(sll, 0);
    }
    else if (0 == sll->compare_func(sll->tail->data, data))
    {
        node_t * current = sll->head;
        node_t * temp    = NULL;

        while (current)
        {
            if (current->next == sll->tail)
            {
                temp = current->next;
                sll->delete_func(temp);
                current->next   = NULL;
                sll->tail       = current;
                sll->size--;
                break;
            }

            current = current->next;
        }
    }
    else
    {
        node_t * current = sll->head;
        node_t * temp    = NULL;
        while (current->next)
        {
            if (0 == sll->compare_func(current->next->data, data))
            {
                temp = current->next;
                size_t index    = temp->index;
                current->next   = current->next->next;
                sll->delete_func(temp);
                sll->size--;
                decrement_index(sll, index);
                return;
            }

            current = current->next;
        }

        if ((0 != sll->compare_func(current->data, data)))
        {
            fprintf(stderr, "%s: data to remove is not within current list\n",
                    __func__);
            return;
        }
    }
}

void destroy_list (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        CLEAN(sll);
        return;
    }

    node_t * current    = sll->head;
    node_t * temp       = NULL;
    while (current->next)
    {
        temp    = current;
        current = current->next;
        sll->delete_func(temp);
    }
    sll->delete_func(current);
    sll->head           = NULL;
    sll->tail           = NULL;
    sll->compare_func   = NULL;
    sll->delete_func    = NULL;
    sll->print_func     = NULL;
    sll->pnode_func     = NULL;
    sll->size           = 0;
    CLEAN(sll);
}

/*** end singly_linked_list.c ***/
