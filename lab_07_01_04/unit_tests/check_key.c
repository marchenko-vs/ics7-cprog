#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "array.h"
#include "check_funcs.h"

START_TEST(test_key_null_pointer_1)
{
    int array[5] = {1, 2, 3, 4, 5};
    int *begin = NULL, *end = array + 5;
    int *new_begin = NULL, *new_end = NULL;

    int rc = key(begin, end, &new_begin, &new_end);

    ck_assert_int_eq(rc, EMPTY_ARRAY_ERROR);
}
END_TEST

START_TEST(test_key_null_pointer_2)
{
    int array[5] = {1, 2, 3, 4, 5};
    int *begin = array, *end = NULL;
    int *new_begin = NULL, *new_end = NULL;

    int rc = key(begin, end, &new_begin, &new_end);

    ck_assert_int_eq(rc, EMPTY_ARRAY_ERROR);
}
END_TEST

START_TEST(test_key_null_pointer_3)
{
    int *begin = NULL, *end = NULL;
    int *new_begin = NULL, *new_end = NULL;

    int rc = key(begin, end, &new_begin, &new_end);

    ck_assert_int_eq(rc, EMPTY_ARRAY_ERROR);
}
END_TEST

START_TEST(test_key_empty_array)
{
    int array[5] = {1, 2, 3, 4, 5};
    int *begin = array, *end = array;
    int *new_begin = NULL, *new_end = NULL;

    int rc = key(begin, end, &new_begin, &new_end);

    ck_assert_int_eq(rc, EMPTY_ARRAY_ERROR);
}
END_TEST

START_TEST(test_key_empty_filtered_array)
{
    int array[5] = {1, 1, 1, 1, 1};
    int *begin = array, *end = array + 5;
    int *new_begin = NULL, *new_end = NULL;

    int rc = key(begin, end, &new_begin, &new_end);

    ck_assert_int_eq(rc, EMPTY_ARRAY_ERROR);
}
END_TEST

START_TEST(test_key_normal_array)
{
    int input_array[5] = {5, 4, 3, 2, 1};
    int output_array[2] = {5, 4};

    int *begin = input_array, *end = input_array + 5;
    int *new_begin = NULL, *new_end = NULL;

    int rc = key(begin, end, &new_begin, &new_end);

    ck_assert_int_eq(new_end - new_begin, 2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    for (int i = 0; i < 2; i++)
        ck_assert_int_eq(*(new_begin + i), output_array[i]);

    free(new_begin);
}
END_TEST

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("key");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_key_null_pointer_1);
    tcase_add_test(tc_neg, test_key_null_pointer_2);
    tcase_add_test(tc_neg, test_key_null_pointer_3);
    tcase_add_test(tc_neg, test_key_empty_array);
    tcase_add_test(tc_neg, test_key_empty_filtered_array);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_normal_array);
    suite_add_tcase(s, tc_pos);

    return s;
}
