//
// Created by jsabs on 11/29/21.
//

#include "../include/queue.h"
#include "../include/compare_functions.h"
#include "../include/print_queue.h"
#include "../include/delete_function.h"
#include "../include/print_node.h"

queue_t * init (cmp_f cmp_func_t,
               del_f del_func_t,
               print_f print_func_t)
{
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

static void decrement_pos (queue_t * queue, size_t start_pos)
{
    if (NULL == queue)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: queue container passed is NULL: %s\n",
                        __func__, strerror(errno));
        return;
    }

    if (start_pos > queue->size - 1)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: position parameter passed cannot exceed container size - 1: %s\n",
                        __func__, strerror(errno));
        return;
    }

    qnode_t * current = queue->head;
    while (current)
    {
        if (current->pos >= start_pos)
        {
            current->pos--;
        }
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
        decrement_pos(queue, 0);
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
    queue->size = 0;
    CLEAN(queue);
}

int main (void)
{
    queue_t * new_q = init(cmp_int_t,
                           delete_node,
                           print_queue_int);
    if (NULL == new_q)
    {
        return EXIT_FAILURE;
    }

    new_q->print_func(new_q);

    int data = 1337;
    int ret_val = enqueue(new_q, (void *)&data, print_int);
    if ((-1 == ret_val) || (1 == ret_val))
    {
        CLEAN(new_q);
        return EXIT_FAILURE;
    }

    int new_data = 31337;
    ret_val = enqueue(new_q, (void *)&new_data, print_int);
    if ((-1 == ret_val) || (1 == ret_val))
    {
        new_q->delete_func(new_q);
        CLEAN(new_q);
        return EXIT_FAILURE;
    }

    new_q->print_func(new_q);

    qnode_t * old_head = dequeue(new_q);
    if (NULL == old_head)
    {
        new_q->delete_func(new_q->tail);
        new_q->delete_func(new_q->head);
        CLEAN(new_q);
        return EXIT_FAILURE;
    }

    printf("popped data: %d\n", *(int *)old_head->data);
    CLEAN(old_head);

    new_q->print_func(new_q);

    printf("%s\n", true == is_empty(new_q) ? "true" : "false");

    peek((void *)new_q);

    ret_val = enqueue(new_q, (void *)&data, print_int);
    if ((-1 == ret_val) || (1 == ret_val))
    {
        CLEAN(new_q);
        return EXIT_FAILURE;
    }

    new_q->print_func(new_q);

    size_t current_size = get_queue_size(new_q);
    printf("size: %ld\n", current_size);

    destroy_queue(new_q);

    return EXIT_SUCCESS;
}

/*** end of queue.c ***/
