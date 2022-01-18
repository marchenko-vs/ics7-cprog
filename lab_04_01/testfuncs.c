#include "testfuncs.h"
#include "strfuncs.h"

void test_strpbrk(void)
{
    if (strpbrk("qw", "erqy") == my_strpbrk("qw", "erqy"))
        printf("Success\n");

    if (strpbrk("qw", "er") == my_strpbrk("qw", "er"))
        printf("Success\n");

    if (strpbrk("qw", "q") == my_strpbrk("qw", "q"))
        printf("Success\n");

    if (strpbrk("qw", "w") == my_strpbrk("qw", "w"))
        printf("Success\n");

    if (strpbrk("", "") == my_strpbrk("", ""))
        printf("Success\n");
}

void test_strspn(void)
{
    if (strspn("this is an example", "hti sa") ==
        my_strspn("this is an example", "hti sa"))
        printf("Success\n");

    if (strspn("qw", "er") == my_strspn("qw", "er"))
        printf("Success\n");

    if (strspn("qw", "q") == my_strspn("qw", "q"))
        printf("Success\n");

    if (strspn("qw", "w") == my_strspn("qw", "w"))
        printf("Success\n");

    if (strspn("", "") == my_strspn("", ""))
        printf("Success\n");
}

void test_strcspn(void)
{
    if (strcspn("qw", "erqy") == my_strcspn("qw", "erqy"))
        printf("Success\n");

    if (strcspn("qw", "er") == my_strcspn("qw", "er"))
        printf("Success\n");

    if (strcspn("qw", "q") == my_strcspn("qw", "q"))
        printf("Success\n");

    if (strcspn("qw", "w") == my_strcspn("qw", "w"))
        printf("Success\n");

    if (strcspn("", "") == my_strcspn("", ""))
        printf("Success\n");
}

void test_strchr(void)
{
    if (strchr("qw", 'q') == my_strchr("qw", 'q'))
        printf("Success\n");

    if (strchr("qw", 'w') == my_strchr("qw", 'w'))
        printf("Success\n");

    if (strchr("qw", ' ') == my_strchr("qw", ' '))
        printf("Success\n");

    if (strchr("", ' ') == my_strchr("", ' '))
        printf("Success\n");
}

void test_strrchr(void)
{
    if (strrchr("qw", 'q') == my_strrchr("qw", 'q'))
        printf("Success\n");

    if (strrchr("qw", 'w') == my_strrchr("qw", 'w'))
        printf("Success\n");

    if (strrchr("qw", ' ') == my_strrchr("qw", ' '))
        printf("Success\n");

    if (strrchr("", ' ') == my_strrchr("", ' '))
        printf("Success\n");
}
