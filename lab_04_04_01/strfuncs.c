#include "strfuncs.h"

#define DIGITS "0123456789"
#define ALL_SYMBOLS "0123456789eE+-."

#define EXIT_SUCCESS 0
#define FAIL -1

int function(char *string, const int size)
{
    short int i = 0;

    while (string[i] == ' ' || string[i] == '\t')
        i++;

    for (int j = i; j < size - 1; j++)
        if (strchr(ALL_SYMBOLS, string[j]) == NULL &&
            strchr(ALL_SYMBOLS, string[j + 1]) != NULL)
            return FAIL;

    int find_group_1 = 0;
    int find_group_2 = 0;

    if (string[i] == '+' || string[i] == '-')
    {
        i++;
        find_group_1 = 1;
    }

    if (strchr(DIGITS, string[i]) != NULL)
        find_group_1 = 1;

    if (string[i] == '.' && string[i + 1] != '.')
    {
        find_group_1 = 1;
        i++;
    }

    if (string[i + 1] == '.' && string[i + 2] == ' ')
        return EXIT_SUCCESS;

    if (find_group_1 == 0)
        return FAIL;

    if (strchr(DIGITS, string[i]) != NULL)
    {
        while (strchr(DIGITS, string[i]) != NULL)
            i++;

        if (string[i] == '.' && (string[i + 1] == 'e' || string[i + 1] == 'E'))
            i++;

        if (string[i] == 'e' || string[i] == 'E' ||
            (strchr("\n\t ", string[i]) || string[i] == '\0'))
            find_group_2 = 1;

        if (string[i] == '.' && strchr(DIGITS, string[i + 1]) != NULL)
        {
            while (strchr(DIGITS, string[i + 1]) != NULL)
                i++;

            i++;

            if (string[i] == 'e' || string[i] == 'E' ||
                (strchr("\n\t ", string[i]) || string[i] == '\0'))
                find_group_2 = 1;
        }

        if (string[i] == '.' && (string[i + 1] == 'e' || string[i + 1] == 'E' ||
            (strchr("\n\t ", string[i]) || string[i] == '\0')))
            find_group_2 = 1;
    }

    if (string[i] == '.' &&
        (strchr(DIGITS, string[i + 1]) != NULL || string[i + 1] == 'e' ||
        string[i + 1] == 'E'))
    {
        while (strchr(DIGITS, string[i + 1]) != NULL)
            i++;

        i++;

        if (string[i] == 'e' || string[i] == 'E' ||
            (strchr("\n\t ", string[i]) || string[i] == '\0'))
            find_group_2 = 1;
    }

    if (find_group_2 == 0)
        return FAIL;

    if (strchr("\n\t ", string[i]) || string[i] == '\0')
        return EXIT_SUCCESS;

    if (string[i] == 'e' || string[i] == 'E')
    {
        i++;

        if ((string[i] == '+' || string[i] == '-') &&
            strchr(DIGITS, string[i + 1]) != NULL)
        {
            while (strchr(DIGITS, string[i + 1]) != NULL)
                i++;

            i++;

            if (strchr("\n\t ", string[i]) || string[i] == '\0')
                return EXIT_SUCCESS;
        }

        if (strchr(DIGITS, string[i]) != NULL)
        {
            while (strchr(DIGITS, string[i]) != NULL)
                i++;

            if (strchr("\n\t ", string[i]) || string[i] == '\0')
                return EXIT_SUCCESS;
        }
    }

    if (string[i] == '\0')
        return EXIT_SUCCESS;

    return FAIL;
}
