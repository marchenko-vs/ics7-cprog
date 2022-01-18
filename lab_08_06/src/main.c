#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    matrix_t matrix_a = { 0 }; // Initializing matrix A

    if (m_get_size(&matrix_a))
        return ERR_MATRIX_SIZE;

    if (m_allocate(&matrix_a))
        return ERR_MEMORY_ALLOC;

    if (m_fill(&matrix_a))
    {
        m_free(&matrix_a);

        return ERR_DATA_TYPE;
    }

    matrix_t matrix_b = { 0 }; // Initializing matrix B

    if (m_get_size(&matrix_b))
    {
        m_free(&matrix_a);

        return ERR_MATRIX_SIZE;
    }

    if (m_allocate(&matrix_b))
    {
        m_free(&matrix_a);

        return ERR_MEMORY_ALLOC;
    }

    if (m_fill(&matrix_b))
    {
        m_free(&matrix_a);
        m_free(&matrix_b);

        return ERR_DATA_TYPE;
    }

    m_crop(&matrix_a); // Removing extra rows or columns
    m_crop(&matrix_b);

    m_expand(&matrix_a, &matrix_b); // Adding extra rows and columns

    matrix_t matrix_res = { 0 };
    matrix_res.rows = matrix_a.rows;
    matrix_res.columns = matrix_a.columns;

    if (m_allocate(&matrix_res))
    {
        m_free(&matrix_a);
        m_free(&matrix_b);

        return ERR_MEMORY_ALLOC;
    }

    if (m_get_result(&matrix_a, &matrix_b, &matrix_res))
    {
        m_free(&matrix_a);
        m_free(&matrix_b);
        m_free(&matrix_res);

        return EXIT_FAILURE;
    }

    m_print(&matrix_res);

    m_free(&matrix_a);
    m_free(&matrix_b);
    m_free(&matrix_res);

    return EXIT_SUCCESS;
}
