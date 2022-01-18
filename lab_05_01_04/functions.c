#include <stdio.h>
#include "functions.h"

int process(FILE *file, int *result)
{
    int left_num;

    if (fscanf(file, "%d", &left_num) != INTEGER)
        return NOT_ENOUGH_NUMBERS;

    int middle_num;

    if (fscanf(file, "%d", &middle_num) != INTEGER)
        return NOT_ENOUGH_NUMBERS;

    int right_num;

    if (fscanf(file, "%d", &right_num) != INTEGER)
        return NOT_ENOUGH_NUMBERS;

    do
    {
        if (middle_num > left_num && middle_num > right_num)
            *result += 1;

        left_num = middle_num;
        middle_num = right_num;
    }
    while (fscanf(file, "%d", &right_num) == INTEGER);

    return SUCCESS;
}
