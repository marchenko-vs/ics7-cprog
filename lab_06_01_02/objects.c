#include "object.h"
#include "objects.h"
#include <stdlib.h>

void print_all_struct(FILE *file_name, object_t *object_array, size_t size)
{
    for (size_t i = 0; i < size; i++)
        fprint_struct(file_name, &object_array[i]);
}

void bubble_sort(object_t *const object_array, const size_t size)
{
    object_t temporary = { 0 };

    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = 0; j < size - i - 1; j++)
            if (cmp_density(&object_array[j], &object_array[j + 1]))
            {
                temporary = object_array[j];
                object_array[j] = object_array[j + 1];
                object_array[j + 1] = temporary;
            }
}
