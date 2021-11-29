//
// Created by jsabs on 11/29/21.
//

#include "../include/print_queue.h"

#include "../include/print_queue.h"

void print_queue_int (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %d ] --> ", current->pos, *(int *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %d ] --| }\n", current->pos, *(int *)current->data);
    }
}

void print_queue_float (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %f ] --> ", current->pos, *(float *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %f ] --| }\n", current->pos, *(float *)current->data);
    }
}

void print_queue_double (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %lf ] --> ", current->pos, *(double *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %lf ] --| }\n", current->pos, *(double *)current->data);
    }
}

void print_queue_str (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %s ] --> ", current->pos, (char *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %s ] --| }\n", current->pos, (char *)current->data);
    }
}

void print_queue_uint8 (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %" PRIu8 " ] --> ", current->pos, *(uint8_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %" PRIu8 " ] --| }\n", current->pos, *(uint8_t *)current->data);
    }
}

void print_queue_int8 (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %" PRIi8 " ] --> ", current->pos, *(int8_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %" PRIi8 " ] --| }\n", current->pos, *(int8_t *)current->data);
    }
}

void print_queue_uint16 (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %" PRIu16 " ] --> ", current->pos, *(uint16_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %" PRIu16 " ] --| }\n", current->pos, *(uint16_t *)current->data);
    }
}

void print_queue_int16 (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %" PRIi16 " ] --> ", current->pos, *(int16_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %" PRIi16 " ] --| }\n", current->pos, *(int16_t *)current->data);
    }
}

void print_queue_uint32 (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %" PRIu32 " ] --> ", current->pos, *(uint32_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %" PRIu32 " ] --| }\n", current->pos, *(uint32_t *)current->data);
    }
}

void print_queue_uint64 (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %" PRIu64 " ] --> ", current->pos, *(uint64_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %" PRIu64 " ] --| }\n", current->pos, *(uint64_t *)current->data);
    }
}

void print_queue_int64 (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %" PRIi64 " ] --> ", current->pos, *(int64_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %" PRIi64 " ] --| }\n", current->pos, *(int64_t *)current->data);
    }
}

void print_queue_bool (queue_t * queue)
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
        fprintf(stdout, "QUEUE: { [EMPTY] }\n");
    }
    else
    {
        qnode_t * current = queue->head;
        fprintf(stdout, "QUEUE: { ");
        while (current->next)
        {
            fprintf(stdout, "[ pos %ld: %s ] --> ", current->pos, 1 == *(bool *)current->data ? "true" : "false");
            current = current->next;
        }

        fprintf(stdout, "[ pos %ld: %s ] --| }\n", current->pos, 1 == *(bool *)current->data ? "true" : "false");
    }
}

/*** end print_queue.c ***/
