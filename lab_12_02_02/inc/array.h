#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdlib.h>

#ifdef ARRAY_EXPORTS
#define ARRAY_DLL __declspec(dllexport)
#else
#define ARRAY_DLL __declspec(dllimport)
#endif

#define ARRAY_DECL __cdecl

#define ERR_NULL_POINTER -1
#define ERR_ZERO_SIZE -2
#define ERR_MEMORY_ALLOC -3
#define ERR_SRC_ARRAY_SIZE -4

ARRAY_DLL int ARRAY_DECL a_fill_fibonacci(int *array, size_t size);
ARRAY_DLL int ARRAY_DECL a_rm_repetitions(int *array_src, size_t size_src, 
int *array_dst, size_t *size_dst);

#endif // _ARRAY_H_
