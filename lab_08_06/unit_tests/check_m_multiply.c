#include <check.h>
#include <stdlib.h>
#include <matrix.h>
#include "check_funcs.h"

START_TEST(test_m_multiply_incorrect_sizes)
{
    size_t m = 5, n = 3;
    matrix_t matrix_1 = { .rows = m, .columns = n };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < m; i++)
        for (size_t j = 0; j < n; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_2 = { .rows = n + 2, .columns = m };

    m_allocate(&matrix_2);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m + 2; j++)
            matrix_2.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = m, .columns = m + 2 };

    m_allocate(&matrix_res);

    int rc = m_multiply(&matrix_1, &matrix_2, &matrix_res);

    m_free(&matrix_1);
    m_free(&matrix_2);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, ERR_MATRIX_SIZE);
}
END_TEST

START_TEST(test_m_multiply_square_matrices)
{
    matrix_t matrix_1 = { .rows = 3, .columns = 3 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_2 = { .rows = 3, .columns = 3 };

    m_allocate(&matrix_2);

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            matrix_2.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = 3, .columns = 3 };

    m_allocate(&matrix_res);

    int rc = m_multiply(&matrix_1, &matrix_2, &matrix_res);

    int output[3][3] = {{5, 8, 11}, 
                        {8, 14, 20},
                        {11, 20, 29}};

    for (size_t i = 0; i < 3; i++)
         for (size_t j = 0; j < 3; j++)
            ck_assert_int_eq(output[i][j],
                matrix_res.element[i][j]);

    m_free(&matrix_1);
    m_free(&matrix_2);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_m_multiply_not_square)
{
    matrix_t matrix_1 = { .rows = 5, .columns = 4 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 4; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_2 = { .rows = 4, .columns = 5 };

    m_allocate(&matrix_2);

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 5; j++)
            matrix_2.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = 5, .columns = 5 };

    m_allocate(&matrix_res);

    int rc = m_multiply(&matrix_1, &matrix_2, &matrix_res);

    int output[5][5] = {{14, 20, 26, 32, 38}, 
                            {20, 30, 40, 50, 60},
                            {26, 40, 54, 68, 82},
                            {32, 50, 68, 86, 104},
                            {38, 60, 82, 104, 126}};

    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            ck_assert_int_eq(output[i][j], 
                matrix_res.element[i][j]);

    m_free(&matrix_1);
    m_free(&matrix_2);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* m_multiply_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("m_multiply");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_m_multiply_square_matrices);
    tcase_add_test(tc_pos, test_m_multiply_not_square);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_m_multiply_incorrect_sizes);
    suite_add_tcase(s, tc_neg);

    return s;
}
