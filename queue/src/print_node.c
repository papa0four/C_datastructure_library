//
// Created by jsabs on 11/29/21.
//

#include "../include/print_node.h"
#include "../include/queue.h"

void print_int (void * data)
{
    if (NULL == data)
    {
        errno = EINVAL;
        fprintf(stderr, "%s: data value passed is NULL: %s\n",
                __func__, strerror(errno));
        return;
    }

    qnode_t * int_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)int_node);
    printf("Node Data: %d\n]\n", *(int *)int_node->data);
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

    qnode_t * flt_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)flt_node);
    printf("Node Data: %f\n]\n", *(float *)flt_node->data);
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

    qnode_t * dbl_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)dbl_node);
    printf("Node Data: %lf\n]\n", *(double *)dbl_node->data);
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

    qnode_t * str_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)str_node);
    printf("Node Data: %s\n]\n", (char *)str_node->data);
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

    qnode_t * uint8_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)uint8_node);
    printf("Node Data: %" PRIu8 "\n]\n", *(uint8_t *)uint8_node->data);
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

    qnode_t * int8_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)int8_node);
    printf("Node Data: %" PRIi8 "\n]\n", *(int8_t *)int8_node->data);
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

    qnode_t * uint16_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)uint16_node);
    printf("Node Data: %" PRIu16 "\n]\n", *(uint16_t *)uint16_node->data);
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

    qnode_t * int16_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)int16_node);
    printf("Node Data: %" PRIi16 "\n]\n", *(int16_t *)int16_node->data);
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

    qnode_t * uint32_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)uint32_node);
    printf("Node Data: %" PRIu32 "\n]\n", *(uint32_t *)uint32_node->data);
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

    qnode_t * uint64_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)uint64_node);
    printf("Node Data: %" PRIu64 "\n]\n", *(uint64_t *)uint64_node->data);
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

    qnode_t * int64_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)int64_node);
    printf("Node Data: %" PRIi64 "\n]\n", *(int64_t *)int64_node->data);
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

    qnode_t * bool_node = (qnode_t *)data;
    printf("Node: \n[\n\t");
    printf("Memory Address: %p\n\t", (void *)bool_node);
    printf("Node Data: %s\n]\n", 1 == *(bool *)bool_node->data ? "true" : "false");
}