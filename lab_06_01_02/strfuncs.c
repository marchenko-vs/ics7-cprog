#include "strfuncs.h"
#include <string.h>

int str_begins(const char *const string_1, const char *const string_2)
{
    char *position_ptr = strstr(string_1, string_2);

    if (position_ptr == NULL)
        return NO_SUBSTRING_FOUND;

    return position_ptr - string_1;
}
