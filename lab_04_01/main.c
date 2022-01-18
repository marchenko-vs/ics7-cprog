#include "strfuncs.h"
#include "testfuncs.h"
#include <stdlib.h>

int main(void)
{
    test_strpbrk();
    printf("\n");

    test_strspn();
    printf("\n");

    test_strcspn();
    printf("\n");

    test_strchr();
    printf("\n");

    test_strrchr();

    return EXIT_SUCCESS;
}
