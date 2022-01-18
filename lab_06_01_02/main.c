#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include "objects.h"
#include "strfuncs.h"

#define MIN_ARGS 2
#define MAX_ARGS 3

#define FILE_OPEN_ERROR -1
#define ARGS_ERROR -2
#define TOO_MANY_STRUCTURES -3
#define NO_STRUCTURES_FOUND -4

#define MAX_ARRAY_SIZE 15

int main(int argc, char **argv)
{
    if (MIN_ARGS > argc || MAX_ARGS < argc)
        return ARGS_ERROR;

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
        return FILE_OPEN_ERROR;

    object_t struct_array[MAX_ARRAY_SIZE];
    size_t array_size = 0;

    while (!feof(input_file))
    {
        if (MAX_ARRAY_SIZE == array_size)
        {
            fclose(input_file);

            return TOO_MANY_STRUCTURES;
        }

        if (fscan_struct(input_file, &struct_array[array_size]) != 0)
        {
            fclose(input_file);

            return INVALID_DATA;
        }

        array_size++;
    }

    fclose(input_file);

    if (MIN_ARGS == argc)
    {
        bubble_sort(struct_array, array_size);
        print_all_struct(stdout, struct_array, array_size);

        return EXIT_SUCCESS;
    }

    if (strcmp(argv[2], "ALL") == 0)
    {
        print_all_struct(stdout, struct_array, array_size);

        return EXIT_SUCCESS;
    }
        
    if (strcmp(argv[2], "ALL") != 0)
    {
        for (size_t i = 0; i < array_size; i++)
            if (str_begins(struct_array[i].name, argv[2]) == 0)
                fprint_struct(stdout, &struct_array[i]);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
