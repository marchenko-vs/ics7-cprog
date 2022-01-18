#ifndef _MY_SNPRINTF_H_
#define _MY_SNPRINTF_H_

#include <stdlib.h>

#define DECIMAL "0123456789"
#define OCTAL "01234567"
#define HEXADECIMAL "0123456789abcdef"

#define BASE_DEC 10
#define BASE_OCT 8
#define BASE_HEX 16

int my_snprintf(char *restrict buffer, size_t size, 
const char *restrict format, ...);

#endif // _MY_SNPRINTF_H_
