#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "team.h"
#include "teams.h"

#define ERR_ARGS_NUMBER -1
#define ERR_FILE_OPEN -2
#define ERR_INCORRECT_DATA -3
#define ERR_MEMORY_ALLOC -4

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
        return ERR_ARGS_NUMBER;

    FILE *input_file = fopen(argv[1], "r");

    if (input_file == NULL)
        return ERR_FILE_OPEN;

    teams_t teams = { NULL, 0 };

    if (count_teams(input_file, &teams.size) != EXIT_SUCCESS
        || teams.size == 0)
    {
        fclose(input_file);

        return ERR_INCORRECT_DATA;
    }

    rewind(input_file);
    teams.array = malloc(teams.size * sizeof(team_t)); 

    if (!teams.array)
    {
        fclose(input_file);

        return ERR_MEMORY_ALLOC;
    }

    fscan_teams(input_file, &teams);
    fclose(input_file);

    node_t *initial_list;
    array_to_list(&initial_list, teams.array, teams.size);

    if (argc == 2)
    {
        node_t *sorted_list;

        sorted_list = sort(initial_list, cmp_by_year);
        fprint_list(stdout, sorted_list);

        free(teams.array);
        free_list(&initial_list);

        return EXIT_SUCCESS;
    }

    if (strcmp(argv[2], "ALL") == 0)
    {
        fprint_list(stdout, initial_list);

        free(teams.array);
        free_list(&initial_list);

        return EXIT_SUCCESS;
    }

    fprint_list_substring(stdout, initial_list, argv[2]);

    free(teams.array);
    free_list(&initial_list);

    return EXIT_SUCCESS;
}
