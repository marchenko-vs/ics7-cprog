#include "functions.h"

double average(FILE *file, double *current_num)
{
    int count = 1;
    double result = *current_num;

    while (fscanf(file, "%lf", current_num) == 1)
    {
        result += *current_num;
        count++;
    }

    return result / count;
}

double variance(FILE *file, double *average)
{
    double current_num, current_value;
    double result = 0;
    int count = 0;

    while (fscanf(file, "%lf", &current_num) == 1)
    {
        current_value = (current_num - *average) * (current_num - *average);
        result += current_value;
        count++;
    }

    return result / count;
}

int rule(FILE *file, double *average, double *interval)
{
    double current_num;

    while (fscanf(file, "%lf", &current_num) == 1)
        if (current_num <= *average - *interval * 3 ||
            current_num >= *average + *interval * 3)
            return FAILURE;

    return SUCCESS;
}
