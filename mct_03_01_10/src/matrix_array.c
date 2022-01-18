#include "matrix.h"
#include "matrix_array.h"
#include <stdlib.h>
#include <stdio.h>

int ma_allocate(matrix_array_t *array)
{
    matrix_t *ptr = calloc(array->size, sizeof(matrix_t));

    if (!ptr)
        return ERR_MEMORY_ALLOC;

    array->element = ptr;

    return EXIT_SUCCESS;
}

int ma_scan(matrix_array_t *array)
{
    for (size_t i = 0; i < array->size; i++)
    {
        if (m_allocate(&array->element[i]))
            return ERR_MEMORY_ALLOC;

        if (m_size(&array->element[i]))
            return ERR_MATRIX_SIZE;

        if (m_scan(&array->element[i]))
            return ERR_DATA_TYPE;
    }

    return EXIT_SUCCESS;
}
