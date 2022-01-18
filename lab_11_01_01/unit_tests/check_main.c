#include <check.h>
#include <stdlib.h>

Suite *my_snprintf_suite(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = my_snprintf_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    if (no_failed == 0)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}
