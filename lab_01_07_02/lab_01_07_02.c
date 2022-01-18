#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double function(double x, double eps)
{
    double frac_up, frac_down, frac;
    double result = 0;
    int i = 1;

    frac_up = x;
    frac_down = 1.0;
    frac = frac_up / frac_down;

    while (fabs(frac) > eps)
    {
        result += frac;
        frac_up *= x * x * i;
        frac_down = frac_down / (double) i;
        i += 1;
        frac_down *= i;
        i += 1;
        frac_down *= i;
        frac = frac_up / frac_down;
    }

    return result;
}

int main()
{
    double x, eps;
    double s, f;
    double delta, beta;

    printf("Enter X and EPS\n");

    if (scanf("%lf%lf", &x, &eps) != 2)
    {
        printf("Error: input error");

        return EXIT_FAILURE;
    }

    if ((eps > 1 || eps <= 0) || (x < -1 || x > 1))
    {
        printf("Error: x or eps are incorrect");

        return EXIT_FAILURE;
    }

    s = function(x, eps);
    f = asin(x);
    delta = fabs(f - s);
    beta = delta / fabs(f);
    printf("s is %.6lf\n", s);
    printf("f is %.6lf\n", f);
    printf("delta is %.6lf\n", delta);
    printf("beta is %.6lf\n", beta);

    return EXIT_SUCCESS;
}
