#include <check.h>

#include "array.h"

START_TEST(test_a_fill_fibonacci_null_pointer)
{
    size_t size = 10;
    int *array = NULL;

    int rc = a_fill_fibonacci(array, size);

    ck_assert_int_eq(rc, ERR_NULL_POINTER);
}
END_TEST

START_TEST(test_a_fill_fibonacci_zero_size)
{
    size_t size = 0;
    int *array = malloc(10 * sizeof(int));

    int rc = a_fill_fibonacci(array, size);

    ck_assert_int_eq(rc, ERR_ZERO_SIZE);

    free(array);
}
END_TEST

START_TEST(test_a_fill_fibonacci_one_element)
{
    size_t size = 1;
    int *array = malloc(size * sizeof(int));

    int rc = a_fill_fibonacci(array, size);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(array[0], 0);

    free(array);
}
END_TEST

START_TEST(test_a_fill_fibonacci_default)
{
    size_t size = 7;
    int *array = malloc(size * sizeof(int));

    int rc = a_fill_fibonacci(array, size);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(array[0], 0);
    ck_assert_int_eq(array[1], 1);
    ck_assert_int_eq(array[2], 1);
    ck_assert_int_eq(array[3], 2);
    ck_assert_int_eq(array[4], 3);
    ck_assert_int_eq(array[5], 5);
    ck_assert_int_eq(array[6], 8);

    free(array);
}
END_TEST

Suite *a_fill_fibonacci_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("a_fill_fibonacci");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_a_fill_fibonacci_one_element);
    tcase_add_test(tc_pos, test_a_fill_fibonacci_default);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_a_fill_fibonacci_null_pointer);
    tcase_add_test(tc_neg, test_a_fill_fibonacci_zero_size);
    suite_add_tcase(s, tc_neg);

    return s;
}
