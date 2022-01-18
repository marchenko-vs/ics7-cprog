#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "matrix.h"

#define ERR_FLAGS 1
#define ERR_FILE 2

int main(int argc, char **argv)
{
    if (argc < 4 || argc > 5)
        return ERR_FLAGS;

    if (argc != 4 && strcmp(argv[1], "o") == 0)
        return ERR_FLAGS;

    FILE *in_file_1 = fopen(argv[2], "r");

    if (!in_file_1)
        return ERR_FILE;

    matrix_t matrix_1 = { 0 };

    if (m_get_size(in_file_1, &matrix_1))
    {
        fclose(in_file_1);

        return ERR_MATRIX_SIZE;
    }

    if (m_allocate(&matrix_1))
    {
        fclose(in_file_1);

        return ERR_MEMORY_ALLOC;
    }

    if (m_fill(in_file_1, &matrix_1))
    {
        m_free(&matrix_1);
        fclose(in_file_1);

        return ERR_MEMORY_ALLOC;
    }

    fclose(in_file_1);          // Первый файл закрыт

    if (strcmp(argv[1], "a") == 0 || strcmp(argv[1], "m") == 0)
    {
        FILE *in_file_2 = fopen(argv[3], "r");

        if (!in_file_2)
        {
            m_free(&matrix_1);

            return ERR_FILE;
        }

        matrix_t matrix_2 = { 0 };

        if (m_get_size(in_file_2, &matrix_2))
        {
            m_free(&matrix_1);
            fclose(in_file_2);

            return ERR_MATRIX_SIZE;
        }

        if (m_allocate(&matrix_2))
        {
            m_free(&matrix_1);
            fclose(in_file_2);

            return ERR_MEMORY_ALLOC;
        }

        if (m_fill(in_file_2, &matrix_2))
        {
            m_free(&matrix_1);
            m_free(&matrix_2);
            fclose(in_file_2);

            return ERR_MEMORY_ALLOC;
        }

        fclose(in_file_2);          // Второй файл закрыт

        FILE *res_file = fopen(argv[4], "w");

        if (!res_file)
        {
            m_free(&matrix_1);
            m_free(&matrix_2);

            return ERR_FILE;
        }

        matrix_t matrix_res = { 0 };

        if (strcmp(argv[1], "a") == 0)
        {
            matrix_res.rows = matrix_1.rows;
            matrix_res.columns = matrix_1.columns;

            if (m_allocate(&matrix_res))
            {
                m_free(&matrix_1);
                m_free(&matrix_2);
                fclose(res_file);

                return ERR_MEMORY_ALLOC;
            }

            if (m_addition(&matrix_1, &matrix_2, &matrix_res))
            {
                m_free(&matrix_1);
                m_free(&matrix_2);
                m_free(&matrix_res);
                fclose(res_file);

                return ERR_MATRIX_SIZE;
            }

            m_print(res_file, &matrix_res);

            m_free(&matrix_1);
            m_free(&matrix_2);
            m_free(&matrix_res);
            fclose(res_file);

            return EXIT_SUCCESS;
        }

        if (strcmp(argv[1], "m") == 0)
        {
            matrix_res.rows = matrix_1.rows;
            matrix_res.columns = matrix_2.columns;

            if (m_allocate(&matrix_res))
            {
                m_free(&matrix_1);
                m_free(&matrix_2);
                fclose(res_file);

                return ERR_MEMORY_ALLOC;
            }

            if (m_multiply(&matrix_1, &matrix_2, &matrix_res))
            {
                m_free(&matrix_1);
                m_free(&matrix_2);
                m_free(&matrix_res);
                fclose(res_file);

                return ERR_MATRIX_SIZE;
            }

            m_print(res_file, &matrix_res);

            m_free(&matrix_1);
            m_free(&matrix_2);
            m_free(&matrix_res);
            fclose(res_file);

            return EXIT_SUCCESS;
        }

        m_free(&matrix_1);
        m_free(&matrix_2);

        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "o") == 0)
    {
        FILE *res_file = fopen(argv[3], "w");

        if (!res_file)
        {
            m_free(&matrix_1);

            return ERR_FILE;
        }

        matrix_t matrix_res = { .rows = matrix_1.rows, 
            .columns = matrix_1.columns };

        if (m_allocate(&matrix_res))
        {
            m_free(&matrix_1);
            fclose(res_file);

            return ERR_MEMORY_ALLOC;
        }

        if (m_inverse(&matrix_1, &matrix_res))
        {
            m_free(&matrix_1);
            m_free(&matrix_res);
            fclose(res_file);

            return EXIT_FAILURE;
        }

        m_print(res_file, &matrix_res);
        m_free(&matrix_1);
        m_free(&matrix_res);
        fclose(res_file);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
