#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>

void m_free(matrix_t *matrix)
{
    free(matrix->element[0]);
    free(matrix->element);
}

int m_allocate(matrix_t *matrix)
{
    double **ptrs = calloc(matrix->rows, sizeof(double *));

    if (!ptrs)
        return ERR_MEMORY_ALLOC;

    double *data = calloc(matrix->columns * matrix->rows, sizeof(double));

    if (!data)
    {
        free(ptrs);

        return ERR_MEMORY_ALLOC;
    }

    matrix->element = ptrs;

    for (size_t i = 0; i < matrix->rows; i++)
        matrix->element[i] = data + i * matrix->columns;

    return EXIT_SUCCESS;
}

int m_size(matrix_t *matrix)
{
    printf("Введите размеры матрицы:\n");

    if (scanf("%d", &matrix->rows) != 1)
        return ERR_DATA_TYPE;

    if (matrix->rows < 1)
        return ERR_MATRIX_SIZE;

    if (scanf("%d", &matrix->columns) != 1)
        return ERR_DATA_TYPE;

    if (matrix->columns < 1)
        return ERR_MATRIX_SIZE;

    return EXIT_SUCCESS;
}

int m_scan(matrix_t *matrix)
{
    printf("Введите элементы матрицы:\n");

    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->columns; j++)
            if (scanf("%lf", &matrix->element[i][j]) != 1)
                return ERR_DATA_TYPE;

    return EXIT_SUCCESS;
}

void m_print(matrix_t *matrix)
{
    printf("Матрица:\n");

    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
            printf("%lf ", matrix->element[i][j]);

        printf("\n");
    }
}
