#ifndef _TEAMS_H_
#define _TEAMS_H_

#include <stdio.h>

#include "list.h"
#include "team.h"

typedef struct
{
    team_t *array;
    size_t size;
} teams_t;

void fprint_teams(FILE *stream, teams_t *teams);
void fscan_teams(FILE *stream, teams_t *teams);
int count_teams(FILE *stream, size_t *size);
void fprint_list_substring(FILE *stream, node_t *head, char *substring);
void fprint_list(FILE *stream, node_t *head);

#endif // _TEAMS_H_
