#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "team.h"

node_t *find(node_t *head, const void *data, 
int (*comparator)(const void *, const void *))
{
    if (head == NULL)
        return NULL;

    if (data == NULL)
        return NULL;

    if (comparator == NULL)
        return NULL;

    node_t *ptr_curr = head;

    while (ptr_curr)
    {
        if (comparator(ptr_curr->data, data) == 0)
            return ptr_curr;

        ptr_curr = ptr_curr->next;
    }

    return NULL;
}

void *pop_front(node_t **head)
{
    if (head == NULL)
        return NULL;

    if (*head == NULL)
        return NULL;

    node_t *prev = *head;
    void *pointer = prev->data;
    *head = (*head)->next;

    free(prev);

    return pointer;
}

node_t *reverse(node_t *head)
{
    if (head == NULL)
        return NULL;

    node_t *new_head = head;
    node_t *buff = NULL;
    node_t *current = new_head;

    while (current != NULL)
    {
        node_t *temp = current->next;
        current->next = buff;
        buff = current;
        current = temp;
    }   

    new_head = buff;

    return new_head;
}

void sorted_insert(node_t **head, node_t *element, 
int (*comparator)(const void *, const void *))
{
    if (head == NULL)
        return;

    if (element == NULL)
        return;

    if (comparator == NULL)
        return;

    node_t *current;

    if (*head == NULL || comparator((*head)->data, element->data) >= 0)
    {
        element->next = *head;
        *head = element;

        return;
    }

    current = *head;

    while (current->next != NULL && 
        comparator(current->next->data, element->data) < 0)
        current = current->next;

    element->next = current->next;
    current->next = element;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head == NULL)
        return NULL;

    if (comparator == NULL)
        return NULL;

    node_t *sorted = head;
    node_t *preaktual = head; 
    node_t *pom;
    node_t *pom1;
   
    while (preaktual->next != NULL)
    {
        pom = sorted;

        while (preaktual->next != NULL && pom != preaktual->next &&
            comparator(pom->data, preaktual->next->data) <= 0)
            pom = pom->next;
       
        if (preaktual->next != pom)
        { 
            pom1 = preaktual->next;
            preaktual->next = preaktual->next->next;
            sorted_insert(&sorted, pom1, comparator);  
        }
        else
            preaktual = preaktual->next;
    }

    return sorted;
}

void array_to_list(node_t **head, team_t *array, size_t size)
{
    size_t i = size - 1;

    if (array == NULL || size == 0)
        return;

    do
    {
        push(head, &array[i]);
    }
    while (i-- != 0);
}

int push(node_t **head, void *data)
{
    node_t *tmp = malloc(sizeof(node_t));

    if (!tmp)
        return -1;

    tmp->data = data;
    tmp->next = (*head);
    *head = tmp;

    return EXIT_SUCCESS;
}

void free_list(node_t **head)
{
    if (head == NULL)
        return;

    if (*head == NULL)
        return;

    node_t *curr_ptr = *head;
    node_t *temp;

    while (curr_ptr)
    {
        temp = curr_ptr;
        curr_ptr = curr_ptr->next;

        pop_front(&temp);
    }

    *head = NULL;
}

int cmp_by_year(const void *a, const void *b)
{
    if (((team_t *)a)->year < ((team_t *)b)->year)
        return -1;

    if (((team_t *)a)->year > ((team_t *)b)->year)
        return 1;

    return 0;
}
