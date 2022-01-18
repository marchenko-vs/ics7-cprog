#include <check.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef DYNAMIC_BUILD
#include "dl_array.h"
#else
#include "array.h"
#endif

START_TEST(test_key_null_pointer)
{
    int *array_src = NULL, size_src = 5;
    int *array_dst = NULL, size_dst = 5;

    int rc = key(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(rc, ERR_NULL_POINTER);
}
END_TEST

START_TEST(test_key_zero_size)
{
    int array_src[5] = {1, 2, 3, 4, 5};
    int *array_dst = NULL;
    int size_src = 0, size_dst = 5;

    int rc = key(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(rc, ERR_ZERO_SIZE);
}
END_TEST

START_TEST(test_key_empty_filtered_array)
{
    int array_src[5] = {1, 1, 1, 1, 1};
    int *array_dst = NULL;
    int size_src = 5, size_dst = 5;

    int rc = key(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(rc, ERR_EMPTY_ARRAY);
}
END_TEST

START_TEST(test_key_small_destination_size)
{
    int size_src = 7, size_dst = 1;
    int array_src[7] = {6, 5, 4, 3, 2, 1, 0};
    int *array_dst = malloc(size_dst * sizeof(int));

    int rc = key(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(size_dst, 3);
    ck_assert_int_eq(rc, ERR_SMALL_DESTINATION_SIZE);

    free(array_dst);
}
END_TEST

START_TEST(test_key_normal_array)
{
    int size_src = 5, size_dst = 2;
    int array_src[5] = {5, 4, 3, 2, 1};
    int *array_dst = malloc(size_dst * sizeof(int));

    int rc = key(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(size_dst, 2);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(array_dst[0], 5);
    ck_assert_int_eq(array_dst[1], 4);

    free(array_dst);
}
END_TEST

Suite *key_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("key");
    tc_neg = tcase_create("negatives");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_neg, test_key_null_pointer);
    tcase_add_test(tc_neg, test_key_zero_size);
    tcase_add_test(tc_neg, test_key_empty_filtered_array);
    tcase_add_test(tc_neg, test_key_small_destination_size);
    suite_add_tcase(s, tc_neg);

    tcase_add_test(tc_pos, test_key_normal_array);
    suite_add_tcase(s, tc_pos);

    return s;
}
