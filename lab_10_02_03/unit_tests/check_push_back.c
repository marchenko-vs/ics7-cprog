#include <check.h>
#include <stdlib.h>

#include "list.h"

START_TEST(test_push_back_null_pointer)
{
    node_t *head = NULL;

    int rc = push_back(NULL, 2);

    ck_assert_ptr_eq(head, NULL);
    ck_assert_int_eq(rc, ERR_NULL_POINTER);
}
END_TEST

START_TEST(test_push_back_uninitialized)
{
    node_t *head = NULL;

    int rc = push_back(&head, 2);

    ck_assert_ptr_ne(head, NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(head->degree, 2);

    free_list(&head);
}
END_TEST

START_TEST(test_push_back_default)
{
    node_t *head = NULL;

    push_back(&head, 2);
    push_back(&head, 1);
    push_back(&head, 3);
    push_back(&head, 0);
    int rc = push_back(&head, 5);

    ck_assert_ptr_ne(head, NULL);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(head->degree, 2);

    free_list(&head);
}
END_TEST

Suite *push_back_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("push_back");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_push_back_default);
    tcase_add_test(tc_neg, test_push_back_uninitialized);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_push_back_null_pointer);
    suite_add_tcase(s, tc_neg);

    return s;
}
