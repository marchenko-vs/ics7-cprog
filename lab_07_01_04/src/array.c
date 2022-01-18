#include <stdlib.h>
#include <stdio.h>
#include "array.h"

int get_array_size(FILE *filename)
{
    int return_code = 0, buffer = 0, size = 0;

    while ((return_code = fscanf(filename, "%d", &buffer)) == 1)
        size++;

    if (return_code != EOF)
        return DATA_TYPE_ERROR;

    return size;
}

int *create_array(FILE *filename, const int size)
{
    int *pointer = malloc(size * sizeof(int));

    if (pointer == NULL)
        return NULL;

    fseek(filename, 0, SEEK_SET);

    int *additional_ptr = pointer;

    while (additional_ptr < pointer + size)
    {
        fscanf(filename, "%d", additional_ptr);

        additional_ptr++;
    }

    return pointer;
}

void fprint_array(FILE *filename, int *ptr_begin, int *ptr_end)
{
    int *ptr_current = ptr_begin;

    while (ptr_current < ptr_end - 1)
    {
        fprintf(filename, "%d ", *ptr_current);

        ptr_current++;
    }

    fprintf(filename, "%d\n", *ptr_current);
}

double count_average(const int *begin, const int *end)
{
    double result = 0;
    int size = end - begin;
    const int *current = begin;

    while (current < end)
    {
        result += *current;
        current++;
    }

    return result /= size;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL)
        return EMPTY_ARRAY_ERROR;
    
    if (pb_src == pe_src)
        return EMPTY_ARRAY_ERROR;

    double average = count_average(pb_src, pe_src);

    int size = 0;
    const int *pc_src = pb_src;

    while (pc_src < pe_src)
    {
        if (*pc_src > average)
            size++;

        pc_src++;
    }

    if (size == 0)
        return EMPTY_ARRAY_ERROR;

    *pb_dst = malloc(size * sizeof(int));

    if (*pb_dst == NULL)
        return MEMORY_ALLOC_ERROR;

    *pe_dst = *pb_dst + size;
    int *pc_dst = *pb_dst;
    pc_src = pb_src;

    while (pc_src < pe_src)
    {
        if (*pc_src > average)
        {
            *pc_dst = *pc_src;
            pc_dst++;
        }

        pc_src++;
    }

    return EXIT_SUCCESS;
}
