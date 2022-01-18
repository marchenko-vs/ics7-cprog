#include "object.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fprint_struct(FILE *file_name, object_t *object)
{
    fprintf(file_name, "%s\n", object->name);
    fprintf(file_name, "%.6lf\n", object->weight);
    fprintf(file_name, "%.6lf\n", object->volume);
}

int fscan_struct(FILE *file_name, object_t *object)
{
    char tmp_buffer[MAX_LENGTH + 3];

    if (fgets(tmp_buffer, MAX_LENGTH + 3, file_name) == NULL)
        return INVALID_DATA;

    if (strlen(tmp_buffer) > MAX_LENGTH && tmp_buffer[MAX_LENGTH] != '\n')
        return INVALID_NAME_SIZE;

    tmp_buffer[strlen(tmp_buffer) - 1] = '\0';
    strcpy(object->name, tmp_buffer);
    
    if (fscanf(file_name, "%lf\n", &object->weight) != 1)
        return INVALID_DATA;

    if (fscanf(file_name, "%lf\n", &object->volume) != 1)
        return INVALID_DATA;

    if (object->weight <= 0 || object->volume <= 0)
        return INVALID_DATA;

    return EXIT_SUCCESS;
}

int cmp_density(object_t *object_1, object_t *object_2)
{
    return object_1->weight / object_1->volume >
        object_2->weight / object_2->volume;
}
