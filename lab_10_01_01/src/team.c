#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "team.h"

void fprint_team(FILE *stream, team_t *team)
{
    fprintf(stream, "%s\n", team->name);
    fprintf(stream, "%d\n", team->year);
    fprintf(stream, "%d\n", team->titles);
}

int fscan_team(FILE *stream, team_t *team)
{
    char tmp_buffer[MAX_SIZE + 1];

    if (fgets(tmp_buffer, MAX_SIZE + 1, stream) == NULL)
        return -1;

    int name_size = strlen(tmp_buffer);

    if (name_size == MAX_SIZE + 1 && tmp_buffer[name_size - 1] != '\n')
        return -2;

    if (tmp_buffer[0] == '\n')
        return -2;

    tmp_buffer[name_size - 1] = '\0';

    strcpy(team->name, tmp_buffer);

    if (fscanf(stream, "%d\n", &team->year) != 1)
        return -3;

    if (team->year < 1950 || team->year > 2022)
        return -4;

    if (fscanf(stream, "%d\n", &team->titles) != 1)
        return -5;

    if (team->titles < 0)
        return -6;

    return EXIT_SUCCESS;
}
