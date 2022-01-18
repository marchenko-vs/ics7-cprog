#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define N 32

void answer(uint32_t a, int n)
{
    a = (a << 1) | (a >> (N - 1));
    for (int i = 0; i < N; i++)
    {
        printf("%d", a % 2);
        a = (a << 1) | (a >> (N - 1));
    }
}

int main(void)
{
    uint32_t a;
    int n, input;

    input = scanf("%u%i", &a, &n);

    if (input != 2)
    {
        printf("Error: input error");

        return EXIT_FAILURE;
    }
    else if (n < 0)
    {
        printf("Error: N must be positive or zero");

        return EXIT_FAILURE;
    }
    else
    {
        a = (a << n) | (a >> (N - n));
        printf("Result: ");
        answer(a, N);

        return EXIT_SUCCESS;
    }
}