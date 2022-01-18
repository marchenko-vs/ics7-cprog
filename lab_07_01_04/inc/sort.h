#ifndef _SORT_H_

#define _SORT_H_

#include <stdlib.h>

int compare(const void *a, const void *b);
void swap(void *a, void *b, size_t size);
void mysort(void *base, size_t nmemb, size_t size,
int (*compar)(const void *, const void *));

#endif
