#include <check.h>
#include <stdlib.h>
#include "sort.h"
#include "check_funcs.h"

START_TEST(test_mysort_one_element)
{
    int input_array[1] = {5};
    int output_array[1] = {5};

    mysort(&input_array, 1, sizeof(int), &compare);

    ck_assert_int_eq(input_array[0], output_array[0]);
}
END_TEST

START_TEST(test_mysort_ordered_array)
{
    int input_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int output_array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    mysort(&input_array, 10, sizeof(int), &compare);

    for (size_t i = 0; i < 10; i++)
        ck_assert_int_eq(input_array[i], output_array[i]);
}
END_TEST

START_TEST(test_mysort_unordered_array)
{
    int input_array[11] = {5, 4, 3, 2, 1, 0, -1, 6, 8, 7, 9};
    int output_array[11] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    mysort(&input_array, 10, sizeof(int), &compare);

    for (size_t i = 0; i < 10; i++)
        ck_assert_int_eq(input_array[i], output_array[i]);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("mysort");
    tc = tcase_create("positives");

    tcase_add_test(tc, test_mysort_one_element);
    tcase_add_test(tc, test_mysort_ordered_array);
    tcase_add_test(tc, test_mysort_unordered_array);
    suite_add_tcase(s, tc);

    return s;
}
