#include <stdlib.h>
#include <stdio.h>

#include "array.h"

static int fibonacci(int number)
{
    if (number < 2)
        return number;

    int number_1 = 0, number_2 = 1;
    int result = 0;

    for (size_t i = 1; i <= number; ++i)
    {
        result = number_1 + number_2;
        number_2 = number_1;
        number_1 = result;
    }
    
    return result;
}

ARRAY_DLL int ARRAY_DECL a_fill_fibonacci(int *array, size_t size)
{
    if (array == NULL)
        return ERR_NULL_POINTER;

    if (size < 1)
        return ERR_ZERO_SIZE;

    for (size_t i = 0; i < size; i++)
        array[i] = fibonacci(i);

    return EXIT_SUCCESS;
}

ARRAY_DLL int ARRAY_DECL a_rm_repetitions(int *array_src, size_t size_src, 
int *array_dst, size_t *size_dst)
{
    if (array_src == NULL)
        return ERR_NULL_POINTER;

    if (size_src == 0)
        return ERR_ZERO_SIZE;

    int *tmp = malloc(size_src * sizeof(int));

    if (!tmp)
        return ERR_MEMORY_ALLOC;

    tmp[0] = array_src[0];
    size_t unique_elements = 1;
    int flag;

    for (size_t i = 1; i < size_src; i++)
    {
        flag = 1;

        for (size_t j = 0; j < unique_elements; j++)
            if (array_src[i] == tmp[j])
            {
                flag = 0;
                break;
            }

        if (flag)
            tmp[unique_elements++] = array_src[i];
    }

    if (*size_dst < unique_elements)
    {
        *size_dst = unique_elements;
        free(tmp);

        return ERR_SRC_ARRAY_SIZE;
    }

    for (size_t i = 0; i < *size_dst; i++)
        array_dst[i] = tmp[i];

    *size_dst = unique_elements;

    free(tmp);

    return EXIT_SUCCESS;
}
