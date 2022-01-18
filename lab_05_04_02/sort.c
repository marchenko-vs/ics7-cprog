#include "sort.h"
#include "functions.h"
#include <stdlib.h>
#include <string.h>

int change(FILE *file_name, const int first_pos, const int second_pos,
goods *first_good, goods *second_good)
{
    if (touch_good(file_name, first_pos, second_good))
        return EXIT_FAILURE;

    if (touch_good(file_name, second_pos, first_good))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int price_sort(FILE *file_name, const int length)
{
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - i - 1; j++)
        {
            goods good_1 = { 0 };
            goods good_2 = { 0 };

            if (get_product_by_pos(file_name, j, &good_1))
                return EXIT_FAILURE;

            if (get_product_by_pos(file_name, j + 1, &good_2))
                return EXIT_FAILURE;

            if (good_1.price < good_2.price)
                if (change(file_name, j, j + 1, &good_1, &good_2))
                    return EXIT_FAILURE;
        }

    return EXIT_SUCCESS;
}

int number_sort(FILE *file_name, const int length)
{
    for (int i = 0; i < length - 1; i++)
        for (int j = 0; j < length - i - 1; j++)
        {
            goods good_1 = { 0 };
            goods good_2 = { 0 };

            if (get_product_by_pos(file_name, j, &good_1))
                return EXIT_FAILURE;

            if (get_product_by_pos(file_name, j + 1, &good_2))
                return EXIT_FAILURE;

            if (good_1.number < good_2.number && good_1.price == good_2.price)
                if (change(file_name, j, j + 1, &good_1, &good_2))
                    return EXIT_FAILURE;
        }

    return EXIT_SUCCESS;
}

int main_sort(FILE *file_input, FILE *file_output)
{
    int size;

    if (file_size(file_input, &size) == 1)
        return EXIT_FAILURE;

    if (size % sizeof(goods) != 0)
        return EXIT_FAILURE;

    int length = get_length(size);

    if (length < 1)
        return EXIT_FAILURE;

    if (touch_file(file_input, file_output, length) == 1)
        return EXIT_FAILURE;

    if (price_sort(file_output, length) == 1)
        return EXIT_FAILURE;

    if (number_sort(file_output, length) == 1)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
