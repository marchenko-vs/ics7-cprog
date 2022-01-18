#include <check.h>
#include <string.h>

#include "list.h"
#include "team.h"
#include "teams.h"

START_TEST(test_reverse_uninitialized_list)
{
    node_t *head = NULL;
    node_t *result = reverse(head);

    ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_reverse_default)
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

    strcpy(teams.array[1].name, team_2);
    teams.array[1].year = 1963;
    teams.array[1].titles = 8;

    strcpy(teams.array[2].name, team_3);
    teams.array[2].year = 1981;
    teams.array[2].titles = 0;

    node_t *head = NULL;

    array_to_list(&head, teams.array, teams.size);
    node_t *reversed_list = reverse(head);

    ck_assert_ptr_ne(reversed_list->data, &teams.array[1]);

    free(teams.array);
    free_list(&reversed_list);
}
END_TEST

START_TEST(test_reverse_one_element)
{
    teams_t teams;
    teams.size = 1;
    teams.array = malloc(teams.size * sizeof(team_t));

    char team_1[] = "Ferrari";

    strcpy(teams.array[0].name, team_1);
    teams.array[0].year = 1950;
    teams.array[0].titles = 16;

    node_t *head = NULL;

    array_to_list(&head, teams.array, teams.size);
    //push(&head, &teams.array[0]);
    node_t *reversed_list = reverse(head);

    ck_assert_ptr_eq(reversed_list->data, &teams.array[0]);

    free(teams.array);
    free_list(&head);
}
END_TEST

Suite *reverse_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("reverse");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_reverse_default);
    tcase_add_test(tc_pos, test_reverse_one_element);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_reverse_uninitialized_list);
    suite_add_tcase(s, tc_neg);

    return s;
}
