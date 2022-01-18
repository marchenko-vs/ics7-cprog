#ifndef _MATRIX_H_
#define _MATRIX_H_

#define ERR_MEMORY_ALLOC -1
#define ERR_DATA_TYPE -2
#define ERR_MATRIX_SIZE -3

typedef struct
{
    double **element;
    int rows;
    int columns;
} matrix_t;

void m_free(matrix_t *matrix);
int m_allocate(matrix_t *matrix);
int m_size(matrix_t *matrix);
int m_scan(matrix_t *matrix);
void m_print(matrix_t *matrix);

#endif // _MATRIX_H_
