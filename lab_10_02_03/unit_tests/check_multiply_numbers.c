#include <check.h>

#include "list.h"

START_TEST(test_multiply_numbers_uninitialized_first)
{
    node_t *number_1 = NULL;
    node_t *number_2 = decompose_number(6);

    node_t *result = multiply_numbers(number_1, number_2);

    ck_assert_ptr_eq(result, NULL);

    free_list(&number_2);
}
END_TEST

START_TEST(test_multiply_numbers_uninitialized_second)
{
    node_t *number_1 = decompose_number(6);
    node_t *number_2 = NULL;

    node_t *result = multiply_numbers(number_1, number_2);

    ck_assert_ptr_eq(result, NULL);

    free_list(&number_1);
}
END_TEST

START_TEST(test_multiply_numbers_uninitialized_both)
{
    node_t *number_1 = NULL;
    node_t *number_2 = NULL;

    node_t *result = multiply_numbers(number_1, number_2);

    ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_multiply_numbers_default)
{
    node_t *number_1 = decompose_number(15);
    node_t *number_2 = decompose_number(9);

    node_t *result = multiply_numbers(number_1, number_2);

    node_t *current = result;

    ck_assert_int_eq(current->degree, 0);
    current = current->next;

    ck_assert_int_eq(current->degree, 3);
    current = current->next;

    ck_assert_int_eq(current->degree, 1);
    current = current->next;

    ck_assert_ptr_eq(current, NULL);

    free_list(&number_1);
    free_list(&number_2);
    free_list(&result);
}
END_TEST

Suite *multiply_numbers_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("multiply_numbers");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_multiply_numbers_default);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_multiply_numbers_uninitialized_first);
    tcase_add_test(tc_neg, test_multiply_numbers_uninitialized_second);
    tcase_add_test(tc_neg, test_multiply_numbers_uninitialized_both);
    suite_add_tcase(s, tc_neg);

    return s;
}
