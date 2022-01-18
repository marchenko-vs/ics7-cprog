#include <check.h>
#include "object.h"
#include "check_funcs.h"

#define EPS 1e-6

START_TEST(test_o_swap_default)
{
    char name_1[] = "Cola\0";
    char name_2[] = "Pepsi\0";

    object_t object_1 = { NULL, 0, 0 };
    object_t object_2 = { NULL, 0, 0 };

    o_init(&object_1, name_1, 20, 4);
    o_init(&object_2, name_2, 17, 6);

    o_swap(&object_1, &object_2);

    ck_assert_float_eq_tol(object_1.weight, 17, EPS);
    ck_assert_float_eq_tol(object_1.volume, 6, EPS);
    ck_assert_float_eq_tol(object_2.weight, 20, EPS);
    ck_assert_float_eq_tol(object_2.volume, 4, EPS);

    o_free_content(&object_1);
    o_free_content(&object_2);
}
END_TEST

Suite *o_swap_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("o_swap");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_o_swap_default);
    suite_add_tcase(s, tc_pos);

    return s;
}
