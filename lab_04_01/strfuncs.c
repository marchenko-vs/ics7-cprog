#include "strfuncs.h"

char *my_strpbrk(char *s, const char *accept)
{
    int i = 0;

    while (s[i] != '\0')
    {
        int j = 0;

        while (accept[j] != '\0')
        {
            if (s[i] == accept[j])
                return &s[i];

            j++;
        }

        i++;
    }

    return NULL;
}

size_t my_strspn(const char *s, const char *accept)
{
    int i = 0, size = 0;

    while (s[i] != '\0')
    {
        int j = 0;

        while (accept[j] != '\0')
        {
            if (s[i] == accept[j])
            {
                size++;
                break;
            }

            j++;

            if (accept[j] == '\0')
                return size;
        }

        if (size == 0)
            return 0;

        i++;
    }

    return size;
}

size_t my_strcspn(const char *s, const char *reject)
{
    int i = 0, size = 0;

    while (s[i] != '\0')
    {
        int j = 0;

        while (reject[j] != '\0')
        {
            if (s[i] == reject[j])
                return size;

            j++;
        }

        size++;
        i++;
    }

    return size;
}

char *my_strchr(char *s, int c)
{
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == (char) c)
            return &s[i];

        i++;
    }

    if (s[i] == (char) c)
        return &s[i];

    return NULL;
}

char *my_strrchr(char *s, int c)
{
    int i = 0;
    char *result = NULL;

    while (s[i] != '\0')
    {
        if (s[i] == (char) c)
            result = &s[i];

        i++;
    }

    if (s[i] == (char) c)
        result = &s[i];

    if (result == NULL)
        return NULL;

    return result;
}
