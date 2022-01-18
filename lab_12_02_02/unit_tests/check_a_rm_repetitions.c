#include <check.h>

#include "array.h"

START_TEST(test_a_rm_repetitions_null_pointer)
{
    size_t size_src = 10;
    int *array_src = NULL;

    size_t size_dst = 10;
    int *array_dst = NULL;

    int rc = a_rm_repetitions(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(rc, ERR_NULL_POINTER);
    ck_assert_int_eq(size_dst, 10);
}
END_TEST

START_TEST(test_a_rm_repetitions_zero_size)
{
    size_t size_src = 0;
    int *array_src = malloc(10 * sizeof(int));

    size_t size_dst = 10;
    int *array_dst = NULL;

    int rc = a_rm_repetitions(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(rc, ERR_ZERO_SIZE);
    ck_assert_int_eq(size_dst, 10);

    free(array_src);
}
END_TEST

START_TEST(test_a_rm_repetitions_small_destination_size)
{
    size_t size_src = 5;
    int *array_src = malloc(size_src * sizeof(int));

    for (size_t i = 0; i < size_src; i++)
        array_src[i] = i;

    size_t size_dst = 2;
    int *array_dst = malloc(size_dst * sizeof(int));

    int rc = a_rm_repetitions(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(rc, ERR_SRC_ARRAY_SIZE);
    ck_assert_int_eq(size_dst, 5);

    free(array_src);
    free(array_dst);
}
END_TEST

START_TEST(test_a_rm_repetitions_one_element)
{
    size_t size_src = 1;
    int *array_src = malloc(size_src * sizeof(int));
    array_src[0] = 2;

    size_t size_dst = 1;
    int *array_dst = malloc(size_dst * sizeof(int));

    int rc = a_rm_repetitions(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(size_dst, 1);
    ck_assert_int_eq(array_src[0], array_dst[0]);

    free(array_src);
    free(array_dst);
}
END_TEST

START_TEST(test_a_rm_repetitions_no_duplicates)
{
    size_t size_src = 5;
    int *array_src = malloc(size_src * sizeof(int));

    for (size_t i = 0; i < size_src; i++)
        array_src[i] = i;

    size_t size_dst = 5;
    int *array_dst = malloc(size_dst * sizeof(int));

    int rc = a_rm_repetitions(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(size_dst, 5);

    for (size_t i = 0; i < size_src; i++)
        ck_assert_int_eq(array_src[i], array_dst[i]);

    free(array_src);
    free(array_dst);
}
END_TEST

START_TEST(test_a_rm_repetitions_default)
{
    size_t size_src = 10;
    int *array_src = malloc(size_src * sizeof(int));

    for (size_t i = 0; i < size_src; i++)
        array_src[i] = i;

    array_src[3] = array_src[1];
    array_src[4] = array_src[9];
    array_src[5] = array_src[1];
    array_src[6] = array_src[8];

    size_t size_dst = 10;
    int *array_dst = malloc(size_dst * sizeof(int));

    int rc = a_rm_repetitions(array_src, size_src, array_dst, &size_dst);

    ck_assert_int_eq(array_dst[0], 0);
    ck_assert_int_eq(array_dst[1], 1);
    ck_assert_int_eq(array_dst[2], 2);
    ck_assert_int_eq(array_dst[3], 9);
    ck_assert_int_eq(array_dst[4], 8);
    ck_assert_int_eq(array_dst[5], 7);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(size_dst, 6);
    
    free(array_src);
    free(array_dst);
}
END_TEST

Suite *a_rm_repetitions_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("a_rm_repetitions");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_a_rm_repetitions_one_element);
    tcase_add_test(tc_pos, test_a_rm_repetitions_no_duplicates);
    tcase_add_test(tc_pos, test_a_rm_repetitions_default);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_a_rm_repetitions_null_pointer);
    tcase_add_test(tc_neg, test_a_rm_repetitions_zero_size);
    tcase_add_test(tc_pos, test_a_rm_repetitions_small_destination_size);
    suite_add_tcase(s, tc_neg);

    return s;
}
