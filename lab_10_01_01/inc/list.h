#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>

#include "team.h"

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

node_t *find(node_t *head, const void *data,
int (*comparator)(const void *, const void *));
void *pop_front(node_t **head);
node_t *reverse(node_t *head);
void sorted_insert(node_t **head, node_t *element, 
int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

int push(node_t **head, void *data);
void array_to_list(node_t **head, team_t *array, size_t size);
void free_list(node_t **head);
int cmp_by_year(const void *a, const void *b);

#endif // _LIST_H_
