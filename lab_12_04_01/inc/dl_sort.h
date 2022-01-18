#ifndef _DL_SORT_H_
#define _DL_SORT_H_

#ifdef ARRAY_EXPORTS
#define ARRAY_DLL __declspec(dllexport)
#else
#define ARRAY_DLL __declspec(dllimport)
#endif

#define ARRAY_DECL __cdecl

#include <stdlib.h>

ARRAY_DLL void ARRAY_DECL mysort(void *base, size_t nmemb, size_t size,
int (*compar)(const void *, const void *));

#endif // _DL_SORT_H_
