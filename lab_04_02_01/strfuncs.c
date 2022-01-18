#include <string.h>
#include "strfuncs.h"

#define OVERFLOW_ERROR -1
#define WORD_LEN_ERROR -2

#define SEP ",;:-.!? \n"
#define EXIST 1
#define NOT_EXIST 0

int check_word(const char *word, char **matrix, const int size)
{
    for (int i = 0; i < size; i++)
        if (strcmp(word, matrix[i]) == 0)
            return EXIST;

    return NOT_EXIST;
}

int split_str(char *string, char **matrix)
{
    if ((matrix[0] = strtok(string, SEP)) == NULL)
        return WORD_LEN_ERROR;

    if (strlen(matrix[0]) > 16)
        return WORD_LEN_ERROR;

    int size = 1;

    while (1)
    {
        char *temp_word;

        if ((temp_word = strtok(NULL, SEP)) == NULL)
            break;
        else if (check_word(temp_word, matrix, size) == 0)
            matrix[size] = temp_word;
        else
            continue;

        if (strlen(matrix[size]) > 16)
            return WORD_LEN_ERROR;

        size++;
    }

    return size;
}

void bubble_sort(char **matrix, int size)
{
    if (size <= 1)
        return;

    int flag = 1;

    while (flag)
    {
        flag = 0;

        for (int i = 0; i < size - 1; i++)
        {
            if (strcmp(matrix[i], matrix[i + 1]) > 0)
            {
                char *temp = matrix[i];
                matrix[i] = matrix[i + 1];
                matrix[i + 1] = temp;
                flag = 1;
            }
        }

        size--;
    }
}
