#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#include "object.h"
#include <stdlib.h>

void print_all_struct(FILE *file_name, object_t *object_array, size_t size);
void bubble_sort(object_t *const object_array, const size_t size);

#endif
