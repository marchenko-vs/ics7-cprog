#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

#define EPS DBL_EPSILON

double side_len(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double cross_product(double ax, double ay, double bx, double by)
{
    return ax * by - ay * bx;
}

int main()
{
    double xa, ya, xb, yb, xc, yc, xp, yp;
    int input;

    printf("Enter coordinates\n");
    input = scanf("%lf%lf%lf%lf%lf%lf%lf%lf", 
    &xa, &ya, &xb, &yb, &xc, &yc, &xp, &yp);

    if (input == 8)
    {
        double ab, bc, ca;

        ab = side_len(xa, ya, xb, yb);
        bc = side_len(xb, yb, xc, yc);
        ca = side_len(xc, yc, xa, ya);

        if ((fabs(ab + bc - ca) > EPS) && (fabs(ab + ca - bc) > EPS) 
            && (fabs(bc + ca - ab) > EPS))
        {
            double x_ab, y_ab, x_bc, y_bc, x_ca, y_ca;
            double x_ap, y_ap, x_bp, y_bp, x_cp, y_cp;
            double cp_1, cp_2, cp_3;

            x_ab = xb - xa;
            y_ab = yb - ya;
            x_ap = xp - xa;
            y_ap = yp - ya;
            cp_1 = cross_product(x_ab, y_ab, x_ap, y_ap);

            x_bc = xc - xb;
            y_bc = yc - yb;
            x_bp = xp - xb;
            y_bp = yp - yb;
            cp_2 = cross_product(x_bc, y_bc, x_bp, y_bp);


            x_ca = xa - xc;
            y_ca = ya - yc;
            x_cp = xp - xc;
            y_cp = yp - yc;
            cp_3 = cross_product(x_ca, y_ca, x_cp, y_cp);

            if (fabs(cp_1) <= EPS || fabs(cp_2) <= EPS || fabs(cp_3) <= EPS)
            {
                printf("1");
            }
            else if ((cp_1 > 0 && cp_2 > 0 && cp_3 > 0)
                || (cp_1 < 0 && cp_2 < 0 && cp_3 < 0))
            {
                printf("0");
            }
            else
            {
                printf("2");
            }
            return EXIT_SUCCESS;
        }
        else
        {
            printf("Error: triangle does not exist\n");

            return EXIT_FAILURE;
        }
    }
    else
    {
        printf("Error: input error");

        return EXIT_FAILURE;
    }
}