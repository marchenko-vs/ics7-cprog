#include <stdlib.h>

#include "dl_sort.h"

static void swap(void *a, void *b, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        char buffer = *((char *)a + i);
        *((char *)a + i) = *((char *)b + i);
        *((char *)b + i) = buffer;
    }
}

ARRAY_DLL void ARRAY_DECL mysort(void *base, size_t nmemb, size_t size,
int (*compar)(const void *, const void *))
{
    int flag = 1;

    for (char *i = (char *)base; i < (char *)base + (nmemb - 1) * size;
        i += size)
    {
        flag = 0;

        for (char *j = (char *)base; j < (char *)base + (nmemb - 1) * size;
            j += size)
            if (compar(j, j + size) > 0)
            {
                swap(j, j + size, size);
                flag = 1;
            }

        for (char *j = (char *)base + (nmemb - 2) * size; j > i; j -= size)
            if (compar(j, j - size) < 0)
            {
                swap(j, j - size, size);
                flag = 1;
            }

        if (!flag)
            return;
    }
}
