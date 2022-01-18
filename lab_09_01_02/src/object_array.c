#include "object.h"
#include "object_array.h"
#include <stdlib.h>

int oa_count(FILE *stream, size_t *size)
{
    object_t object = { NULL, 0, 0 };
    size_t i = 0;
    int rc = EXIT_SUCCESS;

    while (rc == EXIT_SUCCESS)
    {
        rc = o_fscan(stream, &object);

        if (rc == EXIT_SUCCESS)
        {
            i++;

            o_free_content(&object);
        }
    }

    *size = i;

    if (rc != EXIT_SUCCESS && feof(stream))
        rc = EXIT_SUCCESS;

    return rc;
}

int oa_fscan(FILE *stream, object_t *array, size_t size)
{
    int rc = EXIT_SUCCESS;

    for (size_t i = 0; rc == EXIT_SUCCESS && i < size; i++)
        rc = o_fscan(stream, array + i);

    return rc;
}


int oa_create(FILE *stream, object_t **array, size_t *size)
{
    object_t *tmp;
    size_t n = 0;
    int rc = 0;
    *array = NULL;
    *size = 0;

    rc = oa_count(stream, &n);

    if (n == 0)
        rc = EXIT_FAILURE;

    if (rc == EXIT_SUCCESS)
    {
        tmp = calloc(n, sizeof(object_t));

        if (tmp)
        {
            rewind(stream);
            rc = oa_fscan(stream, tmp, n);

            if (rc == EXIT_SUCCESS)
            {
                *array = tmp;
                *size = n;
            }
            else
                oa_free(tmp, n);
        }
        else
            rc = EXIT_FAILURE;
    }

    return rc;
}

void oa_print(object_t *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
        o_print(array + i);
}

void oa_sort(object_t *array, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = 0; j < size - i - 1; j++)
            if (o_cmp_by_density(&array[j], &array[j + 1]))
                o_swap(&array[j], &array[j + 1]);
}

void oa_free(object_t *array, size_t size)
{
    for (size_t i = 0; i < size; i++)
        o_free_content(array + i);

    free(array);
}

