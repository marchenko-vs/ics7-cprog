#include <check.h>
#include <stdlib.h>
#include <matrix.h>
#include "check_funcs.h"

#define EPS 1e-6

START_TEST(test_m_addition_incorrect_sizes)
{
    size_t m = 2, n = 3;
    matrix_t matrix_1 = { .rows = m, .columns = n };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_2 = { .rows = n, .columns = m };

    m_allocate(&matrix_2);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            matrix_2.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = 3, .columns = 3 };

    m_allocate(&matrix_res);

    int rc = m_addition(&matrix_1, &matrix_2, &matrix_res);

    m_free(&matrix_1);
    m_free(&matrix_2);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, ERR_MATRIX_SIZE);
}
END_TEST

START_TEST(test_m_addition_square_matrices)
{
    size_t n = 3;
    matrix_t matrix_1 = { .rows = n, .columns = n };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_2 = { .rows = n, .columns = n };

    m_allocate(&matrix_2);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            matrix_2.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = n, .columns = n };

    m_allocate(&matrix_res);

    int rc = m_addition(&matrix_1, &matrix_2, &matrix_res);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            ck_assert_double_eq_tol(matrix_1.element[i][j] + 
                matrix_2.element[i][j], matrix_res.element[i][j], EPS);

    m_free(&matrix_1);
    m_free(&matrix_2);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_m_addition_rows_gt_columns) // gt means greater than
{
    size_t m = 5, n = 3;
    matrix_t matrix_1 = { .rows = m, .columns = n };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_2 = { .rows = m, .columns = n };

    m_allocate(&matrix_2);

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            matrix_2.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = m, .columns = n };

    m_allocate(&matrix_res);

    int rc = m_addition(&matrix_1, &matrix_2, &matrix_res);

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            ck_assert_double_eq_tol(matrix_1.element[i][j] + 
                matrix_2.element[i][j], matrix_res.element[i][j], EPS);

    m_free(&matrix_1);
    m_free(&matrix_2);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_m_addition_columns_gt_rows) // gt means greater than
{
    size_t m = 3, n = 5;
    matrix_t matrix_1 = { .rows = m, .columns = n };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_2 = { .rows = m, .columns = n };

    m_allocate(&matrix_2);

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            matrix_2.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = m, .columns = n };

    m_allocate(&matrix_res);

    int rc = m_addition(&matrix_1, &matrix_2, &matrix_res);

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            ck_assert_double_eq_tol(matrix_1.element[i][j] + 
                matrix_2.element[i][j], matrix_res.element[i][j], EPS);

    m_free(&matrix_1);
    m_free(&matrix_2);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* m_addition_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("m_addition");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_m_addition_square_matrices);
    tcase_add_test(tc_pos, test_m_addition_rows_gt_columns);
    tcase_add_test(tc_pos, test_m_addition_columns_gt_rows);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_m_addition_incorrect_sizes);
    suite_add_tcase(s, tc_neg);

    return s;
}
