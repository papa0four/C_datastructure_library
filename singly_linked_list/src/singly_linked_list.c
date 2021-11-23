//
// Created by jsabs on 11/17/21.
//

#include "../include/print_list.h"

sll_t * init(cmp_f cmp_func_t,
             del_f del_func_t,
             print_f print_func_t)
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
            current->next = current->next->next;
            sll->delete_func(temp);
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

int main(void)
{
    sll_t * new = init(cmp_int_t,
                       delete_node,
                       print_list_int);
    if (NULL == new)
    {
        fprintf(stderr, "could not create list container\n");
        return EXIT_FAILURE;
    }

    int int_array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int ret_val = -1;
    for (int i = 0; i < 10; i++)
    {
        ret_val = append(new, (void *)&int_array[i]);
        if ((-1 == ret_val) || (1 == ret_val))
        {
            fprintf(stderr, "could not insert node %u\n", i);
            return EXIT_FAILURE;
        }
    }

    node_t * current = new->head;
    while (current)
    {
        if (NULL == current)
        {
            break;
        }
        printf("[ location: %p\tindex: %ld, data: %d ]\n",
               (void *)current, current->index, *(int *)current->data);
        current = current->next;
    }

    int * list_head = (int *)new->head->data;
    node_t * node_found = find_singular_node(new, (const void *)list_head);
    if (NULL == node_found)
    {
        perror("could not find requested node");
        return EXIT_FAILURE;
    }

    printf("node found at position: %ld\tnode data: %d\n", node_found->index, *(int *)node_found->data);

    new->print_func(new);

    int * current_head = (int *) new->head->data;
    remove_node(new, (void *) current_head);

    new->print_func(new);

    printf("tail data: %d\n", *(int *)new->tail->data);

    int * current_tail = (int *) new->tail->data;
    remove_node(new, (void *) current_tail);

    new->print_func(new);

    bool middle = true;

    remove_node(new, (void *)&middle);

    new->print_func(new);

    destroy_list(new);

    return 0;
}