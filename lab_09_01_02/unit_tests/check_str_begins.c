#include <check.h>
#include "strfuncs.h"
#include "check_funcs.h"

START_TEST(test_str_begins_null_ptrs)
{
    char *str_1 = NULL;
    char *str_2 = NULL;

    int rc = str_begins(str_1, str_2);

    ck_assert_int_eq(rc, ERR_NULL_PTRS);
}
END_TEST

START_TEST(test_str_begins_no_substr)
{
    char *str_1 = "hello\0";
    char *str_2 = "ol\0";

    int rc = str_begins(str_1, str_2);

    ck_assert_int_eq(rc, NO_SUBSTRING_FOUND);
}
END_TEST

START_TEST(test_str_begins_similar_ptrs)
{
    char *str = "hello\0";

    int rc = str_begins(str, str);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_str_begins_success)
{
    char *str_1 = "coca-cola\0";
    char *str_2 = "co\0";

    int rc = str_begins(str_1, str_2);

    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_str_begins_default)
{
    char *str_1 = "coca-cola\0";
    char *str_2 = "ca\0";

    int rc = str_begins(str_1, str_2);

    ck_assert_int_eq(rc, 2);
}
END_TEST

Suite *str_begins_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("str_begins");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_str_begins_no_substr);
    tcase_add_test(tc_pos, test_str_begins_similar_ptrs);
    tcase_add_test(tc_pos, test_str_begins_success);
    tcase_add_test(tc_pos, test_str_begins_default);
    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_str_begins_null_ptrs);
    suite_add_tcase(s, tc_neg);

    return s;
}
