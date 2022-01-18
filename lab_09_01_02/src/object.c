#define _GNU_SOURCE
#include "object.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int o_init(object_t *object, char *name, double weight, double volume)
{
    char *ptr = strdup(name);

    if (ptr)
    {
        free(object->name);

        object->name = ptr;
        object->weight = weight;
        object->volume = volume;

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

int o_copy(object_t *dst, object_t *src)
{
    return o_init(dst, src->name, src->weight, src->volume);
}

void o_free_content(object_t *object)
{
    free(object->name);
    object->name = NULL;
}

int o_fscan(FILE *file_name, object_t *object)
{
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read;
    double weight;
    double volume;
    int rc = EXIT_FAILURE;

    if ((read = getline(&buffer, &len, file_name)) == -1)
    {
        free(buffer);

        return rc;
    }

    if (read)
    {
        if (fscanf(file_name, "%lf\n%lf\n", &weight, &volume) == 2)
        {
            if (weight > 0 && volume > 0)
                rc = o_init(object, buffer, weight, volume);
            else
                rc = EXIT_FAILURE;
        }
        else
            rc = EXIT_FAILURE;
    }
    else
        rc = EXIT_FAILURE;
 
    free(buffer);

    return rc;
}

void o_print(object_t *object)
{
    printf("%s", object->name);
    printf("%.6lf\n", object->weight);
    printf("%.6lf\n", object->volume);
}

void o_swap(object_t *object_1, object_t *object_2)
{
    object_t tmp = { NULL, 0, 0 };

    o_copy(&tmp, object_1);
    o_copy(object_1, object_2);
    o_copy(object_2, &tmp);

    o_free_content(&tmp);
}

int o_cmp_by_density(object_t *object_1, object_t *object_2)
{
    return object_1->weight / object_1->volume >
        object_2->weight / object_2->volume;
}
