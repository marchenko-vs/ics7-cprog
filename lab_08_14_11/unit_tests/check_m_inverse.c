#include <check.h>
#include <stdlib.h>
#include <matrix.h>
#include "check_funcs.h"

#define EPS 1e-6

START_TEST(test_m_inverse_not_square)
{
    matrix_t matrix_1 = { .rows = 4, .columns = 6 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 4; i++)
        for (size_t j = 0; j < 6; j++)
            matrix_1.element[i][j] = i + j;

    matrix_t matrix_res = { .rows = 4, .columns = 6 };

    m_allocate(&matrix_res);

    int rc = m_inverse(&matrix_1, &matrix_res);

    m_free(&matrix_1);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, ERR_MATRIX_SIZE);
}
END_TEST

START_TEST(test_m_multiply_det_eq_zero) // det means determinant; eq means equal
{
    matrix_t matrix_1 = { .rows = 2, .columns = 2 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            matrix_1.element[i][j] = 2;

    matrix_t matrix_res = { .rows = 2, .columns = 2 };

    m_allocate(&matrix_res);

    int rc = m_inverse(&matrix_1, &matrix_res);

    m_free(&matrix_1);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, ERR_ZERO_DET);
}
END_TEST

START_TEST(test_m_multiply_det_ne_zero) // ne means not equal
{
    matrix_t matrix_1 = { .rows = 5, .columns = 5 };

    m_allocate(&matrix_1);

    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            if (i == j)
                matrix_1.element[i][j] = -3;
            else
                matrix_1.element[i][j] = i + j;

    double out[5][5] = {{-0.205305, 0.072467, 0.048655, 0.035426, 0.027008},
                        {0.072467, -0.146583, 0.045253, 0.040717, 0.037831},
                        {0.048655, 0.045253, -0.099062, 0.042985, 0.042470},
                        {0.035426, 0.040717, 0.042985, -0.066866, 0.045047},
                        {0.027008, 0.037831, 0.042470, 0.045047, -0.044222}};

    matrix_t matrix_res = { .rows = 5, .columns = 5 };

    m_allocate(&matrix_res);

    int rc = m_inverse(&matrix_1, &matrix_res);

    for (size_t i = 0; i < 3; i++)
         for (size_t j = 0; j < 3; j++)
             ck_assert_double_eq_tol(out[i][j], matrix_res.element[i][j], EPS);

    m_free(&matrix_1);
    m_free(&matrix_res);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

Suite* m_inverse_suite(void)
{
    Suite *s;
    TCase *tc_neg, *tc_pos;

    s = suite_create("m_inverse");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_m_multiply_det_ne_zero);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_m_inverse_not_square);
    tcase_add_test(tc_neg, test_m_multiply_det_eq_zero);
    suite_add_tcase(s, tc_neg);

    return s;
}
