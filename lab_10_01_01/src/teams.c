#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "teams.h"
#include "team.h"
#include "list.h"

void fprint_teams(FILE *stream, teams_t *teams)
{
    for (size_t i = 0; i < teams->size; i++)
        fprint_team(stream, &teams->array[i]);
}

void fscan_teams(FILE *stream, teams_t *teams)
{
    for (size_t i = 0; i < teams->size; i++)
        fscan_team(stream, &teams->array[i]);
}

int count_teams(FILE *stream, size_t *size)
{
    int rc = EXIT_SUCCESS;
    team_t tmp = { 0 };

    while (rc == EXIT_SUCCESS)
    {
        rc = fscan_team(stream, &tmp);

        if (rc == EXIT_SUCCESS)
            (*size)++;
    }

    if (rc != EXIT_SUCCESS && feof(stream))
        rc = EXIT_SUCCESS;

    return rc;
}

void fprint_list_substring(FILE *stream, node_t *head, char *substring)
{
    node_t *ptr_curr = head;
    
    while (ptr_curr)
    {
        char *curr_string = ((team_t *)(ptr_curr->data))->name;
        char *result = strstr(curr_string, substring);

        if (curr_string == result)
            fprint_team(stream, ptr_curr->data);

        ptr_curr = ptr_curr->next;
    }
}

void fprint_list(FILE *stream, node_t *head)
{
    node_t *ptr_curr = head;
    
    while (ptr_curr)
    {
        fprint_team(stream, ptr_curr->data);
        ptr_curr = ptr_curr->next;
    }
}
