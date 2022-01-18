#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>

void mysort(void *base, size_t nmemb, size_t size,
int (*compar)(const void *, const void *));

#endif
