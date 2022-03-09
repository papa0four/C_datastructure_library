//
// Created by jsabs on 11/17/21.
// updated by jsabs on 03/08/22.
//
#define _GNU_SOURCE

#include "../include/print_list.h"
#include "../include/print_node.h"
#include "../include/compare_functions.h"
#include "../include/delete_function.h"

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

dll_t * init (cmp_f cmp_func_t,
             del_f del_func_t,
             print_f print_func_t)
{
    param_check(__FILE__, __LINE__, ARG_3, cmp_func_t, del_func_t, print_func_t);

    dll_t * dll = calloc(1, sizeof(dll_t));
    if (NULL == dll)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate list container: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    dll->head = NULL;
    dll->tail = NULL;
    dll->size = 0;

    dll->compare_func = cmp_func_t;
    dll->delete_func  = del_func_t;
    dll->print_func   = print_func_t;

    return dll;
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
static node_t * create_node (void * data, print_n pnode_func_t)
{
    node_t * node = calloc(1, sizeof(node_t));
    if (NULL == node)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate memory for new node: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    node->index         = 0;
    node->data          = data;
    node->prev          = NULL;
    node->next          = NULL;
    node->pnode_func    = pnode_func_t;

    return node;
}

int append (dll_t * dll, void * node_data, print_n pnode_func_t)
{
    param_check(__FILE__, __LINE__, ARG_3, dll, node_data, pnode_func_t);

    node_t * new = NULL;
    if (NULL == dll->head)
    {
        new = create_node(node_data, pnode_func_t);
        if (NULL == new)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return 1;
        }
        dll->head = new;
        dll->tail = new;
        dll->size++;
    }
    else
    {
        new = create_node(node_data, pnode_func_t);
        if (NULL == new)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return 1;
        }

        new->prev       = dll->tail;
        dll->tail->next = new;
        new->index      = dll->size;
        dll->tail       = new;
        dll->size++;
    }
    return 0;
}

/**
 * @brief - the intent of this helper function is to decrement all node indices without user interaction
 *          when removing a node from the linked list container.
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @param start_pos - (size_t) a numeric representation of the current node's index (n - 1) in the list
 * @return - None. NOTE: if the linked list pointer parameter is NULL or the start_pos parameter passed
 *           is greater than the current number of nodes stored within the linked list container, errno
 *           will be set EINVAL, the appropriate error message will be displayed to the user, and the indices
 *           will not be modified.
 */
static void decrement_index (dll_t * dll, size_t start_pos)
{
    if (start_pos > (dll->size - 1))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: start_pos parameter cannot exceed the current number of list nodes: %s\n",
                        __func__, strerror(errno));
        return;
    }

    node_t * current = dll->head;
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
 * @param dll - (dll_t *) a pointer to the current linked list storage container
 * @param start_node - (node_t *) a pointer to the node, in which, itself and all subsequent nodes will have
 *                      their indices incremented
 * @return - None. NOTE: if any combination of the parameters passed are NULL, errno will be set EINVAL,
 *           the appropriate error message will be displayed to the user, and the indices will not be modified.
 */
static void increment_index (dll_t * dll, node_t * start_node)
{
    if (NULL == start_node)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: start_node parameter passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    node_t * node = find_node(dll, start_node->data);
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

void insert_new_head (dll_t * dll, const void * data, print_n pnode_func_t)
{
    param_check(__FILE__, __LINE__, ARG_3, dll, data, pnode_func_t);

    if (NULL == dll->head)
    {
        int ret_val = append(dll, (void *)data, pnode_func_t);
        if ((-1 == ret_val) || (1 == ret_val))
        {
            return;
        }
    }
    else
    {
        node_t * old_head = dll->head;
        node_t * new_head = create_node((void *)data, pnode_func_t);
        if (NULL == new_head)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return;
        }
        dll->head               = new_head;
        new_head->next          = old_head;
        new_head->next->prev    = new_head;
        dll->size++;
        increment_index(dll, old_head);
    }
}

void insert_at_index (dll_t * dll, void * data, size_t index, print_n pnode_func_t)
{
    param_check(__FILE__, __LINE__, ARG_4, dll, data, pnode_func_t);

    if (index > dll->size - 1)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: index value passed cannot exceed list size: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if ((index > 0) && (NULL == dll->head))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: current list is empty, insert at index 0 is the only"
                                " permissible location: %s\n", __func__, strerror(errno));
        return;
    }

    if (0 == index)
    {
        insert_new_head(dll, (const void *)data, pnode_func_t);
        return;
    }

    node_t * current    = dll->head;
    node_t * prev       = NULL;
    while (current)
    {
        if (index == current->next->index)
        {
            prev    = current;
            current = current->next;

            node_t * new_node = create_node(data, pnode_func_t);
            if (NULL == new_node)
            {
                fprintf(stderr, "%s: could not create new node to insert\n",
                                __func__);
                return;
            }

            prev->next      = new_node;
            new_node->index = current->index;
            new_node->prev  = prev;
            new_node->next  = current;
            dll->size++;
            increment_index(dll, current);
            break;
        }

        current = current->next;
    }

    if (NULL == current)
    {
        fprintf(stderr, "%s: error occurred inserting new node\n", __func__);
    }
}

