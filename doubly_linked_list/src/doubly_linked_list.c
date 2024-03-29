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

static dll_t * det_func (dll_t * dll, uint16_t flag)
{
    param_check(__FILE__, __LINE__, ARG_1, dll);

    dll->memcmp_func  = cmp_address_t;
    dll->delete_func  = delete_node;

    switch (flag)
    {
        case (INT_T):
        {
            dll->compare_func   = cmp_int_t;
            dll->print_func     = print_list_int;
            break;
        }

        case (FLT_T):
        {
            dll->compare_func   = cmp_flt_t;
            dll->print_func     = print_list_float;
            break;
        }

        case (DBL_T):
        {
            dll->compare_func   = cmp_dbl_t;
            dll->print_func     = print_list_double;
            break;
        }

        case (STR_T):
        {
            dll->compare_func   = cmp_str_t;
            dll->print_func     = print_list_str;
            break;
        }

        case (UINT8_T):
        {
            dll->compare_func   = cmp_uint8_t;
            dll->print_func     = print_list_uint8;
            break;
        }

        case (INT8_T):
        {
            dll->compare_func   = cmp_int8_t;
            dll->print_func     = print_list_int8;
            break;
        }

        case (UINT16_T):
        {
            dll->compare_func   = cmp_uint16_t;
            dll->print_func     = print_list_uint16;
            break;
        }

        case (INT16_T):
        {
            dll->compare_func   = cmp_int16_t;
            dll->print_func     = print_list_int16;
            break;
        }

        case (UINT32_T):
        {
            dll->compare_func   = cmp_uint32_t;
            dll->print_func     = print_list_uint32;
            break;
        }

        case (UINT64_T):
        {
            dll->compare_func   = cmp_uint64_t;
            dll->print_func     = print_list_uint64;
            break;
        }

        case (INT64_T):
        {
            dll->compare_func   = cmp_int64_t;
            dll->print_func     = print_list_int64;
            break;
        }

        case (BOOL_T):
        {
            dll->compare_func   = cmp_bool_t;
            dll->print_func     = print_list_bool;
            break;
        }

        case (CUSTOM_T):
        {
            dll->compare_func   = cmp_address_t;
            dll->print_func     = print_list_custom_default;
            break;
        }

        case (USR_DEFINE_T):
        {
            dll->compare_func   = cmp_address_t;
            break;
        }

        default:
        {
            dll = NULL;
            break;
        }
    }

    return dll;
}

dll_t * init (uint16_t node_type)
{
    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    dll_t * dll = calloc(1, sizeof(dll_t));
    if (NULL == dll)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate list container: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    dll = det_func(dll, node_type);
    if (NULL == dll)
    {
        fprintf(stderr, "%s(): error occurred setting up list: functions could not be determined\n",
                        __func__);
        return NULL;
    }
    

    dll->head = NULL;
    dll->tail = NULL;
    dll->size = 0;

    return dll;
}

static node_t * det_node_func (node_t * node, uint16_t flag)
{
    param_check(__FILE__, __LINE__, ARG_1, node);

    switch (flag)
    {
        case (INT_T):
        {
            node->pnode_func     = print_int;
            break;
        }

        case (FLT_T):
        {
            node->pnode_func     = print_float;
            break;
        }

        case (DBL_T):
        {
            node->pnode_func     = print_double;
            break;
        }

        case (STR_T):
        {
            node->pnode_func     = print_string;
            break;
        }

        case (UINT8_T):
        {
            node->pnode_func     = print_uint8;
            break;
        }

        case (INT8_T):
        {
            node->pnode_func     = print_int8;
            break;
        }

        case (UINT16_T):
        {
            node->pnode_func     = print_uint16;
            break;
        }

        case (INT16_T):
        {
            node->pnode_func     = print_int16;
            break;
        }

        case (UINT32_T):
        {
            node->pnode_func     = print_uint32;
            break;
        }

        case (UINT64_T):
        {
            node->pnode_func     = print_uint64;
            break;
        }

        case (INT64_T):
        {
            node->pnode_func     = print_int64;
            break;
        }

        case (BOOL_T):
        {
            node->pnode_func     = print_bool;
            break;
        }

        case (CUSTOM_T):
        {
            node->pnode_func     = print_custom_default;
            break;
        }

        case (USR_DEFINE_T):
        {
            break;
        }

        default:
        {
            node = NULL;
            break;
        }
    }

    return node;
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
    node->prev          = NULL;
    node->next          = NULL;

    return node;
}

