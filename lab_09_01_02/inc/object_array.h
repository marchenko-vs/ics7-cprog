#ifndef _OBJECT_ARRAY_H_
#define _OBJECT_ARRAY_H_

#include "object.h"
#include <stdlib.h>
#include <stdio.h>

int oa_count(FILE *stream, size_t *size);
int oa_fscan(FILE *stream, object_t *array, size_t size);
int oa_create(FILE *stream, object_t **array, size_t *size);
void oa_print(object_t *array, size_t size);
void oa_sort(object_t *array, size_t size);
void oa_free(object_t *array, size_t size);

#endif // _OBJECT_ARRAY_H_
