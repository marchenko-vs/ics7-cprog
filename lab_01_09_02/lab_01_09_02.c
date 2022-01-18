#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    int n = 0, input;
    float x, g = 0, el;

    do
    {
        input = scanf("%f", &x);

        if (input == 1)
        {
            if (x < 0 && n == 0)
            {
                printf("Error: input error");

                return EXIT_FAILURE;
            }
            else
            {
                if (x >= 0)
                {
                    n++;
                    el = sqrt(n + x);
                    g += el;
                }
            }
        }
        else
        {
            printf("Error: input error");

            return EXIT_FAILURE;
        }
    }
    while (x >= 0);

    g /= n;
    printf("%7.6f", g);

    return EXIT_SUCCESS;
}