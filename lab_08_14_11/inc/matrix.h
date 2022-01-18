#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdio.h>

#define ERR_DATA_TYPE -1
#define ERR_MEMORY_ALLOC -2
#define ERR_POWER -3
#define ERR_MATRIX_SIZE -4
#define ERR_ZERO_DET -5

typedef struct
{
    double **element;
    int rows;
    int columns;
} matrix_t;

int m_allocate(matrix_t *matrix);
void m_free(matrix_t *matrix);
int m_get_size(FILE *stream, matrix_t *matrix);
int m_fill(FILE *stream, matrix_t *matrix);
int m_addition(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result);
int m_multiply(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result);
int m_inverse(matrix_t *matrix, matrix_t *result);
void m_print(FILE *stream, matrix_t *matrix);

#endif // _MATRIX_H_
