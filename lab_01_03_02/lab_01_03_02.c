#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float r1, r2, r3, r_total;

    printf("Enter three resistance values\n");
    scanf("%f %f %f", &r1, &r2, &r3);

    r_total = 1 / (1 / r1 + 1 / r2 + 1 / r3);
    printf("Total resistance is %7.6f", r_total);

    return EXIT_SUCCESS;
}