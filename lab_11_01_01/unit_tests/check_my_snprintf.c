#include <check.h>
#include <limits.h>
#include <stdio.h>

#include "my_snprintf.h"

#define SIZE 64

// all
START_TEST(test_all_null_0)
{
    char format[] = "Hello, this is a unit-test.\n";

    int rc_my = my_snprintf(NULL, 0, format);
    int rc_correct = snprintf(NULL, 0, format);

    ck_assert_int_eq(rc_my, rc_correct);
}
END_TEST

START_TEST(test_all_not_null_0)
{
    char format[] = "Hello, this is a unit-test.\n";

    char buf_my[SIZE] = {0};
    char buf_correct[SIZE] = {0};

    int rc_my = my_snprintf(buf_my, 0, format);
    int rc_correct = snprintf(buf_correct, 0, format);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_all_default)
{
    char format[] = "Hello, this is a unit-test.";

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, format);
    int rc_correct = snprintf(buf_correct, SIZE, format);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_all_too_short_buffer)
{
    char format[] = "Hello, this is a unit-test.";

    char buf_my[10];
    char buf_correct[10];

    int rc_my = my_snprintf(buf_my, 10, format);
    int rc_correct = snprintf(buf_correct, 10, format);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_all_one_element_buffer)
{
    char format[] = "Hello, this is a unit-test.";

    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format);
    int rc_correct = snprintf(buf_correct, 1, format);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_all_percent_symbols)
{
    char format[] = "It is 100%% correct info.";

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, format);
    int rc_correct = snprintf(buf_correct, SIZE, format);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %c
START_TEST(test_c_default)
{
    char format[] = "Just %c te%ct.\n";
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, format, 'a', 's');
    int rc_correct = snprintf(buf_correct, SIZE, format, 'a', 's');

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_c_too_short_buffer)
{
    char format[] = "Hell%c";

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, 'o');
    int rc_correct = snprintf(buf_correct, 5, format, 'o');

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_c_escape_sequence)
{
    char format[] = "Hell%c. %c";

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, format, 'o', '\n');
    int rc_correct = snprintf(buf_correct, SIZE, format, 'o', '\n');

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_c_one_element_buffer)
{
    char format[] = "%c";

    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, 'x');
    int rc_correct = snprintf(buf_correct, 1, format, 'x');

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %s
START_TEST(test_s_default)
{
    char format[] = "This%s";

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, format, " is a test.\n");
    int rc_correct = snprintf(buf_correct, SIZE, format, " is a test.\n");

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_s_too_short_buffer)
{
    char format[] = "This%s";

    char buf_my[8];
    char buf_correct[8];

    int rc_my = my_snprintf(buf_my, 8, format, " is a test.\n");
    int rc_correct = snprintf(buf_correct, 8, format, " is a test.\n");

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_s_one_element_buffer)
{
    char format[] = "%s";

    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, "Hello");
    int rc_correct = snprintf(buf_correct, 1, format, "Hello");

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %d
START_TEST(test_d_default_positive)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %d y. o.\n", 18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %d y. o.\n", 18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_d_default_negative)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %d y. o.\n", -18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %d y. o.\n", -18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_d_zero)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %d y. o.\n", 0);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %d y. o.\n", 0);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_d_int_min)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %d\n", INT_MIN);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %d\n", INT_MIN);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_d_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %d\n", INT_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %d\n", INT_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_d_too_short_buffer)
{
    char format[] = "a %d";

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, 67382);
    int rc_correct = snprintf(buf_correct, 5, format, 67382);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_d_one_element_buffer)
{
    char format[] = "%d";
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, 67382);
    int rc_correct = snprintf(buf_correct, 1, format, 67382);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %i
START_TEST(test_i_default_positive)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %i y. o.\n", 18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %i y. o.\n", 18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_i_default_negative)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %i y. o.\n", -18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %i y. o.\n", -18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_i_zero)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %i y. o.\n", 0);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %i y. o.\n", 0);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_i_int_min)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %i\n", INT_MIN);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %i\n", INT_MIN);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_i_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %i\n", INT_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %i\n", INT_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_i_too_short_buffer)
{
    char format[] = "a %i";

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, 67382);
    int rc_correct = snprintf(buf_correct, 5, format, 67382);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_i_one_element_buffer)
{
    char format[] = "%i";
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, 67382);
    int rc_correct = snprintf(buf_correct, 1, format, 67382);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %o
