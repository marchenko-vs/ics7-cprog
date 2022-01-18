#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct node node_t;

struct node
{
    int data;
    node_t *next;
};

typedef struct
{
    node_t *stack_in;
    node_t *stack_out;
} queue_t;

queue_t *queue_init(void);
int queue_push(queue_t *queue, int data);
int queue_pop(queue_t *queue, int *data);
int queue_peek(queue_t *queue, int *data);
int queue_fill(queue_t *queue, size_t elements, ...);
void queue_free(queue_t *queue);

#endif // _QUEUE_H_
