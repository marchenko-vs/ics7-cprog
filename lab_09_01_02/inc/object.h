#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <stdio.h>

#define INVALID_DATA -1
#define INVALID_NAME_SIZE -2

typedef struct
{
    char *name;
    double weight;
    double volume;
} object_t;

int o_init(object_t *object, char *name, double weight, double volume);
int o_copy(object_t *dst, object_t *src);
void o_free_content(object_t *object);
int o_fscan(FILE *file_name, object_t *object);
void o_print(object_t *object);
void o_swap(object_t *object_1, object_t *object_2);
int o_cmp_by_density(object_t *object_1, object_t *object_2);

#endif // _OBJECT_H_