START_TEST(test_o_default)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %o y. o.\n", 18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %o y. o.\n", 18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_o_overflow_negative)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %o y. o.\n", -18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %o y. o.\n", -18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_o_zero)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %o y. o.\n", 0);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %o y. o.\n", 0);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_o_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %o\n", INT_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %o\n", INT_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_o_oct_format)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %o\n", 0576);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %o\n", 0576);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_o_too_short_buffer)
{
    char format[] = "a %o";

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, 67382);
    int rc_correct = snprintf(buf_correct, 5, format, 67382);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_o_one_element_buffer)
{
    char format[] = "%o";
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, 67382);
    int rc_correct = snprintf(buf_correct, 1, format, 67382);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %x
START_TEST(test_x_default)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %x y. o.\n", 18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %x y. o.\n", 18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_x_overflow_negative)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %x y. o.\n", -1238);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %x y. o.\n", -1238);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_x_zero)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %x y. o.\n", 0);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %x y. o.\n", 0);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_x_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %x\n", INT_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %x\n", INT_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_x_hex_format)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %x\n", 0x5a6);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %x\n", 0x5a6);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_x_too_short_buffer)
{
    char format[] = "a %x";

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, 67382);
    int rc_correct = snprintf(buf_correct, 5, format, 67382);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_x_one_element_buffer)
{
    char format[] = "%x";
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, 67382);
    int rc_correct = snprintf(buf_correct, 1, format, 67382);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %hd
START_TEST(test_hd_default_positive)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %hd y. o.\n", 18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %hd y. o.\n", 18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hd_default_negative)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %hd y. o.\n", -18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %hd y. o.\n", -18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hd_zero)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %hd y. o.\n", 0);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %hd y. o.\n", 0);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hd_short_int_min)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %hd\n", SHRT_MIN);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %hd\n", SHRT_MIN);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hd_short_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %hd\n", SHRT_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %hd\n", SHRT_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hd_too_short_buffer)
{
    char format[] = "a %hd";

    char buf_my[3];
    char buf_correct[3];

    int rc_my = my_snprintf(buf_my, 3, format, 2345);
    int rc_correct = snprintf(buf_correct, 3, format, 2345);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hd_one_element_buffer)
{
    char format[] = "%hd";
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, 123);
    int rc_correct = snprintf(buf_correct, 1, format, 123);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %hi
START_TEST(test_hi_default_positive)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %hi y. o.\n", 18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %hi y. o.\n", 18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hi_default_negative)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %hi y. o.\n", -18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %hi y. o.\n", -18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hi_zero)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %hi y. o.\n", 0);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %hi y. o.\n", 0);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hi_short_int_min)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %hi\n", SHRT_MIN);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %hi\n", SHRT_MIN);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hi_short_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %hi\n", SHRT_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %hi\n", SHRT_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hi_too_short_buffer)
{
    char format[] = "a %hi";

    char buf_my[3];
    char buf_correct[3];

    int rc_my = my_snprintf(buf_my, 3, format, 2345);
    int rc_correct = snprintf(buf_correct, 3, format, 2345);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hi_one_element_buffer)
{
    char format[] = "%hi";
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, 123);
    int rc_correct = snprintf(buf_correct, 1, format, 123);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %ho
START_TEST(test_ho_default)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %ho y. o.\n", 18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %ho y. o.\n", 18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ho_overflow_negative)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %ho y. o.\n", -18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %ho y. o.\n", -18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ho_zero)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %ho y. o.\n", 0);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %ho y. o.\n", 0);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ho_short_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %ho\n", SHRT_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %ho\n", SHRT_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ho_oct_format)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %ho\n", 0576);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %ho\n", 0576);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ho_too_short_buffer)
{
    char format[] = "a %ho";

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, 12345);
    int rc_correct = snprintf(buf_correct, 5, format, 12345);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ho_one_element_buffer)
{
    char format[] = "%ho";
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, 123);
    int rc_correct = snprintf(buf_correct, 1, format, 123);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %hx
START_TEST(test_hx_default)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %hx y. o.\n", 18);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %hx y. o.\n", 18);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hx_overflow_negative)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %hx y. o.\n", -1238);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %hx y. o.\n", -1238);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hx_zero)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %hx y. o.\n", 0);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %hx y. o.\n", 0);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hx_short_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %hx\n", SHRT_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %hx\n", SHRT_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hx_hex_format)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %hx\n", 0x5a6);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %hx\n", 0x5a6);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hx_too_short_buffer)
{
    char format[] = "a %hx";

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, 12345);
    int rc_correct = snprintf(buf_correct, 5, format, 12345);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_hx_one_element_buffer)
{
    char format[] = "%hx";
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, 123);
    int rc_correct = snprintf(buf_correct, 1, format, 123);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %ld
