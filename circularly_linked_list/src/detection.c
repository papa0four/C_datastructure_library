#include "../include/detection.h"
#include "../include/compare_functions.h"
#include "../include/print_list.h"
#include "../include/print_node.h"
#include "../include/delete_function.h"

cll_t * det_func (cll_t * cll, uint16_t flag)
{
    param_check(__FILE__, __LINE__, ARG_1, cll);

    cll->memcmp_func  = cmp_address_t;
    cll->delete_func  = delete_node;

    switch (flag)
    {
        case (INT_T):
        {
            cll->compare_func   = cmp_int_t;
            cll->print_func     = print_list_int;
            break;
        }

        case (FLT_T):
        {
            cll->compare_func   = cmp_flt_t;
            cll->print_func     = print_list_float;
            break;
        }

        case (DBL_T):
        {
            cll->compare_func   = cmp_dbl_t;
            cll->print_func     = print_list_double;
            break;
        }

        case (STR_T):
        {
            cll->compare_func   = cmp_str_t;
            cll->print_func     = print_list_str;
            break;
        }

        case (UINT8_T):
        {
            cll->compare_func   = cmp_uint8_t;
            cll->print_func     = print_list_uint8;
            break;
        }

        case (INT8_T):
        {
            cll->compare_func   = cmp_int8_t;
            cll->print_func     = print_list_int8;
            break;
        }

        case (UINT16_T):
        {
            cll->compare_func   = cmp_uint16_t;
            cll->print_func     = print_list_uint16;
            break;
        }

        case (INT16_T):
        {
            cll->compare_func   = cmp_int16_t;
            cll->print_func     = print_list_int16;
            break;
        }

        case (UINT32_T):
        {
            cll->compare_func   = cmp_uint32_t;
            cll->print_func     = print_list_uint32;
            break;
        }

        case (UINT64_T):
        {
            cll->compare_func   = cmp_uint64_t;
            cll->print_func     = print_list_uint64;
            break;
        }

        case (INT64_T):
        {
            cll->compare_func   = cmp_int64_t;
            cll->print_func     = print_list_int64;
            break;
        }

        case (BOOL_T):
        {
            cll->compare_func   = cmp_bool_t;
            cll->print_func     = print_list_bool;
            break;
        }

        case (CUSTOM_T):
        {
            cll->compare_func   = cmp_address_t;
            cll->print_func     = print_list_custom_default;
            break;
        }

        case (USR_DEFINE_T):
        {
            cll->compare_func   = cmp_address_t;
            break;
        }

        default:
        {
            cll = NULL;
            break;
        }
    }

    return cll;
}

node_t * det_node_func (node_t * node, uint16_t flag)
{
    param_check(__FILE__, __LINE__, ARG_1, node);

    switch (flag)
    {
        case (INT_T):
        {
            node->pnode_func     = print_int;
            break;
        }

        case (FLT_T):
        {
            node->pnode_func     = print_float;
            break;
        }

        case (DBL_T):
        {
            node->pnode_func     = print_double;
            break;
        }

        case (STR_T):
        {
            node->pnode_func     = print_string;
            break;
        }

        case (UINT8_T):
        {
            node->pnode_func     = print_uint8;
            break;
        }

        case (INT8_T):
        {
            node->pnode_func     = print_int8;
            break;
        }

        case (UINT16_T):
        {
            node->pnode_func     = print_uint16;
            break;
        }

        case (INT16_T):
        {
            node->pnode_func     = print_int16;
            break;
        }

        case (UINT32_T):
        {
            node->pnode_func     = print_uint32;
            break;
        }

        case (UINT64_T):
        {
            node->pnode_func     = print_uint64;
            break;
        }

        case (INT64_T):
        {
            node->pnode_func     = print_int64;
            break;
        }

        case (BOOL_T):
        {
            node->pnode_func     = print_bool;
            break;
        }

        case (CUSTOM_T):
        {
            node->pnode_func     = print_custom_default;
            break;
        }

        case (USR_DEFINE_T):
        {
            break;
        }

        default:
        {
            node = NULL;
            break;
        }
    }

    return node;
}

/*** end detection.c ***/