int append (dll_t * dll, void * node_data, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_2, dll, node_data);

    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return -1;
    }

    node_t * new = NULL;
    if (NULL == dll->head)
    {
        new = create_node(node_data, node_type);
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
        new = create_node(node_data, node_type);
        if (NULL == new)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return 1;
        }

        new->prev       = dll->tail;
        new->index      = dll->size;
        dll->tail->next = new;
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

void insert_new_head (dll_t * dll, const void * data, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_2, dll, data);

    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        int ret_val = append(dll, (void *)data, node_type);
        if ((-1 == ret_val) || (1 == ret_val))
        {
            return;
        }
    }
    else
    {
        node_t * old_head = dll->head;
        node_t * new_head = create_node((void *)data, node_type);
        if (NULL == new_head)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return;
        }
        dll->head         = new_head;
        new_head->next    = old_head;
        old_head->prev    = new_head;
        dll->size++;
        increment_index(dll, old_head);
    }
}

void insert_at_index (dll_t * dll, void * data, size_t index, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_2, dll, data);

    if (index > dll->size - 1)
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

    if ((index > 0) && (NULL == dll->head))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: current list is empty, insert at index 0 is the only"
                                " permissible location: %s\n", __func__, strerror(errno));
        return;
    }

    if (0 == index)
    {
        insert_new_head(dll, (const void *)data, node_type);
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

            node_t * new_node = create_node(data, node_type);
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

void insert_before (dll_t * dll, node_t * start_node, void * data, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_3, dll, start_node, data);

    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (0 == dll->memcmp_func(dll->head, start_node))
    {
        insert_new_head(dll, data, node_type);
    }
    else
    {
        node_t * current = dll->head;
        node_t * next    = NULL;
        while (current)
        {
            if (0 == dll->memcmp_func(current->next, start_node))
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
        new_node->prev  = current;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(dll, next);
        dll->size++;
    }
}

void insert_after (dll_t * dll, node_t * start_node, void * data, uint16_t node_type)
{
    param_check(__FILE__, __LINE__, ARG_3, dll, start_node, data);

    if (node_type > USR_DEFINE_T)
    {
        errno = EINVAL;
        fprintf(stderr, "%s(): type flag must be between 0 - 12: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (0 == dll->compare_func(dll->head->data, start_node->data))
    {
        node_t * next = dll->head->next;
        node_t * new_node = create_node(data, node_type);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create new node to be inserted\n",
                            __func__);
            return;
        }
        dll->head->next = new_node;
        new_node->prev  = dll->head;
        new_node->next  = next;
        new_node->index = next->index;
        increment_index(dll, next);
        dll->size++;
    }
    else if (0 == dll->compare_func(dll->tail->data, start_node->data))
    {
        int ret_val = append(dll, data, node_type);
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

        node_t * new_node = create_node(data, node_type);
        if (NULL == new_node)
        {
            fprintf(stderr, "%s: could not create new node to be inserted\n",
                            __func__);
            return;
        }

        find->next = new_node;
        new_node->prev  = find;
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
    param_check(__FILE__, __LINE__, ARG_2, dll, data);

    node_t * current = dll->head;

    while (current)
    {
        if (0 == dll->compare_func(current->data, data))
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
    param_check(__FILE__, __LINE__, ARG_2, dll, data);

    if (0 == dll->compare_func(dll->head->data, data))
    {
        node_t * old_head = dll->head;
        dll->head         = old_head->next;
        dll->head->prev   = NULL;
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
                current->prev   = dll->tail;
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
                size_t index        = temp->index;
                current->next       = current->next->next;
                current->next->prev = current;
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
    while (current)
    {
        temp    = current;
        current = current->next;
        dll->delete_func(temp->data);
        dll->delete_func(temp);
    }
    
    dll->head           = NULL;
    dll->tail           = NULL;
    dll->memcmp_func    = NULL;
    dll->compare_func   = NULL;
    dll->delete_func    = NULL;
    dll->print_func     = NULL;
    dll->size           = 0;
    CLEAN(dll);
}

/*** end singly_linked_list.c ***/