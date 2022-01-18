#include "functions.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ARGS_ERROR -1
#define EMPTY_FILE -2
#define DATA_TYPE_ERROR -3

int main(int argc, char **argv)
{
    if (argc != 2)
        return ARGS_ERROR;

    FILE *input_file;

    input_file = fopen(argv[1], "r");

    if (input_file == NULL)
        return EMPTY_FILE;

    double number;

    if (fscanf(input_file, "%lf", &number) != 1)
        return DATA_TYPE_ERROR;

    double avg_value = average(input_file, &number);
    fseek(input_file, 0, SEEK_SET);
    double deviation = sqrt(variance(input_file, &avg_value));
    fseek(input_file, 0, SEEK_SET);

    if (!(rule(input_file, &avg_value, &deviation)))
        printf("0");
    else
        printf("1");

    return EXIT_SUCCESS;
}
