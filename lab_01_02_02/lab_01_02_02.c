#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    float x1, y1, x2, y2, x3, y3;
    float ab, bc, ac, p;

    printf("Enter coordinates\n");
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);

    ab = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    bc = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    ac = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    p = ab + bc + ac;

    printf("Perimeter is %7.6f", p);

    return EXIT_SUCCESS;
}