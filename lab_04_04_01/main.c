#include <stdio.h>
#include "strfuncs.h"

#define STR_MAX 257

#define EXIT_SUCCESS 0
#define OVERFLOW_ERROR -2

int main(void)
{
    char number[STR_MAX];

    fgets(number, STR_MAX, stdin);

    short int length = strlen(number);

    if (length == STR_MAX - 1)
        return OVERFLOW_ERROR;

    if (function(number, length) == EXIT_SUCCESS)
        printf("YES");
    else
        printf("NO");

    return EXIT_SUCCESS;
}
