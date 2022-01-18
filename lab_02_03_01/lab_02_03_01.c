#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10
#define RES_SIZE 20

#define INCORRECT_DATA_TYPE -1
#define INCORRECT_SIZE -2
#define INCORRECT_ELEMENT -3

int fibonacci(const unsigned char number)
{
    if (number <= 1)
        return number;

    int fib_0 = 0, fib_1 = 1;
    int fib_current;

    for (int i = 2; number >= i; i++)
    {
        fib_current = fib_0 + fib_1;
        fib_0 = fib_1;
        fib_1 = fib_current;
    }

    return fib_current;
}

int insert_in_array(int *const array, int size)
{
    unsigned char fib_serial = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] % 3 != 0)
            continue;

        for (int j = size; j > i; j--)
            array[j] = array[j - 1];

        array[++i] = fibonacci(fib_serial);
        fib_serial++;
        size++;
    }

    return size;
}

int array_append(int *const array, const int size)
{
    for (int i = 0; size > i; i++)
        if (scanf("%d", &array[i]) != 1)
            return INCORRECT_ELEMENT;

    return EXIT_SUCCESS;
}

int array_size(void)
{
    int size;

    if (scanf("%d", &size) != 1)
        return INCORRECT_DATA_TYPE;

    if (MIN_SIZE > size || MAX_SIZE < size)
        return INCORRECT_SIZE;

    return size;
}

void print_array(const int *const array, const int size)
{
    for (int i = 0; size > i; i++)
        printf("%d ", array[i]);
}

int main(void)
{
    int user_size = array_size();

    if (user_size == INCORRECT_DATA_TYPE)
        return INCORRECT_DATA_TYPE;

    if (user_size == INCORRECT_SIZE)
        return INCORRECT_SIZE;

    int user_array[RES_SIZE];

    if (array_append(user_array, user_size) == INCORRECT_ELEMENT)
        return INCORRECT_ELEMENT;

    int final_size = insert_in_array(user_array, user_size);

    print_array(user_array, final_size);

    return EXIT_SUCCESS;
}
