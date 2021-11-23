#include "llist.h"

llist_t * init ()
{
    llist_t * p_list = calloc(1, sizeof(llist_t));
    if (NULL == p_list)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate list container: %s\n", __func__, strerror(errno));
        return NULL;
    }
    p_list->size = 0;

    return p_list;
}

bool append(llist_t * p_list, void * p_id, void * p_data)
{
    if ((NULL == p_list) || (NULL == p_data))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more parameters passed are invalid: %s\n", __func__, strerror(errno));
        return false;
    }

    ll_node_t * p_new = calloc(1, sizeof(ll_node_t));
    if (NULL == p_new)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate for node: %s\n", __func__, strerror(errno));
        return false;
    }

    uint32_t * p_node_id    = (uint32_t *) p_id;
    uint32_t * p_node_data  = (uint32_t *) p_data;

    p_new->id   = *p_node_id;
    p_new->data = *p_node_data;
    p_new->next = NULL;

    if (NULL == p_list->head)
    {
        p_list->head = p_new;
        p_list->size++;
    }
    else
    {
        ll_node_t * p_current = p_list->head;
        while (p_current->next)
        {
            p_current = p_current->next;
        }
        p_current->next = p_new;
        p_list->size++;
    }

    return true;
}

size_t get_list_size (llist_t * p_list)
{
    if ((NULL == p_list) || (NULL == p_list->head))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more parameters passed are invalid: %s\n", __func__, strerror(errno));
        return 0;
    }

    return p_list->size;
}

int delete_all_given_nodes (llist_t * p_list, void * p_data_to_rm)
{
    if ((NULL == p_list) || (NULL == p_data_to_rm))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more parameters passed are invalid: %s\n", __func__, strerror(errno));
        return -1;
    }

    size_t old_sz = get_list_size(p_list);

    uint32_t  * p_id        = (uint32_t *) p_data_to_rm;
    ll_node_t * p_current   = p_list->head;
    ll_node_t * p_prev      = NULL;
    int         found       = 0;

    while (p_current)
    {
        //store next pointer, in case we remove current
        ll_node_t * p_next = p_current->next;

        // did we find the node?
        if (p_current->id == *p_id)
        {
            // update list and local data that node was found
            CLEAN(p_current);
            p_list->size--;
            found++;

            // update the link
            if (p_prev)
            {
                // link previous node to next node
                p_prev->next = p_next;
            }
            else
            {
                // no previous node, head node was removed so update head pointer
                p_list->head = p_next;
            }
        }
        else
        {
            // didnt free current, store as previous before continuing iteration
            p_prev = p_current;
        }

        // iterate the list
        p_current = p_next;
    }

    size_t new_sz = get_list_size(p_list);

    if ((new_sz == old_sz) && (0 != found))
    {
        fprintf(stderr, "%s: could not remove node properly\n", __func__);
        return -1;
    }
    else if ((new_sz == old_sz) && (0 == found))
    {
        return 1;
    }
    else
    {
        return 0;
    }

    return -1;
}

void * get_relevant_nodes (llist_t * p_list, void * p_find)
{
    if ((NULL == p_list) || (NULL == p_list->head) || (NULL == p_find))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or mora parameters passed are invalid: %s\n", __func__, strerror(errno));
        return NULL;
    }

    uint32_t    * p_find_me = (uint32_t *) p_find;
    llist_t     * p_answers = calloc(1, sizeof(llist_t));
    if (NULL == p_answers)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate container: %s\n", __func__, strerror(errno));
        return NULL;
    }

    ll_node_t * p_current   = p_list->head;
    bool        added       = false;
    int         found       = 0;

    while (p_current)
    {
        if (p_current->id == *p_find_me)
        {
            added = append(p_answers, p_find, (void *)&p_current->data);
            if (false == added)
            {
                fprintf(stderr, "%s: could not append node to answers\n", __func__);
            }

            found++;
        }

        p_current = p_current->next;
    }

    if (0 == found)
    {
        fprintf(stderr, "%s: no nodes were found containing: %u\n", __func__, *p_find_me);
        CLEAN(p_answers);
        return NULL;
    }

    return (void *) p_answers;
}

void print_relevant_array (void * p_list, void * p_id)
{
    if ((NULL == p_list) || (NULL == p_id))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more parameters passed are invalid: %s\n", __func__, strerror(errno));
        return;
    }

    uint32_t    * p_jid     = (uint32_t *) p_id;
    llist_t     * p_nodes   = (llist_t *)p_list;
    ll_node_t   * p_current = p_nodes->head;

    printf("\tANSWERS: [ JOB: %u ]: ", *p_jid);
    while (p_current->next)
    {
        printf("[ %u ] --> ", p_current->data);
        p_current = p_current->next;
    }
    printf("[ %u ] --|\n", p_current->data);
}

bool destroy (llist_t * p_list)
{
    if (NULL == p_list)
    {
        return false;
    }

    if (NULL == p_list->head)
    {
        CLEAN(p_list);
        return true;
    }

    ll_node_t * p_current = p_list->head;
    ll_node_t * p_temp = NULL;

    while (p_current)
    {
        if (NULL == p_current->next)
        {
            p_list->size--;
            CLEAN(p_current);
            break;
        }
        p_temp = p_current->next;
        CLEAN(p_current);
        p_list->size--;
        p_current = p_temp;
    }

    p_list->size = 0;
    CLEAN(p_list);
    return true;
}

void print_list (llist_t * p_list)
{
    if ((NULL == p_list) || (NULL == p_list->head))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more parameters passed are invalid: %s\n", __func__, strerror(errno));
        return;
    }

    ll_node_t * p_current = p_list->head;
    printf("\tCURRENT LIST: [ HEAD ] --> ");
    while (p_current)
    {
        if (NULL == p_current->next)
        {
            printf("[ (%u, %u) ] --|\n", p_current->id, p_current->data);
            break;
        }
        printf("[ (%u, %u) ] -> ", p_current->id, p_current->data);
        p_current = p_current->next;
    }
}

/*** end llist.c ***/
