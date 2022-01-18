#include "functions.h"
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

#define ADD_PRODUCT_ERROR 300

int main(int argc, char **argv)
{
    int flag;
    
    if ((flag = choice(argc, argv)) == INCORRECT_FLAG)
        return INCORRECT_FLAG;

    if (flag == SORT_FILE)
    {
        FILE *file_input;

        file_input = fopen(argv[2], "rb");

        if (file_input == NULL)
            return FILE_NOT_EXIST;

        FILE *file_output;

        file_output = fopen(argv[3], "w+b");

        if (file_output == NULL)
        {
            fclose(file_input);

            return FILE_NOT_EXIST;
        }

        if (main_sort(file_input, file_output) == 1)
        {
            fclose(file_input);
            fclose(file_output);

            return SORTING_ERROR;
        }

        fclose(file_input);
        fclose(file_output);

        return EXIT_SUCCESS;
    }

    if (flag == CAT_FILE)
    {
        FILE *file_input;

        file_input = fopen(argv[2], "rb");

        if (file_input == NULL)
            return FILE_NOT_EXIST;

        if (find_good(file_input, argv[3]) == 1)
        {
            fclose(file_input);

            return PRINTING_ERROR;
        }

        fclose(file_input);

        return EXIT_SUCCESS;
    }

    if (flag == CHANGE_FILE)
    {
        FILE *file_input;

        file_input = fopen(argv[2], "r+b");

        if (file_input == NULL)
        {
            file_input = fopen(argv[2], "w+b");

            if (file_input == NULL)
                return FILE_NOT_EXIST;
        }

        if (add_good(file_input) == 1)
        {
            fclose(file_input);

            return ADDING_ERROR;
        }

        fclose(file_input);

        return EXIT_SUCCESS;
    }

    return INCORRECT_FLAG;
}
