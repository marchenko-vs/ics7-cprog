#include <check.h>
#include <stdlib.h>
#include <stdlib.h>

#include "queue.h"

START_TEST(test_queue_peek_one_element)
{
    queue_t *queue = queue_init();

    int data;
    queue_push(queue, -9);

    int rc = queue_peek(queue, &data);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(data, -9);

    queue_free(queue);
}
END_TEST

START_TEST(test_queue_peek_several_elements)
{
    queue_t *queue = queue_init();

    int data, rc;

    queue_push(queue, 5);
    queue_push(queue, 6);
    queue_push(queue, 7);
    queue_push(queue, 8);

    rc = queue_peek(queue, &data);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(data, 5);

    rc = queue_peek(queue, &data);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(data, 5);

    for (size_t i = 5; i < 9; i++)
    {
        rc = queue_peek(queue, &data);
        ck_assert_int_eq(rc, EXIT_SUCCESS);
        ck_assert_int_eq(data, i);
        queue_pop(queue, &data);
    }
    
    queue_free(queue);
}
END_TEST

START_TEST(test_queue_peek_and_push)
{
    queue_t *queue = queue_init();

    int data, rc;

    queue_push(queue, 4);
    queue_push(queue, 3);

    rc = queue_peek(queue, &data);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(data, 4);

    queue_push(queue, 2);
    queue_push(queue, 1);

    rc = queue_peek(queue, &data);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(data, 4);
    
    queue_free(queue);
}
END_TEST

START_TEST(test_queue_peek_uninitialized)
{
    queue_t *queue = NULL;

    int rc, data;
    
    rc = queue_peek(queue, &data);

    ck_assert_int_eq(rc, EXIT_FAILURE);

    queue_free(queue);
}
END_TEST

START_TEST(test_queue_peek_empty_queue)
{
    queue_t *queue = queue_init();

    int data, rc;
    
    rc = queue_peek(queue, &data);

    ck_assert_int_eq(rc, EXIT_FAILURE);

    queue_free(queue);
}
END_TEST

Suite *queue_peek_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("queue_peek");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_queue_peek_one_element);
    tcase_add_test(tc_pos, test_queue_peek_several_elements);
    tcase_add_test(tc_pos, test_queue_peek_and_push);

    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_queue_peek_uninitialized);
    tcase_add_test(tc_neg, test_queue_peek_empty_queue);

    suite_add_tcase(s, tc_neg);

    return s;
}
