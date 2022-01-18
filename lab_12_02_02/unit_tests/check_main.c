#include <check.h>
#include <stdlib.h>

Suite *a_fill_fibonacci_suite(void);
Suite *a_rm_repetitions_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = a_fill_fibonacci_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = a_rm_repetitions_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
