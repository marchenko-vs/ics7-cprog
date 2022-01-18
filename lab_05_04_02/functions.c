#include "functions.h"
#include <stdlib.h>
#include <string.h>

int choice(const int size, char **arguments)
{
    if (size == 4)
    {
        if (strcmp(arguments[1], "sb") == 0)
            return SORT_FILE;

        if (strcmp(arguments[1], "fb") == 0)
            return CAT_FILE;
    }

    if (size == CHANGE_FILE)
        if (strcmp(arguments[1], "ab") == 0)
            return CHANGE_FILE;

    return INCORRECT_FLAG;
}

int touch_good(FILE *file_name, const int position, goods *product)
{
    if (fseek(file_name, position * sizeof(goods), SEEK_SET) == 1)
        return EXIT_FAILURE;

    if (fwrite(product, sizeof(goods), 1, file_name) != 1)
        return EXIT_FAILURE;

    return fseek(file_name, 0, SEEK_SET);
}


int get_length(int size_of_file)
{
    return size_of_file / sizeof(goods);
}

int file_size(FILE *file_name, int *const size)
{
    if (fseek(file_name, 0, SEEK_END) == 1)
        return EXIT_FAILURE;

    int position = ftell(file_name);

    if (position < 0)
        return EXIT_FAILURE;

    *size = position;

    return fseek(file_name, 0, SEEK_SET);
}

int get_product_by_pos(FILE *file_input, const int position, goods *product)
{
    if (fseek(file_input, position * sizeof(goods), SEEK_SET) == 1)
        return EXIT_FAILURE;

    if (fread(product, sizeof(goods), 1, file_input) != 1)
        return EXIT_FAILURE;

    return fseek(file_input, 0, SEEK_SET);
}

int touch_file(FILE *source_file, FILE *destination_file, const int length)
{
    for (int i = 0; i < length; i++)
    {
        goods product = { 0 };

        if (get_product_by_pos(source_file, i, &product) == 1)
            return EXIT_FAILURE;

        if (touch_good(destination_file, i, &product) == 1)
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int cp_good(goods *product)
{
    char buffer[MAX];

    if (fgets(buffer, MAX, stdin) == 0)
        return EXIT_FAILURE;

    if (strlen(buffer) > NAME_MAX)
        return EXIT_FAILURE;

    if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = 0;
    else
        return EXIT_FAILURE;

    if (strlen(buffer) == 0)
        return EXIT_FAILURE;
    else
        strcpy(product->name, buffer);

    if (fgets(buffer, MAX, stdin) == 0)
        return EXIT_FAILURE;

    if (strlen(buffer) > MNFCTR_MAX)
        return EXIT_FAILURE;

    if (buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = 0;
    else
        return EXIT_FAILURE;

    if (strlen(buffer) == 0)
        return EXIT_FAILURE;
    else
        strcpy(product->manufacturer, buffer);

    if (scanf("%"SCNu32, &product->price) != 1)
        return EXIT_FAILURE;

    if (scanf("%"SCNu32, &product->number) != 1)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int receive_position(FILE *file_name, goods product, int *const position)
{
    int size;

    if (file_size(file_name, &size))
        return EXIT_FAILURE;

    if (size % sizeof(goods) != 0)
        return EXIT_FAILURE;

    if (size == 0)
        *position = 0;
    else
    {
        goods temporary = { 0 };
        int i = 0;
        int len = get_length(size);

        get_product_by_pos(file_name, i, &temporary);

        while (product.price < temporary.price && i < len)
        {
            i++;
            get_product_by_pos(file_name, i, &temporary);
        }

        while (product.number < temporary.number &&
            product.price == temporary.price && i < len)
        {
            i++;
            get_product_by_pos(file_name, i, &temporary);
        }

        *position = i;
    }

    return EXIT_SUCCESS;
}

int scroll_further(FILE *file_name, const int start, goods product)
{
    int size;

    if (file_size(file_name, &size))
        return EXIT_FAILURE;

    if (size % sizeof(goods) != 0)
        return EXIT_FAILURE;

    int end = get_length(size);

    for (int i = start; i < end; i++)
    {
        goods temporary = { 0 };

        if (get_product_by_pos(file_name, i, &temporary))
            return EXIT_FAILURE;

        if (touch_good(file_name, i, &product))
            return EXIT_FAILURE;

        product = temporary;
    }

    if (touch_good(file_name, end, &product) == 1)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int add_good(FILE *file_name)
{
    goods product = { 0 };
    int position;

    if (cp_good(&product))
        return EXIT_FAILURE;

    if (receive_position(file_name, product, &position))
        return EXIT_FAILURE;

    if (scroll_further(file_name, position, product))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int check_string(char *const name, char *const string)
{
    int len_name = strlen(name);
    int len_str = strlen(string);
    int j = 0;

    if (len_str > len_name)
        return 0;

    for (int i = len_name - len_str; name[i]; i++)
    {
        if (name[i] == string[j])
            j++;
        else
            return 0;
    }

    return 1;
}

void print_good(goods product)
{
    printf("%s\n", product.name);
    printf("%s\n", product.manufacturer);
    printf("%"PRIu32"\n", product.price);
    printf("%"PRIu32"\n", product.number);
}

int find_good(FILE *file_name, char *const string)
{
    int size, counter = 0;

    if (file_size(file_name, &size))
        return EXIT_FAILURE;

    if (size % sizeof(goods) != 0)
        return EXIT_FAILURE;

    if (strlen(string) == 0 || strlen(string) > NAME_MAX)
        return EXIT_FAILURE;

    int length = get_length(size);

    if (length <= 0)
        return EXIT_FAILURE;

    for (int i = 0; i < length; i++)
    {
        goods product = { 0 };

        if (get_product_by_pos(file_name, i, &product))
            return EXIT_FAILURE;

        if (check_string(product.name, string) == 1)
        {
            counter++;
            print_good(product);
        }
    }

    if (counter == 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
