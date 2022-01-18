#ifndef _STRFUNCS_H_

#define _STRFUNCS_H_

#include <string.h>
#include <stdio.h>

char *my_strpbrk(char *s, const char *accept);
size_t my_strspn(const char *s, const char *accept);
size_t my_strcspn(const char *s, const char *reject);
char *my_strchr(char *s, int c);
char *my_strrchr(char *s, int c);

#endif
