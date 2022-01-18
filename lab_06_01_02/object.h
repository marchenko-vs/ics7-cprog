#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <stdio.h>

#define MAX_LENGTH 25

#define INVALID_DATA -1
#define INVALID_NAME_SIZE -2

typedef struct
{
    char name[MAX_LENGTH + 1];
    double weight;
    double volume;
} object_t;

void fprint_struct(FILE *file_name, object_t *object);
int fscan_struct(FILE *file_name, object_t *object);
int cmp_density(object_t *object_1, object_t *object_2);

#endif
