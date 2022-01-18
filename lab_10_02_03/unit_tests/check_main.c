#include <check.h>
#include <stdlib.h>

Suite *free_list_suite(void);
Suite *print_list_number_suite(void);
Suite *push_back_suite(void);
Suite *decompose_number_suite(void);
Suite *square_number_suite(void);
Suite *multiply_numbers_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = free_list_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = print_list_number_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = push_back_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = decompose_number_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = square_number_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = multiply_numbers_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
