#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

#define EMPTY_ARRAY -1
#define OVERFLOW 100

void insertion_sort(int *const array, const int size)
{
    int i, j, key;

    for (i = 1; size > i; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void print_array(const int *const array, const int size)
{
    for (int i = 0; size > i; i++)
        printf("%d ", array[i]);
}

int main(void)
{
    int user_array[MAX_SIZE], flag, i = 0;
    
    while ((flag = scanf("%d", &user_array[i]) == 1) && (MAX_SIZE > i))
        i++;
    
    if (i == 0)
        return EMPTY_ARRAY;
    
    insertion_sort(user_array, i);
    print_array(user_array, i);

    if ((MAX_SIZE <= i) && (flag == 1))
        return OVERFLOW;

    return EXIT_SUCCESS;
}
