#include "matrix.h"
#include "matrix_array.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    setbuf(stdout, NULL);

    int array_size = 0;

    printf("Введите кол-во матриц: ");

    if (scanf("%d", &array_size) != 1)
        return ERR_DATA_TYPE;

    if (array_size < 1)
        return ERR_ARRAY_SIZE;

    matrix_t *main_array = calloc(array_size, sizeof(matrix_t));

    if (!main_array)
        return ERR_MEMORY_ALLOC;

    for (size_t i = 0; i < array_size; i++)
    {
        if (m_allocate(&main_array[i]))
            return ERR_MEMORY_ALLOC;

        if (m_size(&main_array[i]))
            return ERR_MATRIX_SIZE;

        if (m_scan(&main_array[i]))
            return ERR_DATA_TYPE;
    }

    return EXIT_SUCCESS;
}