START_TEST(test_ld_default_positive)
{
    long int number = 18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %ld y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %ld y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ld_default_negative)
{
    long int number = -18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %ld y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %ld y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ld_zero)
{
    long int number = 0;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %ld y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %ld y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ld_long_int_min)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %ld\n", LONG_MIN);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %ld\n", LONG_MIN);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ld_long_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %ld\n", LONG_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %ld\n", LONG_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ld_too_short_buffer)
{
    char format[] = "a %ld";
    long int number = 2345;

    char buf_my[3];
    char buf_correct[3];

    int rc_my = my_snprintf(buf_my, 3, format, number);
    int rc_correct = snprintf(buf_correct, 3, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_ld_one_element_buffer)
{
    char format[] = "%ld";
    long int number = 123;

    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, number);
    int rc_correct = snprintf(buf_correct, 1, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %li
START_TEST(test_li_default_positive)
{
    long int number = 18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %li y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %li y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_li_default_negative)
{
    long int number = -18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %li y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %li y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_li_zero)
{
    long int number = 0;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %li y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %li y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_li_long_int_min)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %li\n", LONG_MIN);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %li\n", LONG_MIN);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_li_long_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %li\n", LONG_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %li\n", LONG_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_li_too_short_buffer)
{
    char format[] = "a %li";
    long int number = 2345;

    char buf_my[3];
    char buf_correct[3];

    int rc_my = my_snprintf(buf_my, 3, format, number);
    int rc_correct = snprintf(buf_correct, 3, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_li_one_element_buffer)
{
    char format[] = "%li";
    long int number = 123;
    
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, number);
    int rc_correct = snprintf(buf_correct, 1, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %lo
START_TEST(test_lo_default)
{
    long int number = 18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %lo y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %lo y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lo_overflow_negative)
{
    long int number = -18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %lo y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %lo y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lo_zero)
{
    long int number = 0;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %lo y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %lo y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lo_long_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %lo\n", LONG_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %lo\n", LONG_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lo_oct_format)
{
    long int number = 0576;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %lo\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %lo\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lo_too_short_buffer)
{
    char format[] = "a %lo";
    long int number = 12345;

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, number);
    int rc_correct = snprintf(buf_correct, 5, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lo_one_element_buffer)
{
    char format[] = "%lo";
    long int number = 123;

    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, number);
    int rc_correct = snprintf(buf_correct, 1, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %lx
START_TEST(test_lx_default)
{
    long int number = 18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %lx y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %lx y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lx_overflow_negative)
{
    long int number = -1238;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I'm not %lx y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I'm not %lx y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lx_zero)
{
    long int number = 0;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %lx y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %lx y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lx_long_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %lx\n", LONG_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %lx\n", LONG_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lx_hex_format)
{
    long int number = 0x5a6;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %lx\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %lx\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lx_too_short_buffer)
{
    char format[] = "a %lx";
    long int number = 12345;

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, number);
    int rc_correct = snprintf(buf_correct, 5, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lx_one_element_buffer)
{
    char format[] = "%lx";
    long int number = 123;

    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, number);
    int rc_correct = snprintf(buf_correct, 1, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %lld
START_TEST(test_lld_default_positive)
{
    long long number = 18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %lld y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %lld y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lld_default_negative)
{
    long long number = -18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %lld y. o.", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %lld y. o.", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lld_zero)
{
    long long number = 0;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %lld y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %lld y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lld_long_long_int_min)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %lld\n", LLONG_MIN);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %lld\n", LLONG_MIN);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lld_long_long_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %lld\n", LLONG_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %lld\n", LLONG_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lld_too_short_buffer)
{
    char format[] = "a %lld";
    long long number = 2345;

    char buf_my[3];
    char buf_correct[3];

    int rc_my = my_snprintf(buf_my, 3, format, number);
    int rc_correct = snprintf(buf_correct, 3, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lld_one_element_buffer)
{
    char format[] = "%lld";
    long long number = 123;

    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, number);
    int rc_correct = snprintf(buf_correct, 1, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %lli
START_TEST(test_lli_default_positive)
{
    long long number = 18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %lli y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %lli y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lli_default_negative)
{
    long long number = -18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %lli y. o.", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %lli y. o.", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lli_zero)
{
    long long number = 0;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %lli y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %lli y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lli_long_long_int_min)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %lli\n", LLONG_MIN);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %lli\n", LLONG_MIN);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lli_long_long_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %lli\n", LLONG_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %lli\n", LLONG_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lli_too_short_buffer)
{
    char format[] = "a %lli";
    long long number = 2345;

    char buf_my[3];
    char buf_correct[3];

    int rc_my = my_snprintf(buf_my, 3, format, number);
    int rc_correct = snprintf(buf_correct, 3, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_lli_one_element_buffer)
{
    char format[] = "%lli";
    long long number = 123;
    
    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, number);
    int rc_correct = snprintf(buf_correct, 1, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %llo
START_TEST(test_llo_default)
{
    long long number = 18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %llo y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %llo y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llo_overflow_negative)
{
    long long number = -18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am not %llo y. o.", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am not %llo y. o.", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llo_zero)
{
    long long number = 0;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %llo y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %llo y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llo_long_long_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %llo\n", LLONG_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %llo\n", LLONG_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llo_oct_format)
{
    long long number = 0576;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %llo\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %llo\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llo_too_short_buffer)
{
    char format[] = "a %llo";
    long long number = 12345;

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, number);
    int rc_correct = snprintf(buf_correct, 5, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llo_one_element_buffer)
{
    char format[] = "%llo";
    long long number = 123;

    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, number);
    int rc_correct = snprintf(buf_correct, 1, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

// %llx
START_TEST(test_llx_default)
{
    long long number = 18;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %llx y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %llx y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llx_overflow_negative)
{
    long long number = -1238;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I'm not %llx y. o.", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I'm not %llx y. o.", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llx_zero)
{
    long long number = 0;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "I am %llx y. o.\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "I am %llx y. o.\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llx_long_long_int_max)
{
    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %llx\n", LLONG_MAX);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %llx\n", LLONG_MAX);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llx_hex_format)
{
    long long number = 0x5a6;

    char buf_my[SIZE];
    char buf_correct[SIZE];

    int rc_my = my_snprintf(buf_my, SIZE, "It is %llx\n", number);
    int rc_correct = snprintf(buf_correct, SIZE, "It is %llx\n", number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llx_too_short_buffer)
{
    char format[] = "a %llx";
    long long number = 12345;

    char buf_my[5];
    char buf_correct[5];

    int rc_my = my_snprintf(buf_my, 5, format, number);
    int rc_correct = snprintf(buf_correct, 5, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

START_TEST(test_llx_one_element_buffer)
{
    char format[] = "%llx";
    long long number = 123;

    char buf_my[1];
    char buf_correct[1];

    int rc_my = my_snprintf(buf_my, 1, format, number);
    int rc_correct = snprintf(buf_correct, 1, format, number);

    ck_assert_int_eq(rc_my, rc_correct);
    ck_assert_str_eq(buf_my, buf_correct);
}
END_TEST

Suite *my_snprintf_suite(void)
{
    Suite *s = suite_create("test_my_snprintf");

    TCase *tc_all = tcase_create("all");

    tcase_add_test(tc_all, test_all_default);
    tcase_add_test(tc_all, test_all_too_short_buffer);
    tcase_add_test(tc_all, test_all_one_element_buffer);
    tcase_add_test(tc_all, test_all_null_0);
    tcase_add_test(tc_all, test_all_not_null_0);
    tcase_add_test(tc_all, test_all_percent_symbols);
    suite_add_tcase(s, tc_all);

    TCase *tc_c = tcase_create("c");

    tcase_add_test(tc_c, test_c_default);
    tcase_add_test(tc_c, test_c_too_short_buffer);
    tcase_add_test(tc_c, test_c_escape_sequence);
    tcase_add_test(tc_c, test_c_one_element_buffer);
    suite_add_tcase(s, tc_c);

    TCase *tc_s = tcase_create("s");

    tcase_add_test(tc_s, test_s_default);
    tcase_add_test(tc_s, test_s_too_short_buffer);
    tcase_add_test(tc_s, test_s_one_element_buffer);
    suite_add_tcase(s, tc_s);

    TCase *tc_d = tcase_create("d");

    tcase_add_test(tc_d, test_d_default_positive);
    tcase_add_test(tc_d, test_d_default_negative);
    tcase_add_test(tc_d, test_d_zero);
    tcase_add_test(tc_d, test_d_int_min);
    tcase_add_test(tc_d, test_d_int_max);
    tcase_add_test(tc_d, test_d_too_short_buffer);
    tcase_add_test(tc_d, test_d_one_element_buffer);
    suite_add_tcase(s, tc_d);

    TCase *tc_i = tcase_create("i");

    tcase_add_test(tc_i, test_i_default_positive);
    tcase_add_test(tc_i, test_i_default_negative);
    tcase_add_test(tc_i, test_i_zero);
    tcase_add_test(tc_i, test_i_int_min);
    tcase_add_test(tc_i, test_i_int_max);
    tcase_add_test(tc_i, test_i_too_short_buffer);
    tcase_add_test(tc_i, test_i_one_element_buffer);
    suite_add_tcase(s, tc_i);

    TCase *tc_o = tcase_create("o");

    tcase_add_test(tc_o, test_o_default);
    tcase_add_test(tc_o, test_o_overflow_negative);
    tcase_add_test(tc_o, test_o_zero);
    tcase_add_test(tc_o, test_o_int_max);
    tcase_add_test(tc_o, test_o_oct_format);
    tcase_add_test(tc_o, test_o_too_short_buffer);
    tcase_add_test(tc_o, test_o_one_element_buffer);
    suite_add_tcase(s, tc_o);

    TCase *tc_x = tcase_create("x");

    tcase_add_test(tc_x, test_x_default);
    tcase_add_test(tc_x, test_x_overflow_negative);
    tcase_add_test(tc_x, test_x_zero);
    tcase_add_test(tc_x, test_x_int_max);
    tcase_add_test(tc_x, test_x_hex_format);
    tcase_add_test(tc_x, test_x_too_short_buffer);
    tcase_add_test(tc_x, test_x_one_element_buffer);
    suite_add_tcase(s, tc_x);

    TCase *tc_hd = tcase_create("hd");

    tcase_add_test(tc_hd, test_hd_default_positive);
    tcase_add_test(tc_hd, test_hd_default_negative);
    tcase_add_test(tc_hd, test_hd_zero);
    tcase_add_test(tc_hd, test_hd_short_int_min);
    tcase_add_test(tc_hd, test_hd_short_int_max);
    tcase_add_test(tc_hd, test_hd_too_short_buffer);
    tcase_add_test(tc_hd, test_hd_one_element_buffer);
    suite_add_tcase(s, tc_hd);

    TCase *tc_hi = tcase_create("hi");

    tcase_add_test(tc_hi, test_hi_default_positive);
    tcase_add_test(tc_hi, test_hi_default_negative);
    tcase_add_test(tc_hi, test_hi_zero);
    tcase_add_test(tc_hi, test_hi_short_int_min);
    tcase_add_test(tc_hi, test_hi_short_int_max);
    tcase_add_test(tc_hi, test_hi_too_short_buffer);
    tcase_add_test(tc_hi, test_hi_one_element_buffer);
    suite_add_tcase(s, tc_hi);

    TCase *tc_ho = tcase_create("ho");

    tcase_add_test(tc_ho, test_ho_default);
    tcase_add_test(tc_ho, test_ho_overflow_negative);
    tcase_add_test(tc_ho, test_ho_zero);
    tcase_add_test(tc_ho, test_ho_short_int_max);
    tcase_add_test(tc_ho, test_ho_oct_format);
    tcase_add_test(tc_ho, test_ho_too_short_buffer);
    tcase_add_test(tc_ho, test_ho_one_element_buffer);
    suite_add_tcase(s, tc_ho);

    TCase *tc_hx = tcase_create("hx");

    tcase_add_test(tc_hx, test_hx_default);
    tcase_add_test(tc_hx, test_hx_overflow_negative);
    tcase_add_test(tc_hx, test_hx_zero);
    tcase_add_test(tc_hx, test_hx_short_int_max);
    tcase_add_test(tc_hx, test_hx_hex_format);
    tcase_add_test(tc_hx, test_hx_too_short_buffer);
    tcase_add_test(tc_hx, test_hx_one_element_buffer);
    suite_add_tcase(s, tc_hx);

    TCase *tc_ld = tcase_create("ld");

    tcase_add_test(tc_ld, test_ld_default_positive);
    tcase_add_test(tc_ld, test_ld_default_negative);
    tcase_add_test(tc_ld, test_ld_zero);
    tcase_add_test(tc_ld, test_ld_long_int_min);
    tcase_add_test(tc_ld, test_ld_long_int_max);
    tcase_add_test(tc_ld, test_ld_too_short_buffer);
    tcase_add_test(tc_ld, test_ld_one_element_buffer);
    suite_add_tcase(s, tc_ld);

    TCase *tc_li = tcase_create("li");

    tcase_add_test(tc_li, test_li_default_positive);
    tcase_add_test(tc_li, test_li_default_negative);
    tcase_add_test(tc_li, test_li_zero);
    tcase_add_test(tc_li, test_li_long_int_min);
    tcase_add_test(tc_li, test_li_long_int_max);
    tcase_add_test(tc_li, test_li_too_short_buffer);
    tcase_add_test(tc_li, test_li_one_element_buffer);
    suite_add_tcase(s, tc_li);

    TCase *tc_lo = tcase_create("lo");

    tcase_add_test(tc_lo, test_lo_default);
    tcase_add_test(tc_lo, test_lo_overflow_negative);
    tcase_add_test(tc_lo, test_lo_zero);
    tcase_add_test(tc_lo, test_lo_long_int_max);
    tcase_add_test(tc_lo, test_lo_oct_format);
    tcase_add_test(tc_lo, test_lo_too_short_buffer);
    tcase_add_test(tc_lo, test_lo_one_element_buffer);
    suite_add_tcase(s, tc_lo);

    TCase *tc_lx = tcase_create("lx");

    tcase_add_test(tc_lx, test_lx_default);
    tcase_add_test(tc_lx, test_lx_overflow_negative);
    tcase_add_test(tc_lx, test_lx_zero);
    tcase_add_test(tc_lx, test_lx_long_int_max);
    tcase_add_test(tc_lx, test_lx_hex_format);
    tcase_add_test(tc_lx, test_lx_too_short_buffer);
    tcase_add_test(tc_lx, test_lx_one_element_buffer);
    suite_add_tcase(s, tc_lx);

    TCase *tc_lld = tcase_create("lld");

    tcase_add_test(tc_lld, test_lld_default_positive);
    tcase_add_test(tc_lld, test_lld_default_negative);
    tcase_add_test(tc_lld, test_lld_zero);
    tcase_add_test(tc_lld, test_lld_long_long_int_min);
    tcase_add_test(tc_lld, test_lld_long_long_int_max);
    tcase_add_test(tc_lld, test_lld_too_short_buffer);
    tcase_add_test(tc_lld, test_lld_one_element_buffer);
    suite_add_tcase(s, tc_lld);

    TCase *tc_lli = tcase_create("lli");

    tcase_add_test(tc_lli, test_lli_default_positive);
    tcase_add_test(tc_lli, test_lli_default_negative);
    tcase_add_test(tc_lli, test_lli_zero);
    tcase_add_test(tc_lli, test_lli_long_long_int_min);
    tcase_add_test(tc_lli, test_lli_long_long_int_max);
    tcase_add_test(tc_lli, test_lli_too_short_buffer);
    tcase_add_test(tc_lli, test_lli_one_element_buffer);
    suite_add_tcase(s, tc_lli);

    TCase *tc_llo = tcase_create("llo");

    tcase_add_test(tc_llo, test_llo_default);
    tcase_add_test(tc_llo, test_llo_overflow_negative);
    tcase_add_test(tc_llo, test_llo_zero);
    tcase_add_test(tc_llo, test_llo_long_long_int_max);
    tcase_add_test(tc_llo, test_llo_oct_format);
    tcase_add_test(tc_llo, test_llo_too_short_buffer);
    tcase_add_test(tc_llo, test_llo_one_element_buffer);
    suite_add_tcase(s, tc_llo);

    TCase *tc_llx = tcase_create("llx");

    tcase_add_test(tc_llx, test_llx_default);
    tcase_add_test(tc_llx, test_llx_overflow_negative);
    tcase_add_test(tc_llx, test_llx_zero);
    tcase_add_test(tc_llx, test_llx_long_long_int_max);
    tcase_add_test(tc_llx, test_llx_hex_format);
    tcase_add_test(tc_llx, test_llx_too_short_buffer);
    tcase_add_test(tc_llx, test_llx_one_element_buffer);
    suite_add_tcase(s, tc_llx);

    return s;
}
