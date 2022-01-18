#include "functions.h"
#include <string.h>
#include <stdlib.h>

int choice(int size, char **arguments)
{
    if (size == 4)
    {
        if (strcmp(arguments[1], "c") == 0)
            return CREATE_FILE;

        return INCORRECT_FLAG;
    }

    if (size == 3)
    {
        if (strcmp(arguments[1], "p") == 0)
            return CAT_FILE;

        if (strcmp(arguments[1], "s") == 0)
            return SORT_FILE;
    }

    return INCORRECT_FLAG;
}

int put_number_by_pos(FILE *file_name, int *const number, const int position)
{
    fseek(file_name, sizeof(int) * position, SEEK_SET);

    if (fwrite(number, sizeof(int), 1, file_name) != 1)
        return ERROR_WHILE_WRITING;

    return SUCCESS_WRITING;
}

int generate_file(FILE *file_name, const int count)
{
    for (int i = 0; i < count; i++)
    {
        int current_number = rand();

        if (put_number_by_pos(file_name, &current_number, i) ==
            ERROR_WHILE_WRITING)
            return ERROR_WHILE_WRITING;
    }

    return SUCCESS_WRITING;
}

int get_size(FILE *file_name, int *const size)
{
    int position;

    if (fseek(file_name, 0, SEEK_END) == 1)
        return EMPTY_FILE_ERROR;

    position = ftell(file_name);

    if (position < 0)
        return EMPTY_FILE_ERROR;

    *size = position;

    return fseek(file_name, 0, SEEK_SET);
}

int get_length(int size_of_file)
{
    return size_of_file / sizeof(int);
}

int read_file(FILE *file_name)
{
    int size;

    if (get_size(file_name, &size) == EMPTY_FILE_ERROR)
        return EMPTY_FILE_ERROR;

    if (size % sizeof(int) != 0)
        return CORRUPTED_FILE;

    int length = get_length(size);
    fseek(file_name, 0, SEEK_SET);

    for (int i = 0; i < length; i++)
    {
        int position;

        if (fread(&position, sizeof(int), 1, file_name) != 1)
            return EMPTY_FILE_ERROR;

        printf("%d ", position);
    }

    return SUCCESS_READING;
}

int swap(FILE *file_name, int max_p, int min_p, int *const max_num,
int *const min_num)
{
    if (put_number_by_pos(file_name, max_num, min_p) == ERROR_WHILE_WRITING)
        return ERROR_WHILE_WRITING;

    if (put_number_by_pos(file_name, min_num, max_p) == ERROR_WHILE_WRITING)
        return ERROR_WHILE_WRITING;

    return SUCCESS_WRITING;
}

int get_number_by_pos(FILE *file_name, int *const number, const int position)
{
    fseek(file_name, position * sizeof(int), SEEK_SET);

    if (fread(number, sizeof(int), 1, file_name) != 1)
        return ERROR_WHILE_READING;

    return SUCCESS_READING;
}

int bubble_sort(FILE *file_name)
{
    int size;

    if (get_size(file_name, &size) == EMPTY_FILE_ERROR)
        return EMPTY_FILE_ERROR;

    if (size % sizeof(int) != 0)
        return CORRUPTED_FILE;

    int length = get_length(size);

    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - i - 1; j++)
        {
            int first, second;

            if (get_number_by_pos(file_name, &first, j) == ERROR_WHILE_READING)
                return ERROR_WHILE_SORTING;

            if (get_number_by_pos(file_name, &second, j + 1) ==
                ERROR_WHILE_READING)
                return ERROR_WHILE_SORTING;

            if (first > second)
                if (swap(file_name, j, j + 1, &first, &second) ==
                    ERROR_WHILE_WRITING)
                    return ERROR_WHILE_SORTING;
        }

    return SUCCESS_WRITING;
}
