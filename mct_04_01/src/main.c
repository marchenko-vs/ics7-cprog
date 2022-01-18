#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

/**
 * Just for a simple test
 */
int main(void)
{
    queue_t *queue = queue_init();

    if (!queue)
        return EXIT_FAILURE;

    int data, rc;

    queue_push(queue, 1);
    queue_push(queue, 2);
    queue_push(queue, 3);

    queue_fill(queue, 5, 4, 5, 6, 7, 8);
    queue_fill(queue, 2, 9, 10);

    rc = queue_peek(queue, &data);
    printf("Peek | return code: %d; data: %d\n", rc, data);
    rc = queue_peek(queue, &data);
    printf("Peek | return code: %d; data: %d\n", rc, data);

    for (size_t i = 0; i < 10; i++)
    {
        rc = queue_pop(queue, &data);
        printf("Pop | return code: %d; data: %d\n", rc, data);
    }

    queue_free(queue);
 
    return rc;
}
