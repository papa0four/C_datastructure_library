//
// Created by jsabs on 11/29/21.
//

#include "../include/compare_functions.h"
#include "../include/queue.h"

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

int cmp_dbl_t (const void * a, const void * b)
{
    const double * da = a;
    const double * db = b;

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

    return (*int8_1 > *int8_2) - (*int8_1 < *int8_2);
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

int cmp_address_t (const void * a, const void * b)
{
    const qnode_t * node_a = a;
    const qnode_t * node_b = b;

    if (node_a->data == node_b->data)
    {
        return 0;
    }

    return -1;
}

/*** end compare_functions.c ***/
