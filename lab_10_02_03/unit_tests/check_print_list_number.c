#include <check.h>

#include "list.h"

START_TEST(test_print_list_number_uninitialized)
{
    node_t *head = NULL;

    print_list_number(head);

    ck_assert_ptr_eq(head, NULL);
}
END_TEST

Suite *print_list_number_suite(void)
{
    Suite *s;
    TCase *tc_neg;

    s = suite_create("print_list_number");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_print_list_number_uninitialized);
    suite_add_tcase(s, tc_neg);

    return s;
}
