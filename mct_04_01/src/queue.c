#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "queue.h"

static int stack_push(node_t **head, int data)
{
    if (head == NULL)
    {
        printf("Error: uninitialized stack.\n");

        return EXIT_FAILURE;
    }

    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
    {
        printf("Error: memory can't be allocated.\n");
        
        return EXIT_FAILURE;
    }
 
    node->data = data;
    node->next = *head;
    *head = node;

    return EXIT_SUCCESS;
}

static int stack_pop(node_t **head, int *data)
{
    if (head == NULL)
    {
        printf("Error: uninitialized stack.\n");

        return EXIT_FAILURE;
    }

    if (*head == NULL)
    {
        printf("Error: empty stack.\n");
        
        return EXIT_FAILURE;
    }

    node_t *node;
    
    node = *head;
    *data = node->data;
    *head = node->next;
    
    free(node);

    return EXIT_SUCCESS;
}

static void stack_free(node_t **head)
{
    if (head == NULL)
    {
        printf("Error: uninitialized stack.\n");

        return;
    }

    node_t *previous = NULL;

    while ((*head)->next)
    {
        previous = *head;
        *head = (*head)->next;

        free(previous);
    }

    free(*head);
}

queue_t *queue_init(void)
{
    queue_t *queue = malloc(sizeof(queue_t));

    if (!queue)
        return NULL;

    queue->stack_in = NULL;
    queue->stack_out = NULL;

    return queue;
}

int queue_push(queue_t *queue, int data)
{
    if (queue == NULL)
    {
        printf("Error: uninitialized queue.\n");

        return EXIT_FAILURE;
    }

    return stack_push(&queue->stack_in, data);
}

int queue_pop(queue_t *queue, int *data)
{
    if (queue == NULL)
    {
        printf("Error: uninitialized queue.\n");

        return EXIT_FAILURE;
    }

    if (queue->stack_in == NULL && queue->stack_out == NULL)
    {
        printf("Error: pop from empty queue.\n");

        return EXIT_FAILURE;
    }

    int rc = EXIT_FAILURE;
 
    if (queue->stack_out == NULL)
    {
        while (queue->stack_in != NULL)
        {
            rc = stack_pop(&queue->stack_in, data);

            if (rc == EXIT_FAILURE)
                return rc;

            rc = stack_push(&queue->stack_out, *data);

            if (rc == EXIT_FAILURE)
                return rc;
        }
    }
 
    rc = stack_pop(&queue->stack_out, data);

    return rc;
}

int queue_peek(queue_t *queue, int *data)
{
    if (queue == NULL)
    {
        printf("Error: uninitialized queue.\n");

        return EXIT_FAILURE;
    }

    if (queue->stack_in == NULL && queue->stack_out == NULL)
    {
        printf("Error: peek from empty queue.\n");

        return EXIT_FAILURE;
    }

    if (queue->stack_out != NULL)
    {
        *data = queue->stack_out->data;

        return EXIT_SUCCESS;
    }

    if (queue->stack_in != NULL)
    {
        node_t *current = queue->stack_in;
        node_t *next = current->next;

        while (next != NULL)
        {
            current = next;
            next = current->next;
        }

        *data = current->data;

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

/**
 * push operation for multiple elements
 */
int queue_fill(queue_t *queue, size_t elements, ...)
{
    if (queue == NULL)
    {
        printf("Error: uninitialized queue.\n");

        return EXIT_FAILURE;
    }

    int rc = EXIT_SUCCESS;

    va_list vl;
    va_start(vl, elements);

    for (size_t i = 0; i < elements; i++)
    {
        rc = stack_push(&queue->stack_in, va_arg(vl, int));

        if (rc == EXIT_FAILURE)
            break;
    }
            
    va_end(vl);
        
    return rc;
}

void queue_free(queue_t *queue)
{
    if (queue == NULL)
    {
        printf("Error: uninitialized queue.\n");

        return;
    }

    if (queue->stack_in != NULL)
    {
        stack_free(&queue->stack_in);

        queue->stack_in = NULL;
    }

    if (queue->stack_out != NULL)
    {
        stack_free(&queue->stack_out);

        queue->stack_out = NULL;
    }
}
