#include <check.h>
#include <stdlib.h>
#include "check_funcs.h"

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = m_multiply_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    s = m_power_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    
    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