void insert_before (dll_t * dll, node_t * start_node, void * data, print_n pnode_func_t)
{
    if (NULL == dll)
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

    if (NULL == pnode_func_t)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: node print function passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (0 == dll->compare_func(dll->head->data, start_node->data))
    {
        insert_new_head(dll, data, pnode_func_t);
    }
    else
    {
        node_t * current = dll->head;
        node_t * next    = NULL;
        while (current)
        {
            if (0 == dll->compare_func(current->next->data, start_node->data))
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

        node_t * new_node = create_node(data, pnode_func_t);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create node to be inserted\n",
                    __func__);
            return;
        }

        current->next   = new_node;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(dll, next);
        dll->size++;
    }
}

void insert_after (dll_t * dll, node_t * start_node, void * data, print_n pnode_func_t)
{
    if (NULL == dll)
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

    if (NULL == pnode_func_t)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: nopde print function passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (0 == dll->compare_func(dll->head->data, start_node->data))
    {
        node_t * next = dll->head->next;
        node_t * new_node = create_node(data, pnode_func_t);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create new node to be inserted\n",
                            __func__);
            return;
        }
        dll->head->next = new_node;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(dll, next);
        dll->size++;
    }
    else if (0 == dll->compare_func(dll->tail->data, start_node->data))
    {
        int ret_val = append(dll, data, pnode_func_t);
        if ((-1 == ret_val) || (1 == ret_val))
        {
            fprintf(stderr, "%s: could not insert new node\n",
                            __func__);
            return;
        }
    }
    else
    {
        node_t * find = find_node(dll, start_node->data);
        if (NULL == find)
        {
            fprintf(stderr, "%s: could not find desired node to insert after\n",
                            __func__);
            return;
        }
        node_t * next = find->next;

        node_t * new_node = create_node(data, pnode_func_t);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create new node to be inserted\n",
                            __func__);
            return;
        }

        find->next = new_node;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(dll, next);
        dll->size++;
    }
}

node_t * find_by_index (dll_t * dll, size_t index)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    if (NULL == dll->head)
    {
        fprintf(stderr, "%s: current list container is empty\n",
                        __func__);
        return NULL;
    }

    if (index > dll->size - 1)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: index value passed cannot exceed list size: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    node_t * current = dll->head;
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

node_t * find_node (dll_t * dll, const void * data)
{
    if (NULL == dll)
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

    node_t * node_to_find = dll->head;

    while (node_to_find)
    {
        if (0 == dll->compare_func(node_to_find->data, data))
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

size_t get_list_size (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return 0;
    }
    return dll->size;
}

void remove_node (dll_t * dll, const void * data)
{
    if ((NULL == dll) || (NULL== data))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more parameters passed are NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (0 == dll->compare_func(dll->head->data, data))
    {
        node_t * old_head = dll->head;
        dll->head         = old_head->next;
        dll->delete_func(old_head);
        dll->size--;
        decrement_index(dll, 0);
    }
    else if (0 == dll->compare_func(dll->tail->data, data))
    {
        node_t * current = dll->head;
        node_t * temp    = NULL;

        while (current)
        {
            if (current->next == dll->tail)
            {
                temp = current->next;
                dll->delete_func(temp);
                current->next   = NULL;
                dll->tail       = current;
                dll->size--;
                break;
            }

            current = current->next;
        }
    }
    else
    {
        node_t * current = dll->head;
        node_t * temp    = NULL;
        while (current->next)
        {
            if (0 == dll->compare_func(current->next->data, data))
            {
                temp = current->next;
                size_t index    = temp->index;
                current->next   = current->next->next;
                dll->delete_func(temp);
                dll->size--;
                decrement_index(dll, index);
                return;
            }

            current = current->next;
        }

        if ((0 != dll->compare_func(current->data, data)))
        {
            fprintf(stderr, "%s: data to remove is not within current list\n",
                    __func__);
            return;
        }
    }
}

void destroy_list (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        CLEAN(dll);
        return;
    }

    node_t * current    = dll->head;
    node_t * temp       = NULL;
    while (current->next)
    {
        temp    = current;
        current = current->next;
        dll->delete_func(temp);
    }
    dll->delete_func(current);
    dll->head           = NULL;
    dll->tail           = NULL;
    dll->compare_func   = NULL;
    dll->delete_func    = NULL;
    dll->print_func     = NULL;
    dll->size           = 0;
    CLEAN(dll);
}

/*** end singly_linked_list.c ***/