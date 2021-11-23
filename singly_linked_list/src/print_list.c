//
// Created by jsabs on 11/22/21.
//

#include "../include/print_list.h"

void print_list_int (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %d ] --> ", *(int *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %d ] --| }\n", *(int *)current->data);
    }
}

void print_list_float (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %f ] --> ", *(float *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %f ] --| }\n", *(float *)current->data);
    }
}

void print_list_double (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %lf ] --> ", *(double *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %lf ] --| }\n", *(double *)current->data);
    }
}

void print_list_str (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %s ] --> ", (char *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %s ] --| }\n", (char *)current->data);
    }
}

void print_list_uint8 (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %" PRIu8 " ] --> ", *(uint8_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %" PRIu8 " ] --| }\n", *(uint8_t *)current->data);
    }
}

void print_list_int8 (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %" PRIi8 " ] --> ", *(int8_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %" PRIi8 " ] --| }\n", *(int8_t *)current->data);
    }
}

void print_list_uint16 (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %" PRIu16 " ] --> ", *(uint16_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %" PRIu16 " ] --| }\n", *(uint16_t *)current->data);
    }
}

void print_list_int16 (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %" PRIi16 " ] --> ", *(int16_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %" PRIi16 " ] --| }\n", *(int16_t *)current->data);
    }
}

void print_list_uint32 (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %" PRIu32 " ] --> ", *(uint32_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %" PRIu32 " ] --| }\n", *(uint32_t *)current->data);
    }
}

void print_list_uint64 (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %" PRIu64 " ] --> ", *(uint64_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %" PRIu64 " ] --| }\n", *(uint64_t *)current->data);
    }
}

void print_list_int64 (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %" PRIi64 " ] --> ", *(int64_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ %" PRIi64 " ] --| }\n", *(int64_t *)current->data);
    }
}

void print_list_bool (sll_t * sll)
{
    if (NULL == sll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == sll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = sll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ %s ] --> ", 1 == *(bool *)current->data ? "true" : "false");
            current = current->next;
        }

        fprintf(stdout, "[ %s ] --| }\n", 1 == *(bool *)current->data ? "true" : "false");
    }
}

/*** end of print_list.c ***/
