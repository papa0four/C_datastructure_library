//
// Created by jsabs on 11/19/21.
//

#include "../include/compare_functions.h"

int cmp_int_t (const void * a, const void * b)
{
    const int * ia = a;
    const int * ib = b;

    return (*ia > *ib) - (*ia < *ib);
}

int cmp_flt_t (const void * a, const void * b)
{
    const float * fa = a;
    const float * fb = b;

    return (*fa > *fb) - (*fa < *fb);
}

int cmp_uflt_t (const void * a, const void * b)
{
    const unsigned float * fa = a;
    const unsigned float * fb = b;

    return (*fa > *fb) - (*fa < *fb);
}

int cmp_dbl_t (const void * a, const void * b)
{
    const double * da = a;
    const double * db = b;

    return (*da > *db) - (*da < *db);
}

int cmp_udbl_t (const void * a, const void * b)
{
    const unsigned double * da = a;
    const unsigned double * db = b;

    return (*da > *db) - (*da < *db);
}

int cmp_str_t (const void * a, const void * b)
{
    if ((NULL == a) || (NULL == b))
    {
        errno = EINVAL;
        fprintf(stderr, "%s: must pass non-NULL strings in both positions: %s\n",
                __func__, strerror(errno));
        return -1;
    }

    const char * str1 = a;
    const char * str2 = b;

    int             m = 0;
    volatile size_t i = 0;
    volatile size_t j = 0;
    volatile size_t k = 0;

    while (1)
    {
        m |= str1[i] ^ str2[j];

        if ('\0' == str1[i])
        {
            break;
        }

        i++;

        if (str2[j] != '\0')
        {
            j++;
        }

        if ('\0' == str2[j])
        {
            k++;
        }
    }

    if (0 != m)
    {
        return -1;
    }

    return 0;
}

int cmp_uint8_t (const void * a, const void * b)
{
    const uint8_t * ui8_1 = a;
    const uint8_t * ui8_2 = b;

    return (*ui8_1 > *ui8_2) - (*ui8_1 < *ui8_2);
}

int cmp_int8_t (const void * a, const void * b)
{
    const int8_t * int8_1 = a;
    const int8_t * int8_2 = b;

    return (*int8_1 > *int8_2) - (*int8_2 < *int8_2);
}

int cmp_uint16_t (const void * a, const void * b)
{
    const uint16_t * ui16_1 = a;
    const uint16_t * ui16_2 = b;

    return (*ui16_1 > *ui16_2) - (*ui16_1 < *ui16_2);
}

int cmp_int16_t (const void * a, const void * b)
{
    const int16_t * int16_1 = a;
    const int16_t * int16_2 = b;

    return (*int16_1 > *int16_2) - (*int16_1 < *int16_2);
}

int cmp_uint32_t (const void * a, const void * b)
{
    const uint32_t * ui32_1 = a;
    const uint32_t * ui32_2 = b;

    return (*ui32_1 > *ui32_2) - (*ui32_1 < *ui32_2);
}

int cmp_uint64_t (const void * a, const void * b)
{
    const uint64_t * ui64_1 = a;
    const uint64_t * ui64_2 = b;

    return (*ui64_1 > *ui64_2) - (*ui64_1 < *ui64_2);
}

int cmp_int64_t (const void * a, const void * b)
{
    const int64_t * int64_1 = a;
    const int64_t * int64_2 = b;

    return (*int64_1 > *int64_2) - (*int64_1 < *int64_2);
}

int cmp_bool_t (const void * a, const void * b)
{
    const bool * bool1 = a;
    const bool * bool2 = b;
    if (*bool1 == *bool2)
    {
        return 0;
    }

    return -1;
}

//static int determine_cmp_func (const void * a, const void * b, int flag_t)
//{
//    int (*cmp_func_ptr) (const void *, const void *);
//    int cmp_return = -1;
//
//    switch (flag_t)
//    {
//        case INT_F:
//            cmp_func_ptr = &cmp_int_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case FLT_F:
//            cmp_func_ptr = &cmp_flt_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case DBL_F:
//            cmp_func_ptr = &cmp_dbl_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case STR_F:
//            cmp_func_ptr = &cmp_str_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case UI8_F:
//            cmp_func_ptr = &cmp_uint8_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case INT8_F:
//            cmp_func_ptr = &cmp_int8_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case UI16_F:
//            cmp_func_ptr = &cmp_uint16_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case INT16_F:
//            cmp_func_ptr = &cmp_int16_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case UI32_F:
//            cmp_func_ptr = &cmp_uint32_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case UI64_F:
//            cmp_func_ptr = &cmp_uint64_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case INT64_F:
//            cmp_func_ptr = &cmp_int64_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        case BOOL_F:
//            cmp_func_ptr = &cmp_bool_t;
//            cmp_return = cmp_func_ptr(a, b);
//            break;
//
//        default:
//            fprintf(stderr, "%s: error occurred determining compare function\n",
//                            __func__);
//            return -1;
//    }
//
//    return cmp_return;
//}

/*** end compare_functions.c ***/
