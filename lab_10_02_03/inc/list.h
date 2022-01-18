#ifndef _LIST_H_
#define _LIST_H_

#define ERR_NULL_POINTER -1
#define ERR_MEMORY_ALLOCATION -2

typedef struct node node_t;

struct node
{
    int degree;
    node_t *next;
};

int push_back(node_t **head, int degree);
node_t *decompose_number(int number);
void square_number(node_t *head);
node_t *multiply_numbers(node_t *number_1, node_t *number_2);
void print_list_number(node_t *head);
void free_list(node_t **head);

#endif // _LIST_H_
