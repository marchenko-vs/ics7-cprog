#ifndef _MATRIX_ARRAY_H_
#define _MATRIX_ARRAY_H_

#include "matrix.h"

#define ERR_ARRAY_SIZE -1

typedef struct
{
    matrix_t *element;
    int size;
} matrix_array_t;

int ma_allocate(matrix_array_t *array);
int ma_scan(matrix_array_t *array);

#endif // _MATRIX_ARRAY_H_
