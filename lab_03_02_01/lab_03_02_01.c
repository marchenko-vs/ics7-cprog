#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 2
#define MAX_SIZE 10

#define SUCCESS 0
#define INCORRECT_DATA_TYPE -1
#define INCORRECT_SIZE -2

#define BASE 10

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

void rm_columns(int (*matrix)[MAX_SIZE], const int rows, int cols,
const int index)
{
    for (int i = 0; rows > i; i++)
        for (int j = index; cols > j + 1; j++)
            matrix[i][j] = matrix[i][j + 1];
}

void rm_rows(int (*matrix)[MAX_SIZE], int rows, const int cols, const int index)
{
    for (int i = 0; cols > i; i++)
        for (int j = index; rows > j + 1; j++)
            matrix[j][i] = matrix[j + 1][i];
}

void change_matrix(int (*matrix)[MAX_SIZE], int rows, int cols,
const int row_index, const int column_index)
{
    rm_rows(matrix, rows, cols, row_index);
    rm_columns(matrix, rows, cols, column_index);
}

int sum_of_digits(int number)
{
    if (number < 0)
        number = -number;

    int result = 0;

    while (number > 0)
    {
        result += number % BASE;
        number /= BASE;
    }

    return result;
}

void element_to_remove(int (*matrix)[MAX_SIZE], int rows, int cols)
{
    int min_sum = sum_of_digits(matrix[0][0]);
    int row_index = 0, column_index = 0;

    for (int i = 0; rows > i; i++)
    {
        for (int j = 0; cols > j; j++)
        {
            if (sum_of_digits(matrix[i][j]) >= min_sum)
                continue;

            min_sum = sum_of_digits(matrix[i][j]);
            row_index = i;
            column_index = j;
        }
    }

    change_matrix(matrix, rows, cols, row_index, column_index);
}

int main(void)
{
    int user_matrix[MAX_SIZE][MAX_SIZE], user_rows, user_cols, result;

    if ((result = create_matrix(user_matrix, &user_rows, &user_cols)) ==
        INCORRECT_SIZE)
        return INCORRECT_SIZE;

    if (result == INCORRECT_DATA_TYPE)
        return INCORRECT_DATA_TYPE;

    element_to_remove(user_matrix, user_rows, user_cols);
    print_matrix(user_matrix, user_rows - 1, user_cols - 1);

    return EXIT_SUCCESS;
}
