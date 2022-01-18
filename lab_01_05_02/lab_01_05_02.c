#include <stdio.h>
#include <stdlib.h>

int fibonacci(int i)
{
    int j = 2, fib_0 = 0, fib_1 = 1, fib_2;

    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    else
    {
        while (j <= i)
        {
            fib_2 = fib_1 + fib_0;
            fib_0 = fib_1;
            fib_1 = fib_2;
            j++;
        }
    }
    return fib_2;
}

int main(void)
{
    int n, input, fib_n;

    printf("Enter N\n");
    input = scanf("%i", &n);

    if (input == 1)
    {
        if (n < 0)
        {
            printf("Error: n must me more than minus one");

            return EXIT_FAILURE;
        }
        else if (n > 48)
        {
            printf("Error: fibonacci number is too big");

            return EXIT_FAILURE;
        }
        else
        {
            fib_n = fibonacci(n);
            printf("Fib[n] is %i", fib_n);

            return EXIT_SUCCESS;
        }
    }
    else
    {
        printf("Error: input error");

        return EXIT_FAILURE;
    }
}