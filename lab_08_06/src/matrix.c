#include "matrix.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int m_allocate(matrix_t *matrix)
{
    int **ptrs = calloc(matrix->rows, sizeof(int *));

    if (!ptrs)
        return ERR_MEMORY_ALLOC;

    int *data = calloc(matrix->rows * matrix->columns, sizeof(int));

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

int m_get_size(matrix_t *matrix)
{
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

int m_fill(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->columns; j++)
            if (scanf("%d", &matrix->element[i][j]) != 1)
                return ERR_DATA_TYPE;

    return EXIT_SUCCESS;
}

void m_remove_columns(matrix_t *matrix, int number)
{
    for (size_t k = 0; k < number; k++)
    {
        size_t min_i = 0, min_j = 0;
        int min_element = matrix->element[min_i][min_j];

        for (size_t i = 0; i < matrix->rows; i++)
            for (size_t j = 0; j < matrix->columns; j++)
                if (matrix->element[i][j] <= min_element)
                {
                    min_element = matrix->element[i][j];
                    min_i = i;
                    min_j = j;
                }

        if (min_j == matrix->columns - 1)
        {
            matrix->columns--;
            continue;
        }

        for (size_t j = min_j; j < matrix->columns - 1; j++)
            for (size_t i = 0; i < matrix->rows; i++)
                matrix->element[i][j] = matrix->element[i][j + 1];

        matrix->columns--;
    }
}

void m_remove_rows(matrix_t *matrix, int number)
{
    for (size_t k = 0; k < number; k++)
    {
        size_t min_i = 0, min_j = 0;
        int min_element = matrix->element[min_i][min_j];

        for (size_t i = 0; i < matrix->rows; i++)
            for (size_t j = 0; j < matrix->columns; j++)
                if (matrix->element[i][j] <= min_element)
                {
                    min_element = matrix->element[i][j];
                    min_i = i;
                    min_j = j;
                }

        if (min_i == matrix->rows - 1)
        {
            matrix->rows--;
            continue;
        }

        for (size_t i = min_i; i < matrix->rows - 1; i++)
            for (size_t j = 0; j < matrix->columns; j++)
                matrix->element[i][j] = matrix->element[i + 1][j];

        matrix->rows--;
    }
}

void m_crop(matrix_t *matrix)
{
    int shifts = matrix->rows - matrix->columns;

    if (shifts == 0)
        return;

    if (shifts < 0)
        m_remove_columns(matrix, -shifts);

    if (shifts > 0)
        m_remove_rows(matrix, shifts);
}

void m_add_rows(matrix_t *matrix, int new_size)
{
    int **ptrs = calloc(new_size, sizeof(int *));

    int *data = calloc(new_size * matrix->columns, sizeof(int));

    for (int i = 0; i < new_size; i++)
        ptrs[i] = data + i * matrix->columns;

    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->columns; j++)
            ptrs[i][j] = matrix->element[i][j];

    m_free(matrix);

    matrix->element = ptrs;

    for (int i = 0; i < new_size; i++)
        matrix->element[i] = data + i * matrix->columns;

    for (size_t i = matrix->rows; i < new_size; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
        {
            int sr_geom = 1, n = 0;

            for (size_t k = 0; k < matrix->rows; k++)
            {
                n++;
                sr_geom *= abs(matrix->element[k][j]);
            }

            matrix->element[i][j] = floor(pow(sr_geom, 1.0 / n));
        }

        matrix->rows++;
    }
}

void m_add_columns(matrix_t *matrix, int new_size)
{
    int **ptrs = calloc(matrix->rows, sizeof(int *));

    int *data = calloc(new_size * matrix->rows, sizeof(int));

    for (int i = 0; i < matrix->rows; i++)
        ptrs[i] = data + i * new_size;

    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->columns; j++)
            ptrs[i][j] = matrix->element[i][j];

    m_free(matrix);
    
    matrix->element = ptrs;

    for (int i = 0; i < matrix->rows; i++)
        matrix->element[i] = data + i * new_size;

    for (size_t k = matrix->columns; k < new_size; k++)
    {
        for (size_t i = 0; i < matrix->rows; i++)
        {
            int min_element = matrix->element[i][0];

            for (size_t j = 0; j < matrix->columns; j++)
                if (matrix->element[i][j] < min_element)
                    min_element = matrix->element[i][j];

            matrix->element[i][matrix->columns] = min_element;
        }

        matrix->columns++;
    }
}

