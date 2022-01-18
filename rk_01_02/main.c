/* Программа переворачивает число N задом наперед,
не используя массив. Записать новое число в новую переменную.
N = 1234 -> 4321. Можно вводить отрицательные числа*/

#include <stdio.h>
#include <stdlib.h>

int length(int num)
{
    int j = 1, number_copy = num;

    while (number_copy > 0)
    {
        j *= 10;
        number_copy /= 10;
    }
    
    j /= 10;

    return j;
}

int main(void)
{
    int sign, number, result = 0;

    printf("Enter the number:\n");

    if (scanf("%d", &number) != 1)
    {
        printf("Error: number must be an integer\n");

        return EXIT_FAILURE;
    }

    if (number < 0)
    {
        number *= -1;
        sign = 0;
    }
    else
        sign = 1;

    int k;

    k = length(number);
    
    while (number > 0)
    {
        result += number % 10 * k;
        number /= 10;
        k /= 10;
    }

    if (sign == 0)
        printf("Result is:\n%d", result * -1);
    else
        printf("Result is:\n%d", result);
    
    return EXIT_SUCCESS;
}