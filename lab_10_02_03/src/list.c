#include <stdlib.h>
#include <stdio.h>

#include "list.h"

static int is_prime(int number)
{
    if (number <= 1)
        return 0;

    for (size_t i = 2; i < number; i++)
        if (number % i == 0)
            return 0;

    return 1;
}

static int get_length(node_t *number)
{
    if (number == NULL)
        return 0;

    int result = 0;
    node_t *current = number;

    while (current->next != NULL)
    {
        result++;
        current = current->next;
    }

    return result + 1;
}

int push_back(node_t **head, int degree)
{
    if (head == NULL)
        return ERR_NULL_POINTER;

    node_t *new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
        return ERR_MEMORY_ALLOCATION;

    node_t *last = *head;

    new_node->degree = degree;
    new_node->next = NULL;
 
    if (*head == NULL)
    {
        *head = new_node;

        return EXIT_SUCCESS;
    } 

    while (last->next != NULL)
        last = last->next;
  
    last->next = new_node;

    return EXIT_SUCCESS;   
}

node_t *decompose_number(int number)
{
    if (number < 1)
        return NULL;

    node_t *result = NULL;

    if (number == 1)
    {
        push_back(&result, 0);

        return result;
    }

    int divider = 2;

    while (number > 1)
    {
        int degree = 0;

        while (number % divider == 0)
        {
            degree++;
            number /= divider;
        }

        if (is_prime(divider))
            push_back(&result, degree);

        divider++;
    }

    return result;
}

void square_number(node_t *number)
{
    if (number == NULL)
        return;

    node_t *current = number;

    while (current->next != NULL)
    {
        current->degree *= 2;
        current = current->next;
    }

    current->degree *= 2;
}

node_t *multiply_numbers(node_t *number_1, node_t *number_2)
{
    if (number_1 == NULL || number_2 == NULL)
        return NULL;

    node_t *result = NULL;

    int length_1 = get_length(number_1);
    int length_2 = get_length(number_2);

    if (length_1 > length_2)
    {
        for (size_t i = 0; i < length_1; i++)
        {
            if (i < length_2)
            {
                push_back(&result, number_1->degree + number_2->degree);
                number_1 = number_1->next;
                number_2 = number_2->next;
            }
            else
            {
                push_back(&result, number_1->degree);
                number_1 = number_1->next;
            }
        }

        return result;
    }

    for (size_t i = 0; i < length_2; i++)
    {
        if (i < length_1)
        {
            push_back(&result, number_1->degree + number_2->degree);
            number_1 = number_1->next;
            number_2 = number_2->next;
        }
        else
        {
            push_back(&result, number_2->degree);
            number_2 = number_2->next;
        }
    }

    return result;
}

void print_list_number(node_t *head)
{
    if (head == NULL)
        return;

    node_t *current = head;

    while (current->next != NULL)
    {
        printf("%d ", current->degree);
        current = current->next;
    }

    printf("%d L\n", current->degree);
}

void free_list(node_t **head)
{
    if (head == NULL)
        return;

    if (*head == NULL)
        return;
    
    node_t *current = *head;
    node_t *next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}
