#ifndef _MATRIX_H_
#define _MATRIX_H_

#define ERR_DATA_TYPE -1
#define ERR_MEMORY_ALLOC -2
#define ERR_POWER -3
#define ERR_MATRIX_SIZE -4

typedef struct
{
    int **element;
    int rows;
    int columns;
} matrix_t;

int m_allocate(matrix_t *matrix);
void m_free(matrix_t *matrix);
int m_get_size(matrix_t *matrix);
int m_fill(matrix_t *matrix);
void m_remove_columns(matrix_t *matrix, int number);
void m_remove_rows(matrix_t *matrix, int number);
void m_crop(matrix_t *matrix);
void m_add_rows(matrix_t *matrix, int new_rows);
void m_add_columns(matrix_t *matrix, int new_size);
void m_expand(matrix_t *matrix_1, matrix_t *matrix_2);
int m_multiply(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result);
int m_power(matrix_t *matrix, matrix_t *result, int power);
int m_get_result(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result);
void m_print(matrix_t *matrix);

#endif // _MATRIX_H_
