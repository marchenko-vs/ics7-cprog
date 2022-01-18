#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include "object_array.h"
#include "strfuncs.h"

#define MIN_ARGS 2
#define MAX_ARGS 3

#define ERR_FILE_OPEN -1
#define ERR_ARGS -2
#define NO_STRUCTURES_FOUND -4
#define ERR_MEMORY_ALLOC -5

int main(int argc, char **argv)
{
    if (MIN_ARGS > argc || MAX_ARGS < argc)
        return ERR_ARGS;

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
        return ERR_FILE_OPEN;

    object_t *object_array = NULL;
    size_t array_size = 0;
    
    if (oa_create(input_file, &object_array, &array_size))
    {
        oa_free(object_array, array_size);
        fclose(input_file);
        
        return EXIT_FAILURE;
    }

    fclose(input_file);

    if (array_size < 1)
        return EXIT_FAILURE;

    if (MIN_ARGS == argc)
    {
        oa_sort(object_array, array_size);
        oa_print(object_array, array_size);
        oa_free(object_array, array_size);
    
        return EXIT_SUCCESS;
    }

    if (strcmp(argv[2], "ALL") == 0)
    {
        oa_print(object_array, array_size);
        oa_free(object_array, array_size);
    
        return EXIT_SUCCESS;
    }
        
    if (strcmp(argv[2], "ALL") != 0)
    {
        for (size_t i = 0; i < array_size; i++)
            if (str_begins(object_array[i].name, argv[2]) == 0)
                o_print(&object_array[i]);

        oa_free(object_array, array_size);
    
        return EXIT_SUCCESS;
    }

    oa_free(object_array, array_size);

    return EXIT_FAILURE;
}
