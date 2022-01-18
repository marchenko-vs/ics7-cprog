#ifndef _FUNCS_H_
#define _FUNCS_H_

#include <stdio.h>

#define FILE_NOT_EXIST -1
#define EMPTY_STRING -2
#define LENGTH_ERROR -3

#define WORD_LEN 11
#define STR_LEN 66

int split_str(FILE *file_name, char *matrix[WORD_LEN], char *string);
void reverse(FILE *file_name, const char *string);

#endif
