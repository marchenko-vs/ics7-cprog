#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10

#define INCORRECT_DATA_TYPE -1
#define INCORRECT_SIZE -2
#define INCORRECT_ELEMENT -3
#define NO_PRIME_ELEMENTS -4

#define NON_PRIME 0
#define PRIME 1

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

    if (scanf("%i", &size) != 1)
        return INCORRECT_DATA_TYPE;

    if (MIN_SIZE > size || MAX_SIZE < size)
        return INCORRECT_SIZE;

    return size;
}

int is_prime(const int number)
{
    if (number <= 1)
        return NON_PRIME;

    for (int i = 2; number >= i * i; i++)
        if (number % i == 0)
            return NON_PRIME;

    return PRIME;
}

int prime_array(const int *init_arr, int *prime_arr, const int size)
{
    int counter = 0;

    for (int i = 0; size > i; i++)
        if (is_prime(init_arr[i]) == PRIME)
            prime_arr[counter++] = init_arr[i];

    return counter;
}

void print_array(const int *array, const int size)
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

    int user_array[MAX_SIZE];

    if (array_append(user_array, user_size) == INCORRECT_ELEMENT)
        return INCORRECT_ELEMENT;

    int result_size, result_array[MAX_SIZE];

    if (!(result_size = prime_array(user_array, result_array, user_size)))
        return NO_PRIME_ELEMENTS;

    print_array(result_array, result_size);

    return EXIT_SUCCESS;
}
