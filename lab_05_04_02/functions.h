#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#include <stdio.h>
#include <inttypes.h>

#define SORT_FILE 1
#define CAT_FILE 2
#define CHANGE_FILE 3

#define ADDING_ERROR -4
#define PRINTING_ERROR -3
#define FILE_NOT_EXIST -1
#define INCORRECT_FLAG 53

#define MAX 50
#define NAME_MAX 31
#define MNFCTR_MAX 16

typedef struct merchandise
{
    char name[NAME_MAX];
    char manufacturer[MNFCTR_MAX];
    uint32_t price;
    uint32_t number;
} goods;

int choice(const int size, char **arguments);
int touch_good(FILE *file_name, const int position, goods *product);
int change(FILE *file_name, const int first_pos, const int second_pos,
goods *first_good, goods *second_good);
int price_sort(FILE *file_name, const int length);
int number_sort(FILE *file_name, const int length);
int get_length(int size_of_file);
int file_size(FILE *file_name, int *const size);
int get_product_by_pos(FILE *file_input, const int position, goods *product);
int touch_file(FILE *source_file, FILE *destination_file, const int length);
int main_sort(FILE *file_input, FILE *file_output);
int cp_good(goods *product);
int receive_position(FILE *file_name, goods product, int *const position);
int scroll_further(FILE *file_name, const int start, goods product);
int add_good(FILE *file_name);
int check_string(char *const name, char *const string);
void print_good(goods product);
int find_good(FILE *file_name, char *const string);

#endif
