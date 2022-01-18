#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

#define NOT_POSITIVE_NUMBER -1

int main(int argc, char *argv[])
{
    int flag;

    if ((flag = choice(argc, argv)) == INCORRECT_FLAG)
        return INCORRECT_FLAG;

    FILE *input_file;

    if (flag == CREATE_FILE)
    {
        int num_of_numbers = atoi(argv[2]);

        if (num_of_numbers < 1)
            return NOT_POSITIVE_NUMBER;

        input_file = fopen(argv[3], "wb");

        if (generate_file(input_file, num_of_numbers) == ERROR_WHILE_WRITING)
        {
            fclose(input_file);

            return ERROR_WHILE_WRITING;
        }

        fclose(input_file);

        return EXIT_SUCCESS;
    }

    if (flag == CAT_FILE)
    {
        input_file = fopen(argv[2], "rb");

        if (input_file == NULL)
            return EMPTY_FILE_ERROR;

        if (read_file(input_file))
        {
            fclose(input_file);

            return ERROR_WHILE_READING;
        }

        fclose(input_file);

        return EXIT_SUCCESS;
    }

    if (flag == SORT_FILE)
    {
        input_file = fopen(argv[2], "r+b");

        if (input_file == NULL)
            return EMPTY_FILE_ERROR;

        if (bubble_sort(input_file))
        {
            fclose(input_file);

            return ERROR_WHILE_SORTING;
        }

        fclose(input_file);

        return EXIT_SUCCESS;
    }

    return INCORRECT_KEY;
}
