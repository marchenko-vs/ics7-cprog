#include "strfuncs.h"
#include <stdio.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define OVERFLOW_ERROR -1
#define WORD_LEN_ERROR -2

#define STR_MAX 257
#define WORD_MAX 16

int main(void)
{
    char input_str[STR_MAX];

    if (fgets(input_str, STR_MAX, stdin) == NULL)
        return OVERFLOW_ERROR;

    if (strlen(input_str) == STR_MAX - 1)
        return OVERFLOW_ERROR;

    char *words_array[WORD_MAX];

    int array_size = split_str(input_str, words_array);

    if (array_size == WORD_LEN_ERROR)
        return WORD_LEN_ERROR;

    bubble_sort(words_array, array_size);

    printf("Result: ");

    for (int i = 0; i < array_size; i++)
    {
        if (i != array_size - 1)
            printf("%s ", words_array[i]);
        else
            printf("%s", words_array[i]);
    }

    return EXIT_SUCCESS;
}
