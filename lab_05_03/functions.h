#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>

#define ERROR_WHILE_SORTING -6
#define ERROR_WHILE_READING -5
#define CORRUPTED_FILE -4
#define EMPTY_FILE_ERROR -3
#define ERROR_WHILE_WRITING -2
#define INCORRECT_KEY -1
#define INCORRECT_FLAG -1
#define CREATE_FILE 1
#define CAT_FILE 2
#define SORT_FILE 3
#define SUCCESS_WRITING 0
#define SUCCESS_READING 0

int choice(int size, char **arguments);
int put_number_by_pos(FILE *file_name, int *const number, const int position);
int generate_file(FILE *file_name, const int count);
int get_size(FILE *file_name, int *const size);
int get_length(int size_of_file);
int read_file(FILE *file_name);
int swap(FILE *file_name, int max_p, int min_p, int *const max_num,
int *const min_num);
int get_number_by_pos(FILE *file_name, int *const number, const int position);
int bubble_sort(FILE *file_name);

#endif
