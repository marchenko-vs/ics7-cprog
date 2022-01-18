#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10

#define SHIFT 3

#define SUCCESS 0
#define INCORRECT_DATA_TYPE -1
#define INCORRECT_SIZE -2
#define NO_NEEDED_NUMS -3

int sum_of_digits(int number)
{
    if (number < 0)
        number = -number;

    int result = 0;

    while (number > 0)
    {
        result += number % 10;
        number /= 10;
    }

    return result;
}

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

int array_to_shift(int *array, int (*const matrix)[MAX_SIZE],
const int rows, const int cols)
{
    int result = 0;

    for (int i = 0; rows > i; i++)
        for (int j = 0; cols > j; j++)
            if (sum_of_digits(matrix[i][j]) > MAX_SIZE)
                array[result++] = matrix[i][j];

    return result;
}

void cyclic_shift(int *array, const int size, const int step)
{
    for (int i = 0; step > i; i++)
    {
        int temp = array[0];

        for (int j = 0; size > j; j++)
            array[j] = array[j + 1];

        array[size - 1] = temp;
    }
}

void form_matrix(const int *const array, int (*matrix)[MAX_SIZE],
const int rows, const int cols)
{
    int count = 0;

    for (int i = 0; rows > i; i++)
        for (int j = 0; cols > j; j++)
            if (sum_of_digits(matrix[i][j]) > MAX_SIZE)
                matrix[i][j] = array[count++];
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

    int user_array[MAX_SIZE * MAX_SIZE], user_size;

    if (!(user_size = array_to_shift(user_array, user_matrix, user_rows,
    user_cols)))
        return NO_NEEDED_NUMS;

    cyclic_shift(user_array, user_size, SHIFT);
    form_matrix(user_array, user_matrix, user_rows, user_cols);
    print_matrix(user_matrix, user_rows, user_cols);

    return EXIT_SUCCESS;
}
