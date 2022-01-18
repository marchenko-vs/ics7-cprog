#include <check.h>
#include <stdlib.h>
#include <matrix.h>
#include "check_funcs.h"

START_TEST(test_m_power_negative_power)
{
    matrix_t matrix_1 = { .rows = 5, .columns = 5 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = 5, .columns = 5 };

    m_allocate(&matrix_res);

    int rc = m_power(&matrix_1, &matrix_res, -5);

    m_free(&matrix_1);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_m_power_rows_ne_columns) // ne means not equal
{
    matrix_t matrix_1 = { .rows = 6, .columns = 3 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 6; i++)
        for (size_t j = 0; j < 3; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = 6, .columns = 3 };

    m_allocate(&matrix_res);

    int rc = m_power(&matrix_1, &matrix_res, 3);

    m_free(&matrix_1);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_FAILURE);
}
END_TEST

START_TEST(test_m_power_power_eq_zero) // eq means equal
{
    matrix_t matrix_1 = { .rows = 4, .columns = 4 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = 4, .columns = 4 };

    m_allocate(&matrix_res);

    int rc = m_power(&matrix_1, &matrix_res, 0);

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            if (i == j)
                ck_assert_int_eq(matrix_res.element[i][j], 1);
            else
                ck_assert_int_eq(matrix_res.element[i][j], 0);

    m_free(&matrix_1);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_m_power_power_eq_one)
{
    matrix_t matrix_1 = { .rows = 4, .columns = 4 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = 4, .columns = 4 };

    m_allocate(&matrix_res);

    int rc = m_power(&matrix_1, &matrix_res, 1);

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            ck_assert_int_eq(matrix_res.element[i][j], matrix_1.element[i][j]);


    m_free(&matrix_1);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_m_power_default)
{
    matrix_t matrix_1 = { .rows = 4, .columns = 4 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = 4, .columns = 4 };

    m_allocate(&matrix_res);

    int rc = m_power(&matrix_1, &matrix_res, 3);

    int output[4][4] = {{168, 260, 352, 444},
                        {260, 400, 540, 680},
                        {352, 540, 728, 916},
                        {444, 680, 916, 1152}};

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 4; j++)
            ck_assert_int_eq(matrix_res.element[i][j], output[i][j]);

    m_free(&matrix_1);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* m_power_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("m_power");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_m_power_power_eq_zero);
    tcase_add_test(tc_pos, test_m_power_power_eq_one);
    tcase_add_test(tc_pos, test_m_power_default);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_m_power_negative_power);
    tcase_add_test(tc_neg, test_m_power_rows_ne_columns);
    suite_add_tcase(s, tc_neg);

    return s;
}
