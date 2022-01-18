#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "sort.h"

#define KEY_NUMBER_ERROR -1
#define FILE_OPEN_ERROR -2
#define EMPTY_FILE_ERROR -3

int main(int argc, char **argv)
{
    if ((argc < 3 || argc > 4) || (argc == 4 && strcmp(argv[3], "f") != 0))
        return KEY_NUMBER_ERROR;

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
        return FILE_OPEN_ERROR;

    int array_size = 0;

    if ((array_size = get_array_size(input_file)) == DATA_TYPE_ERROR)
    {
        fclose(input_file);

        return DATA_TYPE_ERROR;
    }

    if (array_size == 0)
    {
        fclose(input_file);

        return EMPTY_FILE_ERROR;
    }

    int *array_begin = NULL;

    if ((array_begin = create_array(input_file, array_size)) == NULL)
    {
        fclose(input_file);

        return MEMORY_ALLOC_ERROR;
    }

    fclose(input_file);

    FILE *output_file = fopen(argv[2], "w");

    if (argc == 4)
    {
        int *beg = NULL, *end = NULL;
        int rc = 0;

        rc = key(array_begin, array_begin + array_size, &beg, &end);

        if (rc != EXIT_SUCCESS)
        {
            fclose(output_file);
            free(array_begin);
            free(beg);

            return EMPTY_ARRAY_ERROR;
        }

        mysort(beg, end - beg, sizeof(int), &compare);
        fprint_array(output_file, beg, end);
        free(beg);
        free(array_begin);
        fclose(output_file);
    }
    else
    {
        mysort(array_begin, array_size, sizeof(int), &compare);
        fprint_array(output_file, array_begin, array_begin + array_size);
        free(array_begin);
        fclose(output_file);
    }

    return EXIT_SUCCESS;
}
