#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include "functions.h"

#define SORTING_ERROR -2

int change(FILE *file_name, const int first_pos, const int second_pos,
goods *first_good, goods *second_good);
int price_sort(FILE *file_name, const int length);
int number_sort(FILE *file_name, const int length);
int main_sort(FILE *file_input, FILE *file_output);

#endif