#include <stdio.h>
#include "functions.h"

int main(void)
{
    int result = 0, exit_code;

    exit_code = process(stdin, &result);

    if (exit_code == NOT_ENOUGH_NUMBERS)
        return NOT_ENOUGH_NUMBERS;

    fprintf(stdout, "%d", result);

    return SUCCESS;
}
