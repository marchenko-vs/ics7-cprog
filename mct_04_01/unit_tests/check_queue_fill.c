#include <check.h>
#include <stdlib.h>
#include <stdlib.h>

#include "queue.h"

START_TEST(test_queue_fill_zero_elements)
{
    queue_t *queue = queue_init();

    int rc = queue_fill(queue, 0, 1);

    ck_assert_int_eq(rc, EXIT_SUCCESS);

    queue_free(queue);
}
END_TEST

START_TEST(test_queue_fill_one_element)
{
    queue_t *queue = queue_init();

    int data;
    queue_fill(queue, 1, -2);
    int rc = queue_peek(queue, &data);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(data, -2);

    queue_free(queue);
}
END_TEST

START_TEST(test_queue_fill_several_elements)
{
    queue_t *queue = queue_init();

    int data, rc;

    queue_fill(queue, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9);

    for (size_t i = 0; i < 9; i++)
    {
        rc = queue_pop(queue, &data);

        ck_assert_int_eq(rc, EXIT_SUCCESS);
        ck_assert_int_eq(data, i + 1);
    }
    
    queue_free(queue);
}
END_TEST

START_TEST(test_queue_fill_and_pop)
{
    queue_t *queue = queue_init();

    int data, rc;

    queue_fill(queue, 5, 1, 2, 3, 4, 5);

    rc = queue_pop(queue, &data);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(data, 1);

    queue_fill(queue, 2, 6, 7);

    for (size_t i = 0; i < 6; i++)
    {
        rc = queue_pop(queue, &data);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
        ck_assert_int_eq(data, i + 2);
    }

    queue_free(queue);
}
END_TEST

START_TEST(test_queue_fill_uninitialized)
{
    queue_t *queue = NULL;
    
    int rc = queue_fill(queue, 5, 1, 2, 3, 4, 5);

    ck_assert_int_eq(rc, EXIT_FAILURE);

    queue_free(queue);
}
END_TEST

Suite *queue_fill_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("queue_fill");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_queue_fill_zero_elements);
    tcase_add_test(tc_pos, test_queue_fill_one_element);
    tcase_add_test(tc_pos, test_queue_fill_several_elements);
    tcase_add_test(tc_pos, test_queue_fill_and_pop);

    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_queue_fill_uninitialized);

    suite_add_tcase(s, tc_neg);

    return s;
}
