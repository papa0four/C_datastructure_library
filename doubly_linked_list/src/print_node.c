//
// Created by jsabs on 11/29/21.
//

#include "../include/print_node.h"

void print_int (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * int_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", int_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)int_node);
    fprintf(stdout, "Node Index: %ld\n\t", int_node->index);
    fprintf(stdout, "Node Data: %d\n\t", *(int *)int_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)int_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)int_node->next);
}

void print_float (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * flt_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", flt_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)flt_node);
    fprintf(stdout, "Node Index: %ld\n\t", flt_node->index);
    fprintf(stdout, "Node Data: %f\n\t", *(float *)flt_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)flt_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)flt_node->next);
}

void print_double (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * dbl_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", dbl_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)dbl_node);
    fprintf(stdout, "Node Index: %ld\n\t", dbl_node->index);
    fprintf(stdout, "Node Data: %lf\n\t", *(double *)dbl_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)dbl_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)dbl_node->next);
}

void print_string (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * str_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", str_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)str_node);
    fprintf(stdout, "Node Index: %ld\n\t", str_node->index);
    fprintf(stdout, "Node Data: %s\n\t", (char *)str_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)str_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)str_node->next);
}

void print_uint8 (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * uint8_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", uint8_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)uint8_node);
    fprintf(stdout, "Node Index: %ld\n\t", uint8_node->index);
    fprintf(stdout, "Node Data: %" PRIu8 "\n\t", *(uint8_t *)uint8_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)uint8_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)uint8_node->next);
}

void print_int8 (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * int8_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", int8_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)int8_node);
    fprintf(stdout, "Node Index: %ld\n\t", int8_node->index);
    fprintf(stdout, "Node Data: %" PRIi8 "\n\t", *(int8_t *)int8_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)int8_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)int8_node->next);
}

void print_uint16 (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * uint16_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", uint16_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)uint16_node);
    fprintf(stdout, "Node Index: %ld\n\t", uint16_node->index);
    fprintf(stdout, "Node Data: %" PRIu16 "\n\t", *(uint16_t *)uint16_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)uint16_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)uint16_node->next);
}

void print_int16 (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * int16_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", int16_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)int16_node);
    fprintf(stdout, "Node Index: %ld\n\t", int16_node->index);
    fprintf(stdout, "Node Data: %" PRIi16 "\n\t", *(int16_t *)int16_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)int16_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)int16_node->next);
}

void print_uint32 (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * uint32_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", uint32_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)uint32_node);
    fprintf(stdout, "Node Index: %ld\n\t", uint32_node->index);
    fprintf(stdout, "Node Data: %" PRIu32 "\n\t", *(uint32_t *)uint32_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)uint32_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)uint32_node->next);
}

void print_uint64 (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * uint64_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", uint64_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)uint64_node);
    fprintf(stdout, "Node Index: %ld\n\t", uint64_node->index);
    fprintf(stdout, "Node Data: %" PRIu64 "\n\t", *(uint64_t *)uint64_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)uint64_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)uint64_node->next);
}

void print_int64 (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * int64_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", int64_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)int64_node);
    fprintf(stdout, "Node Index: %ld\n\t", int64_node->index);
    fprintf(stdout, "Node Data: %" PRIi64 "\n\t", *(int64_t *)int64_node->data);
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)int64_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)int64_node->next);
}

void print_bool (void * data)
{
    param_check(__FILE__, __LINE__, ARG_1, data);

    node_t * bool_node = (node_t *)data;
    fprintf(stdout, "Node %ld Data: \n[\n\t", bool_node->index);
    fprintf(stdout, "Memory Address: %p\n\t", (void *)bool_node);
    fprintf(stdout, "Node Index: %ld\n\t", bool_node->index);
    fprintf(stdout, "Node Data: %s\n\t", 1 == *(bool *)bool_node->data ? "true" : "false");
    fprintf(stdout, "Previous Node Address: %p\n\t", (void *)bool_node->prev);
    fprintf(stdout, "Next Node Address: %p\n]\n", (void *)bool_node->next);
}

/*** end print_node.c ***/