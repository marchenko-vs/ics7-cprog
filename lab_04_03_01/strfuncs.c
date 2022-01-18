#include "strfuncs.h"
#include <string.h>

#define WORD_LEN 16

#define EMPTY_STRING -1
#define WORD_LEN_ERROR -3

int split_str(char *string, char **matrix, const char *separators)
{
    if ((matrix[0] = strtok(string, separators)) == NULL)
        return EMPTY_STRING;

    if (strlen(matrix[0]) > WORD_LEN)
        return WORD_LEN_ERROR;

    int size = 1;

    while (1)
    {
        if ((matrix[size] = strtok(NULL , separators)) == NULL)
            break;

        if (strlen(matrix[size]) > WORD_LEN)
            return WORD_LEN_ERROR;

        size++;
    }

    return size - 1;
}

void form_array(char *string, char **matrix, int first)
{
    int last = first;

    for (; first >= 0; first--)
    {
        if (strcmp(matrix[first], matrix[last]) == 0)
            continue;

        char *symbol = matrix[first];

        strcat(string, " ");

        char current_symbol[WORD_LEN + 1] = "";
        int i = 0;

        while (*symbol)
        {
            if (strchr(matrix[first], *symbol) >= symbol)
                current_symbol[i++] = *symbol;

            symbol++;
        }

        current_symbol[i] = '\0';
        strcat(string, current_symbol);
    }
}
