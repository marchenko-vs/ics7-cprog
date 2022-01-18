#include <check.h>

#include "list.h"

START_TEST(test_free_list_null_pointer)
{
    node_t *head = NULL;

    free_list(NULL);

    ck_assert_ptr_eq(head, NULL);
}
END_TEST

START_TEST(test_free_list_uninitialized)
{
    node_t *head = NULL;

    free_list(&head);

    ck_assert_ptr_eq(head, NULL);
}
END_TEST

START_TEST(test_free_list_default)
{
    node_t *head = NULL;

    push_back(&head, 5);
    push_back(&head, 1);

    free_list(&head);

    ck_assert_ptr_eq(head, NULL);
}
END_TEST

Suite *free_list_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("free_list");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_free_list_default);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_free_list_null_pointer);
    tcase_add_test(tc_neg, test_free_list_uninitialized);
    suite_add_tcase(s, tc_neg);

    return s;
}
