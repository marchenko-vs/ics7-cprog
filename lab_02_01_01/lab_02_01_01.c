#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1
#define MAX_SIZE 10

#define INCORRECT_DATA_TYPE -1
#define INCORRECT_SIZE -2
#define INCORRECT_ELEMENT -3
#define NO_ODD_ELEMENTS -4

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

int odd_count(const int *array, const int size)
{
    int result = 0;

    for (int i = 0; size > i; i++)
        if (array[i] % 2 != 0)
            result++;

    if (result < 1)
        return NO_ODD_ELEMENTS;

    return result;
}

long long int odd_product(const int *array, const int size)
{
    long long int result = 1;

    for (int i = 0; size > i; i++)
        if (array[i] % 2 != 0)
            result *= array[i];

    return result;
}

int main(void)
{
    int user_size;

    user_size = array_size();

    if (user_size == INCORRECT_DATA_TYPE)
        return INCORRECT_DATA_TYPE;

    if (user_size == INCORRECT_SIZE)
        return INCORRECT_SIZE;

    int user_array[MAX_SIZE];

    if (array_append(user_array, user_size) == INCORRECT_ELEMENT)
        return INCORRECT_ELEMENT;

    if (odd_count(user_array, user_size) == NO_ODD_ELEMENTS)
        return NO_ODD_ELEMENTS;

    printf("%lld", odd_product(user_array, user_size));

    return EXIT_SUCCESS;
}
