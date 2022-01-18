#include "matrix.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int m_allocate(matrix_t *matrix)
{
    double **ptrs = calloc(matrix->rows, sizeof(double *));

    if (!ptrs)
        return ERR_MEMORY_ALLOC;

    double *data = calloc(matrix->rows * matrix->columns, sizeof(double));

    if (!data)
    {
        free(ptrs);

        return ERR_MEMORY_ALLOC;
    }

    matrix->element = ptrs;

    for (int i = 0; i < matrix->rows; i++)
        matrix->element[i] = data + i * matrix->columns;

    return EXIT_SUCCESS;
}

void m_free(matrix_t *matrix)
{
    free(matrix->element[0]);
    free(matrix->element);
}

int m_get_size(FILE *stream, matrix_t *matrix)
{
    if (fscanf(stream, "%d", &matrix->rows) != 1)
        return ERR_DATA_TYPE;

    if (matrix->rows < 1)
        return ERR_MATRIX_SIZE;

    if (fscanf(stream, "%d", &matrix->columns) != 1)
        return ERR_DATA_TYPE;

    if (matrix->columns < 1)
        return ERR_MATRIX_SIZE;

    return EXIT_SUCCESS;
}

int m_fill(FILE *stream, matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->columns; j++)
            if (fscanf(stream, "%lf", &matrix->element[i][j]) != 1)
                return ERR_DATA_TYPE;

    return EXIT_SUCCESS;
}

int m_addition(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result)
{
    if (matrix_1->rows != matrix_2->rows ||
        matrix_1->columns != matrix_2->columns)
        return ERR_MATRIX_SIZE;

    for (size_t i = 0; i < matrix_1->rows; i++)
        for (size_t j = 0; j < matrix_1->columns; j++)
            result->element[i][j] =
                matrix_1->element[i][j] + matrix_2->element[i][j];

    return EXIT_SUCCESS;
}

int m_multiply(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result)
{
    if (matrix_1->columns != matrix_2->rows)
        return ERR_MATRIX_SIZE;

    for (size_t i = 0; i < matrix_1->rows; i++)
        for (size_t j = 0; j < matrix_2->columns; j++)
        {
            result->element[i][j] = 0;

            for (size_t k = 0; k < matrix_1->columns; k++)
                result->element[i][j] += matrix_1->element[i][k] * 
                    matrix_2->element[k][j];
        }

    return EXIT_SUCCESS;
}

int m_inverse(matrix_t *matrix, matrix_t *result)
{
    if (matrix->rows != matrix->columns)
        return ERR_MATRIX_SIZE;

    size_t order = matrix->rows;
    double ratio;

    matrix_t extended = { .rows = order, .columns = order * 2 };

    if (m_allocate(&extended))
        return ERR_MEMORY_ALLOC;

    for (size_t i = 0; i < order; i++)
        for (size_t j = 0; j < order; j++)
            extended.element[i][j] = matrix->element[i][j];

    for (size_t i = 0; i < order; i++)
        for (size_t j = 0; j < order; j++)
            if (i == j)
                extended.element[i][j + order] = 1;
            else
                extended.element[i][j + order] = 0;

    for (size_t i = 0; i < order; i++)
    {
        if (extended.element[i][i] == 0.0)
        {
            m_free(&extended);

            return ERR_ZERO_DET;
        }

        for (size_t j = 0; j < order; j++)
        {
            if (i != j)
            {
                ratio = extended.element[j][i] / extended.element[i][i];

                for (size_t k = 0; k < 2 * order; k++)
                    extended.element[j][k] = extended.element[j][k] -
                        ratio * extended.element[i][k];
            }
        }
    }

    for (size_t i = 0; i < order; i++)
        for (size_t j = order; j < 2 * order; j++)
            extended.element[i][j] = extended.element[i][j] /
                extended.element[i][i];

    for (size_t i = 0; i < order; i++)
        for (size_t j = 0; j < order; j++)
            result->element[i][j] = extended.element[i][j + order];

    m_free(&extended);

    return EXIT_SUCCESS;
}

void m_print(FILE *stream, matrix_t *matrix)
{
    fprintf(stream, "%d %d\n", matrix->rows, matrix->columns);

    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
            if (j != matrix->columns - 1)
                fprintf(stream, "%.6lf ", matrix->element[i][j]);
            else
                fprintf(stream, "%.6lf\n", matrix->element[i][j]);
    }
}