void m_expand(matrix_t *matrix_1, matrix_t *matrix_2)
{
    int new_size = matrix_1->rows - matrix_2->rows;

    if (new_size == 0)
        return;

    if (new_size < 0)
    {
        m_add_rows(matrix_1, matrix_2->rows);
        m_add_columns(matrix_1, matrix_2->columns);
    }

    if (new_size > 0)
    {
        m_add_rows(matrix_2, matrix_1->rows);
        m_add_columns(matrix_2, matrix_1->columns);
    }
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

int m_power(matrix_t *matrix, matrix_t *result, int power)
{
    if (power < 0)
        return EXIT_FAILURE;

    if (matrix->rows != matrix->columns)
        return EXIT_FAILURE;

    if (power == 0)
    {
        for (size_t i = 0; i < matrix->rows; i++)
            for (size_t j = 0; j < matrix->columns; j++)
            {
                if (i == j)
                    result->element[i][j] = 1;
                else
                    result->element[i][j] = 0;
            }

        return EXIT_SUCCESS;
    }

    if (power == 1)
    {
        for (size_t i = 0; i < matrix->rows; i++)
            for (size_t j = 0; j < matrix->columns; j++)
                result->element[i][j] = matrix->element[i][j];

        return EXIT_SUCCESS;
    }

    matrix_t add = { 0 };
    add.rows = matrix->rows;
    add.columns = matrix->columns;

    if (m_allocate(&add))
        return ERR_MEMORY_ALLOC;

    for (size_t i = 0; i < matrix->rows; i++)
        for (size_t j = 0; j < matrix->columns; j++)
            add.element[i][j] = matrix->element[i][j];

    for (size_t n = 0; n < power - 1; n++)
    {
        m_multiply(matrix, &add, result);

        for (size_t i = 0; i < matrix->rows; i++)
            for (size_t j = 0; j < matrix->columns; j++)
                add.element[i][j] = result->element[i][j];
    }

    m_free(&add);

    return EXIT_SUCCESS;
}

int m_get_result(matrix_t *matrix_a1, matrix_t *matrix_b1, matrix_t *result)
{
    int ro = 0, gamma = 0;

    if (scanf("%d", &ro) != 1)
        return ERR_DATA_TYPE;

    if (ro < 0)
        return ERR_POWER;

    if (scanf("%d", &gamma) != 1)
        return ERR_DATA_TYPE;

    if (gamma < 0)
        return ERR_POWER;

    matrix_t matrix_a2 = { 0 };
    matrix_a2.rows = matrix_a1->rows;
    matrix_a2.columns = matrix_a1->columns;

    if (m_allocate(&matrix_a2))
        return ERR_MEMORY_ALLOC;

    matrix_t matrix_b2 = { 0 };
    matrix_b2.rows = matrix_b1->rows;
    matrix_b2.columns = matrix_b1->columns;

    if (m_allocate(&matrix_b2))
    {
        m_free(&matrix_a2);

        return ERR_MEMORY_ALLOC;
    }

    m_power(matrix_a1, &matrix_a2, ro);
    m_power(matrix_b1, &matrix_b2, gamma);
    m_multiply(&matrix_a2, &matrix_b2, result);

    m_free(&matrix_a2);
    m_free(&matrix_b2);

    return EXIT_SUCCESS;
}

void m_print(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->rows; i++)
    {
        for (size_t j = 0; j < matrix->columns; j++)
            printf("%d ", matrix->element[i][j]);

        printf("\n");
    }
}
