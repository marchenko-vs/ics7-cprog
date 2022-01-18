#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 2
#define MAX_SIZE 10

#define INCORRECT_DATA_TYPE -1
#define INCORRECT_SIZE -2
#define INCORRECT_ELEMENT -3
#define NO_PRIME_ELEMENTS -4
#define EMPTY_ARRAY -54
#define MEMORY_ERORR -23

int array_append(int *const array, const int size)
{
    for (int i = 0; i < size; i++)
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

int min_product(const int *left, const int *const right)
{
    if (left == right)
        return EMPTY_ARRAY;

    if (left == NULL || right == NULL)
        return MEMORY_ERORR;

    int result = *left * *(left + 1);

    while (left < right - 1)
    {
        if (*left * *(left + 1) < result)
            result = *left * *(left + 1);

        left++;
    }

    return result;
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

    int min_prod = min_product(user_array, user_array + user_size);

    if (min_prod == MEMORY_ERORR)
        return MEMORY_ERORR;
	
    if (min_prod == EMPTY_ARRAY)
        return EMPTY_ARRAY;

    printf("%d", min_prod);

    return EXIT_SUCCESS;
}
