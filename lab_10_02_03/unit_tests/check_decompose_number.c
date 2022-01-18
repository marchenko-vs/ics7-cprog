#include <check.h>

#include "list.h"

START_TEST(test_decompose_number_non_positive)
{
    int number = -2;

    node_t *head = decompose_number(number);

    ck_assert_ptr_eq(head, NULL);
}
END_TEST

START_TEST(test_decompose_number_one)
{
    int number = 1;

    node_t *head = decompose_number(number);

    ck_assert_int_eq(head->degree, 0);

    free_list(&head);
}
END_TEST

START_TEST(test_decompose_number_default)
{
    int number = 164;

    node_t *head = decompose_number(number);
    node_t *current = head;

    ck_assert_int_eq(current->degree, 2);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 1);
    current = current->next;

    ck_assert_ptr_eq(current, NULL);

    free_list(&head);
}
END_TEST

Suite *decompose_number_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("decompose_number");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_decompose_number_one);
    tcase_add_test(tc_neg, test_decompose_number_default);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_decompose_number_non_positive);
    suite_add_tcase(s, tc_neg);

    return s;
}
