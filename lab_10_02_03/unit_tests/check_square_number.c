#include <check.h>

#include "list.h"

START_TEST(test_square_number_uninitialized)
{
    node_t *head = NULL;

    square_number(head);

    ck_assert_ptr_eq(head, NULL);
}
END_TEST

START_TEST(test_square_number_one)
{
    int number = 1;

    node_t *head = decompose_number(number);
    square_number(head);

    ck_assert_int_eq(head->degree, 0);

    free_list(&head);
}
END_TEST

START_TEST(test_square_number_default)
{
    int number = 36;

    node_t *head = decompose_number(number);
    square_number(head);

    node_t *current = head;

    ck_assert_int_eq(current->degree, 4);
    current = current->next;

    ck_assert_int_eq(current->degree, 4);
    current = current->next;

    ck_assert_ptr_eq(current, NULL);

    free_list(&head);
}
END_TEST

Suite *square_number_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("square_number");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_square_number_one);
    tcase_add_test(tc_neg, test_square_number_default);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_square_number_uninitialized);
    suite_add_tcase(s, tc_neg);

    return s;
}
