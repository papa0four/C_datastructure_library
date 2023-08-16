//
// Created by jsabs on 12/9/21.
//

#include "../include/stack.h"
#include "../include/print_node.h"

void print_int (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * int_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)int_node);
    printf("Node Index: %ld\n\t", int_node->index);
    printf("Node Data: %d\n\t", *(int *)int_node->data);
    printf("Next Node Address: %p\n]\n", (void *)int_node->next);
}

void print_float (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * flt_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)flt_node);
    printf("Node Index: %ld\n\t", flt_node->index);
    printf("Node Data: %f\n\t", *(float *)flt_node->data);
    printf("Next Node Address: %p\n]\n", (void *)flt_node->next);
}

void print_double (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * dbl_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)dbl_node);
    printf("Node Index: %ld\n\t", dbl_node->index);
    printf("Node Data: %lf\n\t", *(double *)dbl_node->data);
    printf("Next Node Address: %p\n]\n", (void *)dbl_node->next);
}

void print_string (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * str_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)str_node);
    printf("Node Index: %ld\n\t", str_node->index);
    printf("Node Data: %s\n\t", (char *)str_node->data);
    printf("Next Node Address: %p\n]\n", (void *)str_node->next);
}

void print_uint8 (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * uint8_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)uint8_node);
    printf("Node Index: %ld\n\t", uint8_node->index);
    printf("Node Data: %" PRIu8 "\n\t", *(uint8_t *)uint8_node->data);
    printf("Next Node Address: %p\n]\n", (void *)uint8_node->next);
}

void print_int8 (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * int8_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)int8_node);
    printf("Node Index: %ld\n\t", int8_node->index);
    printf("Node Data: %" PRIi8 "\n\t", *(int8_t *)int8_node->data);
    printf("Next Node Address: %p\n]\n", (void *)int8_node->next);
}

void print_uint16 (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * uint16_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)uint16_node);
    printf("Node Index: %ld\n\t", uint16_node->index);
    printf("Node Data: %" PRIu16 "\n\t", *(uint16_t *)uint16_node->data);
    printf("Next Node Address: %p\n]\n", (void *)uint16_node->next);
}

void print_int16 (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * int16_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)int16_node);
    printf("Node Index: %ld\n\t", int16_node->index);
    printf("Node Data: %" PRIi16 "\n\t", *(int16_t *)int16_node->data);
    printf("Next Node Address: %p\n]\n", (void *)int16_node->next);
}

void print_uint32 (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * uint32_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)uint32_node);
    printf("Node Index: %ld\n\t", uint32_node->index);
    printf("Node Data: %" PRIu32 "\n\t", *(uint32_t *)uint32_node->data);
    printf("Next Node Address: %p\n]\n", (void *)uint32_node->next);
}

void print_uint64 (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * uint64_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)uint64_node);
    printf("Node Index: %ld\n\t", uint64_node->index);
    printf("Node Data: %" PRIu64 "\n\t", *(uint64_t *)uint64_node->data);
    printf("Next Node Address: %p\n]\n", (void *)uint64_node->next);
}

void print_int64 (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * int64_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)int64_node);
    printf("Node Index: %ld\n\t", int64_node->index);
    printf("Node Data: %" PRIi64 "\n\t", *(int64_t *)int64_node->data);
    printf("Next Node Address: %p\n]\n", (void *)int64_node->next);
}

void print_bool (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    node_t * bool_node = (node_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)bool_node);
    printf("Node Index: %ld\n\t", bool_node->index);
    printf("Node Data: %s\n\t", 1 == *(bool *)bool_node->data ? "true" : "false");
    printf("Next Node Address: %p\n]\n", (void *)bool_node->next);
}
