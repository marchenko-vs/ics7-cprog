#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10

#define SUCCESS 0
#define INCORRECT_DATA_TYPE -1
#define INCORRECT_SIZE -2
#define ONE_IN_ROW -4

#define SYMMETRIC 1
#define NON_SYMMETRIC 0

int array_append(int *array, const int size)
{
    for (int i = 0; size > i; i++)
        if (scanf("%d", &array[i]) != 1)
            return INCORRECT_DATA_TYPE;

    return SUCCESS;
}

int create_matrix(int (*matrix)[MAX_SIZE], int *rows, int *cols)
{
    if (scanf("%d", rows) != 1)
        return INCORRECT_DATA_TYPE;

    if (MIN_SIZE > *rows || MAX_SIZE < *rows)
        return INCORRECT_SIZE;

    if (scanf("%d", cols) != 1)
        return INCORRECT_DATA_TYPE;

    if (MIN_SIZE > *cols || MAX_SIZE < *cols)
        return INCORRECT_SIZE;

    for (int i = 0; *rows > i; i++)
        if (array_append(matrix[i], *cols) == INCORRECT_DATA_TYPE)
            return INCORRECT_DATA_TYPE;

    return SUCCESS;
}

int count_cols(const int *const array, const int limit, const int size)
{
    int is_symmetric = 1;

    for (int i = 0; i < limit; i++)
    {
        if (array[i] != array[size - i - 1])
        {
            is_symmetric = NON_SYMMETRIC;
            break;
        }
        else
            is_symmetric = SYMMETRIC;
    }

    return is_symmetric;
}

int symmetric_rows(int *array, int (*const matrix)[MAX_SIZE],
const int rows, const int cols)
{
    if (cols == 1)
    {
        for (int i = 0; rows > i; i++)
            printf("1 ");

        return ONE_IN_ROW;
    }

    int limit;

    if (cols % 2 != 0)
        limit = (cols - 1) / 2;
    else
        limit = cols / 2;

    for (int i = 0; rows > i; i++)
        array[i] = count_cols(matrix[i], limit, cols);

    return SUCCESS;
}

void print_array(const int *const array, const int size)
{
    for (int i = 0; size > i; i++)
        printf("%d ", array[i]);
}

int main(void)
{
    int user_matrix[MAX_SIZE][MAX_SIZE], user_rows, user_cols, result;

    if ((result = create_matrix(user_matrix, &user_rows, &user_cols)) ==
        INCORRECT_SIZE)
        return INCORRECT_SIZE;

    if (result == INCORRECT_DATA_TYPE)
        return INCORRECT_DATA_TYPE;

    int result_array[MAX_SIZE];

    if (symmetric_rows(result_array, user_matrix, user_rows, user_cols) ==
        ONE_IN_ROW)
        return EXIT_SUCCESS;

    print_array(result_array, user_rows);

    return EXIT_SUCCESS;
}
