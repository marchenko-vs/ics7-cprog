/* Программа создает новый массив, где B[i] = A[i]*A[N-i]
A = [1, 2, 3, 3, 2, 4, 5] -> [5, 8, 6,3]
A = [1, 2, 3, 4, 5, 6] -> [6, 10, 12] 
Сначала вводится размер массива, затем его элементы.
Максимальная длина массива - 10, можно изменить в define */

#include <stdio.h>
#include <stdlib.h>

#define N 10

int form_array(const int *init_array, int *res_array, int array_size)
{
    int num = 0;
    
    if (array_size % 2 == 0)
        num = array_size / 2;
    else
        num = (array_size + 1) / 2;
    
    for (int i = 0; i < num; i++)
    {
        if (i == array_size - i - 1)
            res_array[i] = init_array[i];
        else
            res_array[i] = init_array[i] * init_array[array_size - i - 1];
    }
    
    return num;
}
    
int main(void)
{
    int size, array[N];
    
    printf("Enter size of an array:\n");
    
    if (scanf("%d", &size) != 1)
    {	
        printf("Error: size must be an integer\n");
    
        return EXIT_FAILURE;
    }
    
    if (size < 1 || size > 10)
    {
        printf("Error: size must be from one to ten\n");
    
        return EXIT_FAILURE;
    }
    
    printf("Enter elements of an array:\n");
    
    for (int i = 0; i < size; i++)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            printf("Error: element must be an integer\n");
    
            return EXIT_FAILURE;
        }
    }
    
    printf("Result is\n");
    
    if (size == 1)
    {
        printf("%d", array[0]);
        
        return EXIT_SUCCESS;
    }
    
    int length, result[N];
    
    length = form_array(array, result, size);
    
    for (int i = 0; i < length; i++)
    {
        printf("%d ", result[i]);
    }
    
    return EXIT_SUCCESS;
}