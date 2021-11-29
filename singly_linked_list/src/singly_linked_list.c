//
// Created by jsabs on 11/17/21.
//

#include "../include/print_list.h"
#include "../include/print_node.h"
#include "../include/compare_functions.h"
#include "../include/delete_function.h"

sll_t * init(cmp_f cmp_func_t,
             del_f del_func_t,
             print_f print_func_t,
             print_n pnode_func_t)
{
    /* allocate new list structure, sets errno on calloc failure */
    sll_t * sll = calloc(1, sizeof(sll_t));
    if (NULL == sll)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate list container: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    /* initialize head and tail to NULL and size to 0 */
    sll->head = NULL;
    sll->tail = NULL;
    sll->size = 0;

    sll->compare_func = cmp_func_t;
    sll->delete_func  = del_func_t;
    sll->print_func   = print_func_t;
    sll->pnode_func   = pnode_func_t;

    /* return a pointer to the empty structure */
    return sll;
}

node_t * create_node (void * data)
{
    /* verify valid data has been passed or set errno and return */
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data passed is NULL: %s\n",
                __func__, strerror(errno));
    }

    node_t * node = calloc(1, sizeof(node_t));
    /* allocate new node, sets errno on calloc failure */
    if (NULL == node)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate memory for new node: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    /* set initial index to 0, update in various add function */
    node->index = 0;
    node->data  = data;

    /* set initial next pointer to NULL, update in various add function */
    node->next  = NULL;

    return node;
}

int append (sll_t * sll, void * node_data)
{
    /* initial parameter check, set errno on error */
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

        new->index = sll->size;
        sll->tail->next = new;
        sll->tail = new;
        sll->size++;
    }
    return 0;
}

static void decrement_index (sll_t * sll, size_t start_pos)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
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

static void increment_index (sll_t * sll, size_t start_pos)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * current = sll->head->next;
    while (current)
    {
        if (current->index <= start_pos)
        {
            current->index++;
        }
        else
        {
            current->index++;
        }

        current = current->next;
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
        sll->head = new_head;
        new_head->next = old_head;
        sll->size++;
        increment_index(sll, new_head->index);
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

    if (0 == index)
    {
        insert_new_head(sll, data);
        return;
    }

    node_t * current    = sll->head;
    node_t * prev       = NULL;
    while (current)
    {
        if (index == current->next->index)
        {
            prev = current;
            current = current->next;
            node_t * new_node = create_node(data);
            //NULL check on create
            prev->next = new_node;
            new_node->next = current;
            sll->size++;
            increment_index(sll, index + 1);
            break;
        }

        current = current->next;
    }

    if (NULL == current)
    {
        fprintf(stderr, "%s: error occurred inserting new node\n", __func__);
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

node_t * find_singular_node (sll_t * sll, const void * data)
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
        return NULL;
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
        sll->head = old_head->next;
        sll->delete_func(old_head);
        sll->size--;
        decrement_index(sll, 0);
        return;
    }

    if (0 == sll->compare_func(sll->tail->data, data))
    {
        node_t * current = sll->head;
        node_t * temp    = NULL;

        while (current)
        {
            if (current->next == sll->tail)
            {
                temp = current->next;
                sll->delete_func(temp);
                current->next = NULL;
                sll->tail = current;
                sll->size--;
                return;
            }

            current = current->next;
        }
    }

    node_t * current = sll->head;
    node_t * temp    = NULL;
    while (current->next)
    {
        if (0 == sll->compare_func(current->next->data, data))
        {
            temp = current->next;
            size_t index = temp->index;
            current->next = current->next->next;
            sll->delete_func(temp);
            sll->size--;
            decrement_index(sll, index);
            break;
        }

        current = current->next;
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
        temp = current;
        current = current->next;
        sll->delete_func(temp);
    }
    sll->delete_func(current);
    sll->size = 0;
    CLEAN(sll);
}

/*** end singly_linked_list.c ***/
