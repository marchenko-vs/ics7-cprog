#include <stdlib.h>
#include <stdio.h>
#include "array.h"

int get_array_size(FILE *filename)
{
    int return_code = 0, buffer = 0, size = 0;

    while ((return_code = fscanf(filename, "%d", &buffer)) == 1)
        size++;

    if (return_code != EOF)
        return ERR_DATA_TYPE;

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

static double count_average(const int *begin, const int *end)
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

int key(const int *pb_src, const int src_len, int *pb_dst, int *dst_len)
{
    if (pb_src == NULL)
        return ERR_NULL_POINTER;

    if (src_len == 0)
        return ERR_ZERO_SIZE;

    double average = count_average(pb_src, pb_src + src_len);

    int size = 0;

    for (size_t i = 0; i < src_len; i++)
        if (pb_src[i] > average)
            size++;

    if (size == 0)
        return ERR_EMPTY_ARRAY;

    if (size > *dst_len)
    {
        *dst_len = size;

        return ERR_SMALL_DESTINATION_SIZE;
    }

    size_t j = 0;

    for (size_t i = 0; i < src_len; i++)
        if (pb_src[i] > average)
            pb_dst[j++] = pb_src[i];

    *dst_len = size;

    return EXIT_SUCCESS;
}
