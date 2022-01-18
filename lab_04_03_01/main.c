#include "strfuncs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LEN 257
#define WORD_LEN 16

#define EMPTY_STRING -1
#define OVERFLOW_ERROR -2
#define WORD_LEN_ERROR -3
#define NO_SOLUTION -4

int main(void)
{
    char input_str[STR_LEN], sep[] = " ,;:-.!?\n";

    if (fgets(input_str, STR_LEN, stdin) == NULL)
        return EMPTY_STRING;
	
    if (strlen(input_str) == STR_LEN - 1)
        return OVERFLOW_ERROR;

    char *word_matrix[WORD_LEN];

    int last_word = split_str(input_str, word_matrix, sep);

    if (last_word == EMPTY_STRING)
        return EMPTY_STRING;

    if (last_word == WORD_LEN_ERROR)
        return WORD_LEN_ERROR;

    char new_str[STR_LEN - 1] = "";

    form_array(new_str, word_matrix, last_word);

    if (strcmp(new_str, "") != 0)
        printf("Result:%s\n", new_str);
    else
        return NO_SOLUTION;

    return EXIT_SUCCESS;
}
