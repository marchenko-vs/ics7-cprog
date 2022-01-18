#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main(void)
{
    int number_1;
    char option[4];

    if (scanf("%s", option) != 1)
        return -1;

    if (strcmp(option, "out") == 0)
    {
        if (scanf("%d", &number_1) != 1)
            return -2;

        if (number_1 <= 0)
            return -3;

        node_t *list_1 = decompose_number(number_1);

        print_list_number(list_1);

        free_list(&list_1);

        return EXIT_SUCCESS;
    }

    if (strcmp(option, "mul") == 0)
    {
        int number_2;

        if (scanf("%d", &number_1) != 1)
            return -2;

        if (number_1 <= 0)
            return -3;

        if (scanf("%d", &number_2) != 1)
            return -2;

        if (number_2 <= 0)
            return -3;

        node_t *list_1 = decompose_number(number_1);
        node_t *list_2 = decompose_number(number_2);

        node_t *list_result = multiply_numbers(list_1, list_2);
        print_list_number(list_result);

        free_list(&list_1);
        free_list(&list_2);
        free_list(&list_result);

        return EXIT_SUCCESS;
    }

    if (strcmp(option, "sqr") == 0)
    {
        if (scanf("%d", &number_1) != 1)
            return -2;

        if (number_1 <= 0)
            return -3;

        node_t *list_1 = decompose_number(number_1);
        square_number(list_1);

        print_list_number(list_1);

        free_list(&list_1);

        return EXIT_SUCCESS;
    }

    if (strcmp(option, "div") == 0)
    {
        int number_2;

        if (scanf("%d", &number_1) != 1)
            return -2;

        if (number_1 <= 0)
            return -3;

        if (scanf("%d", &number_2) != 1)
            return -2;

        if (number_2 <= 0)
            return -3;

        int result = number_1 / number_2;

        if (result == 0)
            return EXIT_FAILURE;

        node_t *list_result = decompose_number(result);

        print_list_number(list_result);

        free_list(&list_result);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
