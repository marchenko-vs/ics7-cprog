#ifndef _TEAM_H_
#define _TEAM_H_

#include <stdio.h>

#define MAX_SIZE 64

typedef struct
{
    char name[MAX_SIZE + 1];
    int year;
    int titles;
} team_t;

void fprint_team(FILE *stream, team_t *team);
int fscan_team(FILE *stream, team_t *team);

#endif // _TEAM_H_
