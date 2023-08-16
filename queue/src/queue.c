//
// Created by jsabs on 11/29/21.
//

#include "../include/queue.h"
#include "../include/delete_function.h"

queue_t * init (cmp_f cmp_func_t,
               del_f del_func_t,
               print_f print_func_t)
{
    if ((NULL == cmp_func_t) ||
        (NULL == del_func_t) ||
        (NULL == print_func_t))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: one or more function pointers passed are NULL: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }
    /* allocate new list structure, sets errno on calloc failure */
    queue_t * queue = calloc(1, sizeof(queue_t));
    if (NULL == queue)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate queue container: %s\n",
                __func__, strerror(errno));
        return NULL;
    }

    /* initialize head and tail to NULL and size to 0 */
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    queue->compare_func = cmp_func_t;
    queue->delete_func  = del_func_t;
    queue->print_func   = print_func_t;

    /* return a pointer to the empty structure */
    return queue;
}

/**
 * @brief - this is a helper function, meant to allocate memory to the heap to store the appropriate
 *          queue node container date before placing the node within the queue. If the data parameter
 *          passed is NULL, create_node will set errno to EINVAL, print an error message to STDERR,
 *          and return a NULL node pointer.
 * @param data - (void *) a generic pointer contained the desired data to be stored within the newly created node.
 * @param pnode_func_t - (print_n) a function pointer passed by the user within enqueue and checked for validity.
 *                       This function pointer will point to the appropriate formatter print function, determined
 *                       by the user in order to print the specific data within the node.
 * @return - upon success, create_node will return a newly allocated queue node container, created on the heap
 *           and containing the appropriate data before being inserted into the queue storage container. If create_node
 *           receives an invalid parameter, errno will be set to EINVAL and the function will return a NULL pointer.
 *           If the call to calloc fails to allocate memory upon the heap, errno will be set to ENOMEM and
 *           create_node will return a NULL pointer.
 */
static qnode_t * create_node (const void * data, print_n pnode_func_t)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data passed to create is NULL: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    qnode_t * node = calloc(1, sizeof(qnode_t));
    if (NULL == node)
    {
        errno = ENOMEM;
        fprintf(stderr, "%s: could not allocate memory for new node: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    node->pos = 0;
    node->data = (void *)data;
    node->next = NULL;
    node->pnode_func = pnode_func_t;

    return node;
}

int enqueue (queue_t * queue, void * data, print_n pnode_func_t)
{
    if (NULL == pnode_func_t)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: formatted node print function pointer passed is NULL: %s\n",
                        __func__, strerror(errno));
        return -1;
    }

    if (NULL == queue)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return -1;
    }

    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data parameter passed is NULL: %s\n",
                        __func__, strerror(errno));
        return -1;
    }

    qnode_t * new = NULL;
    if (NULL == queue->head)
    {
        new = create_node(data, pnode_func_t);
        if (NULL == new)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return 1;
        }

        queue->head = new;
        queue->tail = new;
        queue->size++;
    }
    else
    {
        new = create_node(data, pnode_func_t);
        if (NULL == new)
        {
            fprintf(stderr, "%s: could not create new node\n", __func__);
            return 1;
        }

        new->pos = queue->size;
        queue->tail->next = new;
        queue->tail = new;
        queue->size++;
    }

    return 0;
}

/**
 * @brief - this function is an internal helper function meant to appropriate decrease the position member
 *          stored within the queue node container as nodes are removed from the queue container.
 * @param queue - (queue_t *) a pointer to the current queue storage container
 * @return - None. If the queue parameter passed is NULL, errno will be set to EINVAL and an error message
 *           will be sent to STDERR and the decrement functionality will not be performed.
 */
static void decrement_pos (queue_t * queue)
{
    if (NULL == queue)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    qnode_t * current = queue->head;
    while (current)
    {
        current->pos--;
        current = current->next;
    }
}

qnode_t * dequeue (queue_t * queue)
{
    if (NULL == queue)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return NULL;
    }

    qnode_t * current = NULL;
    if (NULL == queue->head->next)
    {
        current     = queue->head;
        queue->head = NULL;
        queue->size = 0;
    }
    else
    {
        current = queue->head;
        queue->head = queue->head->next;
        decrement_pos(queue);
        queue->size--;
    }

    return current;
}

bool is_empty (queue_t * queue)
{
    if (NULL == queue)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return false;
    }

    if ((queue->size == 0) || (NULL == queue->head))
    {
        return true;
    }

    return false;
}

void peek (queue_t * queue)
{
    if (NULL == queue)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == queue->head)
    {
        fprintf(stdout, "QUEUE: { EMPTY }\n");
    }
    else
    {
        queue->head->pnode_func((void *)queue->head);
    }
}

size_t get_queue_size (queue_t * queue)
{
    if (NULL == queue)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return 0;
    }

    if ((NULL == queue->head) || (queue->size == 0))
    {
        return 0;
    }

    return queue->size;
}

void destroy_queue (queue_t * queue)
{
    if (NULL == queue)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (NULL == queue->head)
    {
        CLEAN(queue);
        return;
    }

    qnode_t * current   = queue->head;
    qnode_t * temp      = NULL;
    while (current->next)
    {
        temp = current;
        current = current->next;
        queue->delete_func(temp);
    }

    queue->delete_func(current);
    queue->head         = NULL;
    queue->tail         = NULL;
    queue->delete_func  = NULL;
    queue->compare_func = NULL;
    queue->print_func   = NULL;
    queue->size         = 0;
    CLEAN(queue);
}

/*** end of queue.c ***/
