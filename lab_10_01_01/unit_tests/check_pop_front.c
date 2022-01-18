#include <check.h>
#include <string.h>

#include "list.h"
#include "team.h"
#include "teams.h"

START_TEST(test_pop_front_null_pointer)
{
    teams_t teams;
    teams.size = 3;
    teams.array = malloc(teams.size * sizeof(team_t));

    char team_1[] = "Ferrari";
    char team_2[] = "McLaren";
    char team_3[] = "Jaguar";

    strcpy(teams.array[0].name, team_1);
    teams.array[0].year = 1950;
    teams.array[0].titles = 16;

    strcpy(teams.array[0].name, team_2);
    teams.array[1].year = 1963;
    teams.array[1].titles = 8;

    strcpy(teams.array[0].name, team_3);
    teams.array[2].year = 1981;
    teams.array[2].titles = 0;

    node_t *head = NULL;

    array_to_list(&head, teams.array, teams.size);
    void *result = pop_front(NULL);

    ck_assert_ptr_eq(result, NULL);

    free(teams.array);
    free_list(&head);
}
END_TEST

START_TEST(test_pop_front_uninitialized_list)
{
    teams_t teams;
    teams.size = 3;
    teams.array = malloc(teams.size * sizeof(team_t));

    char team_1[] = "Ferrari";
    char team_2[] = "McLaren";
    char team_3[] = "Jaguar";

    strcpy(teams.array[0].name, team_1);
    teams.array[0].year = 1950;
    teams.array[0].titles = 16;

    strcpy(teams.array[0].name, team_2);
    teams.array[1].year = 1963;
    teams.array[1].titles = 8;

    strcpy(teams.array[0].name, team_3);
    teams.array[2].year = 1981;
    teams.array[2].titles = 0;

    node_t *head = NULL;

    array_to_list(&head, teams.array, teams.size);
    node_t *new_head = NULL;
    void *result = pop_front(&new_head);
    
    ck_assert_ptr_eq(result, NULL);

    free(teams.array);
    free_list(&head);
    free_list(&new_head);
}
END_TEST

START_TEST(test_pop_front_default)
{
    teams_t teams;
    teams.size = 3;
    teams.array = malloc(teams.size * sizeof(team_t));

    char team_1[] = "Ferrari";
    char team_2[] = "McLaren";
    char team_3[] = "Jaguar";

    strcpy(teams.array[0].name, team_1);
    teams.array[0].year = 1950;
    teams.array[0].titles = 16;

    strcpy(teams.array[0].name, team_2);
    teams.array[1].year = 1963;
    teams.array[1].titles = 8;

    strcpy(teams.array[0].name, team_3);
    teams.array[2].year = 1981;
    teams.array[2].titles = 0;

    node_t *head = NULL;

    array_to_list(&head, teams.array, teams.size);
    void *result = pop_front(&head);
    
    ck_assert_ptr_eq(result, &teams.array[0]);

    free(teams.array);
    free_list(&head);
}
END_TEST

START_TEST(test_pop_front_one_element)
{
    teams_t teams;
    teams.size = 1;
    teams.array = malloc(teams.size * sizeof(team_t));

    char team_1[] = "Ferrari";

    strcpy(teams.array[0].name, team_1);
    teams.array[0].year = 1950;
    teams.array[0].titles = 16;

    node_t *head = NULL;

    push(&head, &teams.array[0]);
    void *result = pop_front(&head);

    ck_assert_ptr_eq(result, &teams.array[0]);

    free(teams.array);
    free_list(&head);
}
END_TEST

Suite *pop_front_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("find");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_pop_front_default);
    tcase_add_test(tc_pos, test_pop_front_one_element);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_pop_front_null_pointer);
    tcase_add_test(tc_neg, test_pop_front_uninitialized_list);
    suite_add_tcase(s, tc_neg);

    return s;
}
