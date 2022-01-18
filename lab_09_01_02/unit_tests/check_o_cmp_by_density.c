#include <check.h>
#include "object.h"
#include "check_funcs.h"

START_TEST(test_o_cmp_by_density_obj1_gt_obj2)
{
    object_t object_1 = { NULL, 10, 2 };
    object_t object_2 = { NULL, 5, 3 };

    int rc = o_cmp_by_density(&object_1, &object_2);

    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_o_cmp_by_density_obj2_gt_obj1)
{
    object_t object_1 = { NULL, 5, 3 };
    object_t object_2 = { NULL, 10, 2 };

    int rc = o_cmp_by_density(&object_1, &object_2);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_o_cmp_by_density_obj1_eq_obj2)
{
    object_t object_1 = { NULL, 20, 5 };
    object_t object_2 = { NULL, 20, 5 };

    int rc = o_cmp_by_density(&object_1, &object_2);

    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite *o_cmp_by_density_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("o_cmp_by_density");
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_o_cmp_by_density_obj1_gt_obj2);
    tcase_add_test(tc_pos, test_o_cmp_by_density_obj2_gt_obj1);
    tcase_add_test(tc_pos, test_o_cmp_by_density_obj1_eq_obj2);
    suite_add_tcase(s, tc_pos);

    return s;
}
