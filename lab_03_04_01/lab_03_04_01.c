#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10

#define SUCCESS 0
#define INCORRECT_DATA_TYPE -1
#define INCORRECT_SIZE -2

#define NOT_SQUARE 1
#define SQUARE 0

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

    if (*rows != *cols)
        return NOT_SQUARE;

    for (int i = 0; *rows > i; i++)
        if (array_append(matrix[i], *cols) == INCORRECT_DATA_TYPE)
            return INCORRECT_DATA_TYPE;

    return SUCCESS;
}

void print_matrix(int (*const matrix)[MAX_SIZE], const int rows,
const int cols)
{
    for (int i = 0; rows > i; i++)
    {
        for (int j = 0; cols > j; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

void change_matrix(int (*matrix)[MAX_SIZE], const int size)
{
    int limit = (size + 1) / 2;
    int n = 0;

    for (int i = 0; limit > i; i++)
    {
        for (int j = n; size > j + n; j++)
        {
            int k = matrix[i][j];
            matrix[i][j] = matrix[size - n - 1][j];
            matrix[size - n - 1][j] = k;
        }

        n++;
    }
}

int main(void)
{
    int user_matrix[MAX_SIZE][MAX_SIZE], user_rows, user_cols, result;

    if ((result = create_matrix(user_matrix, &user_rows, &user_cols)) ==
        INCORRECT_SIZE)
        return INCORRECT_SIZE;

    if (result == INCORRECT_DATA_TYPE)
        return INCORRECT_DATA_TYPE;

    if (result == NOT_SQUARE)
        return NOT_SQUARE;

    change_matrix(user_matrix, user_rows);
    print_matrix(user_matrix, user_rows, user_cols);

    return EXIT_SUCCESS;
}
