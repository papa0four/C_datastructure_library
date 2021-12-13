//
// Created by jsabs on 12/9/21.
//

#include "../include/print_stack.h"

void print_stack_int (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %d ] --> ", current->index, *(int *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %d ] --| }\n", current->index, *(int *)current->data);
    }
}

void print_stack_float (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %f ] --> ", current->index, *(float *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %f ] --| }\n", current->index, *(float *)current->data);
    }
}

void print_stack_double (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %lf ] --> ", current->index, *(double *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %lf ] --| }\n", current->index, *(double *)current->data);
    }
}

void print_stack_str (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %s ] --> ", current->index, (char *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %s ] --| }\n", current->index, (char *)current->data);
    }
}

void print_stack_uint8 (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIu8 " ] --> ", current->index, *(uint8_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIu8 " ] --| }\n", current->index, *(uint8_t *)current->data);
    }
}

void print_stack_int8 (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIi8 " ] --> ", current->index, *(int8_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIi8 " ] --| }\n", current->index, *(int8_t *)current->data);
    }
}

void print_stack_uint16 (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIu16 " ] --> ", current->index, *(uint16_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIu16 " ] --| }\n", current->index, *(uint16_t *)current->data);
    }
}

void print_stack_int16 (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIi16 " ] --> ", current->index, *(int16_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIi16 " ] --| }\n", current->index, *(int16_t *)current->data);
    }
}

void print_stack_uint32 (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIu32 " ] --> ", current->index, *(uint32_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIu32 " ] --| }\n", current->index, *(uint32_t *)current->data);
    }
}

void print_stack_uint64 (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIu64 " ] --> ", current->index, *(uint64_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIu64 " ] --| }\n", current->index, *(uint64_t *)current->data);
    }
}

void print_stack_int64 (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIi64 " ] --> ", current->index, *(int64_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIi64 " ] --| }\n", current->index, *(int64_t *)current->data);
    }
}

void print_stack_bool (stack_t * stack)
{
    if (NULL == stack)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: stack container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == stack->top)
    {
        fprintf(stdout, "STACK: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = stack->top;
        fprintf(stdout, "STACK: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %s ] --> ", current->index, 1 == *(bool *)current->data ? "true" : "false");
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %s ] --| }\n", current->index, 1 == *(bool *)current->data ? "true" : "false");
    }
}

/*** end print_stack.c ***/
