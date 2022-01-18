#include <check.h>
#include <stdlib.h>
#include <stdlib.h>

#include "queue.h"

START_TEST(test_queue_push_one_element)
{
    queue_t *queue = queue_init();

    int data;
    queue_push(queue, 5);
    int rc = queue_peek(queue, &data);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(data, 5);

    queue_free(queue);
}
END_TEST

START_TEST(test_queue_push_several_elements)
{
    queue_t *queue = queue_init();

    int data, rc;

    queue_push(queue, 0);
    queue_push(queue, 1);
    queue_push(queue, 2);
    queue_push(queue, 3);

    for (size_t i = 0; i < 4; i++)
    {
        rc = queue_pop(queue, &data);

        ck_assert_int_eq(rc, EXIT_SUCCESS);
        ck_assert_int_eq(data, i);
    }
    
    queue_free(queue);
}
END_TEST

START_TEST(test_queue_push_and_pop)
{
    queue_t *queue = queue_init();

    int data, rc;

    queue_push(queue, 0);
    queue_push(queue, 1);
    queue_pop(queue, &data);
    queue_push(queue, 2);
    queue_pop(queue, &data);
    
    rc = queue_pop(queue, &data);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(data, 2);
    
    queue_free(queue);
}
END_TEST

START_TEST(test_queue_push_uninitialized)
{
    queue_t *queue = NULL;
    
    int rc = queue_push(queue, 5);

    ck_assert_int_eq(rc, EXIT_FAILURE);

    queue_free(queue);
}
END_TEST

Suite *queue_push_suite(void)
{
    Suite *s;
    TCase *tc_pos, *tc_neg;

    s = suite_create("queue_push");
    tc_pos = tcase_create("positives");
    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_pos, test_queue_push_one_element);
    tcase_add_test(tc_pos, test_queue_push_several_elements);
    tcase_add_test(tc_pos, test_queue_push_and_pop);

    suite_add_tcase(s, tc_pos);

    tcase_add_test(tc_neg, test_queue_push_uninitialized);

    suite_add_tcase(s, tc_neg);

    return s;
}
