#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DYNAMIC_BUILD
#include "dl_array.h"
#include "dl_sort.h"
#else
#include "array.h"
#include "sort.h"
#endif

#define ERR_KEY_NUMBER -1
#define ERR_FILE_OPEN -2
#define ERR_EMPTY_FILE -3
#define ERR_MEMORY_ALLOC -4

int compare(const void *a, const void *b);

int main(int argc, char **argv)
{
    if ((argc < 3 || argc > 4) || (argc == 4 && strcmp(argv[3], "f") != 0))
        return ERR_KEY_NUMBER;

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
        return ERR_FILE_OPEN;

    int array_size = 0;

    if ((array_size = get_array_size(input_file)) == ERR_DATA_TYPE)
    {
        fclose(input_file);

        return ERR_DATA_TYPE;
    }

    if (array_size == 0)
    {
        fclose(input_file);

        return ERR_EMPTY_FILE;
    }

    int *array_begin = NULL;

    if ((array_begin = create_array(input_file, array_size)) == NULL)
    {
        fclose(input_file);

        return ERR_MEMORY_ALLOC;
    }

    fclose(input_file);

    FILE *output_file = fopen(argv[2], "w");

    if (argc == 4)
    {
        int new_size = array_size;
        int *beg = malloc(array_size * sizeof(int));

        if (!beg)
        {
            fclose(output_file);
            free(array_begin);

            return ERR_MEMORY_ALLOC;
        }

        int rc = key(array_begin, array_size, beg, &new_size);

        if (rc == EXIT_FAILURE)
        {
            int *tmp = realloc(beg, new_size);

            if (!tmp)
                return ERR_MEMORY_ALLOC;

            beg = tmp;

            rc = key(array_begin, array_size, beg, &new_size);
        }

        if (rc != EXIT_SUCCESS)
        {
            fclose(output_file);
            free(array_begin);
            free(beg);

            return ERR_EMPTY_ARRAY;
        }

        mysort(beg, new_size, sizeof(int), &compare);
        fprint_array(output_file, beg, beg + new_size);
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

int compare(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;

    if (*(int *)a < *(int *)b)
        return -1;

    return 0;
}
