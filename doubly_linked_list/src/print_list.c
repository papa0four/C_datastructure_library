//
// Created by jsabs on 11/22/21.
//

#include "../include/print_list.h"

void print_list_int (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %d ] --> ", current->index, *(int *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %d ] --| }\n", current->index, *(int *)current->data);
    }
}

void print_list_float (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %f ] --> ", current->index, *(float *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %f ] --| }\n", current->index, *(float *)current->data);
    }
}

void print_list_double (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %lf ] --> ", current->index, *(double *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %lf ] --| }\n", current->index, *(double *)current->data);
    }
}

void print_list_str (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %s ] --> ", current->index, (char *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %s ] --| }\n", current->index, (char *)current->data);
    }
}

void print_list_uint8 (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIu8 " ] --> ", current->index, *(uint8_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIu8 " ] --| }\n", current->index, *(uint8_t *)current->data);
    }
}

void print_list_int8 (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIi8 " ] --> ", current->index, *(int8_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIi8 " ] --| }\n", current->index, *(int8_t *)current->data);
    }
}

void print_list_uint16 (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIu16 " ] --> ", current->index, *(uint16_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIu16 " ] --| }\n", current->index, *(uint16_t *)current->data);
    }
}

void print_list_int16 (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIi16 " ] --> ", current->index, *(int16_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIi16 " ] --| }\n", current->index, *(int16_t *)current->data);
    }
}

void print_list_uint32 (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIu32 " ] --> ", current->index, *(uint32_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIu32 " ] --| }\n", current->index, *(uint32_t *)current->data);
    }
}

void print_list_uint64 (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIu64 " ] --> ", current->index, *(uint64_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIu64 " ] --| }\n", current->index, *(uint64_t *)current->data);
    }
}

void print_list_int64 (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %" PRIi64 " ] --> ", current->index, *(int64_t *) current->data);
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %" PRIi64 " ] --| }\n", current->index, *(int64_t *)current->data);
    }
}

void print_list_bool (dll_t * dll)
{
    if (NULL == dll)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: list container passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    if (NULL == dll->head)
    {
        fprintf(stdout, "LIST: { [EMPTY] }\n");
    }
    else
    {
        node_t * current = dll->head;
        fprintf(stdout, "LIST: { ");
        while (current->next)
        {
            fprintf(stdout, "[ idx %ld: %s ] --> ", current->index, 1 == *(bool *)current->data ? "true" : "false");
            current = current->next;
        }

        fprintf(stdout, "[ idx %ld: %s ] --| }\n", current->index, 1 == *(bool *)current->data ? "true" : "false");
    }
}

/*** end of print_list.c ***/