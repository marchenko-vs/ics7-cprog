#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10

#define SUCCESS 0
#define INCORRECT_DATA_TYPE -1
#define INCORRECT_SIZE -2

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

int max_num(const int *array, const int size)
{
    int max = array[0];

    for (int i = 0; size > i; i++)
        if (array[i] > max)
            max = array[i];

    return max;
}

void swap(int *first, int *second, const int size)
{
    int temp;

    for (int i = 0; i < size; i++)
    {
        temp = first[i];
        first[i] = second[i];
        second[i] = temp;
    }
}

void bubble_sort(int (*matrix)[MAX_SIZE], const int rows, const int cols)
{
    int flag = 0;

    for (int i = 0; rows > i + 1; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {
            flag = 0;

            if (max_num(matrix[j], cols) < max_num(matrix[j + 1], cols))
            {
                swap(matrix[j], matrix[j + 1], cols);
                flag = 1;
            }
        }

        if (flag == 0)
            return;
    }
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

int main(void)
{
    int user_matrix[MAX_SIZE][MAX_SIZE], user_rows, user_cols, result;

    if ((result = create_matrix(user_matrix, &user_rows, &user_cols)) ==
        INCORRECT_SIZE)
        return INCORRECT_SIZE;

    if (result == INCORRECT_DATA_TYPE)
        return INCORRECT_DATA_TYPE;

    bubble_sort(user_matrix, user_rows, user_cols);
    print_matrix(user_matrix, user_rows, user_cols);

    return EXIT_SUCCESS;
}
