#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "my_snprintf.h"

int sizeof_int(int number, int base)
{
    if (number == 0)
        return 1;

    int length = 0;

    if (number < 0)
        length++;

    while (number != 0)
    {
        length++;
        number /= base;
    }

    return length;
}

int sizeof_short_int(short int number, int base)
{
    if (number == 0)
        return 1;

    int length = 0;

    if (number < 0)
        length++;

    while (number != 0)
    {
        length++;
        number /= base;
    }

    return length;
}

int sizeof_long_int(long int number, int base)
{
    if (number == 0)
        return 1;

    int length = 0;

    if (number < 0)
        length++;

    while (number != 0)
    {
        length++;
        number /= base;
    }

    return length;
}

int sizeof_long_long_int(long long number, int base)
{
    if (number == 0)
        return 1;

    int length = 0;

    if (number < 0)
        length++;

    while (number != 0)
    {
        length++;
        number /= base;
    }

    return length;
}

int sizeof_uint(unsigned int number, int base)
{
    if (number == 0)
        return 1;

    int length = 0;

    while (number != 0)
    {
        length++;
        number /= base;
    }

    return length;
}

int sizeof_short_uint(unsigned short int number, int base)
{
    if (number == 0)
        return 1;

    int length = 0;

    while (number != 0)
    {
        length++;
        number /= base;
    }

    return length;
}

int sizeof_long_uint(unsigned long number, int base)
{
    if (number == 0)
        return 1;

    int length = 0;

    while (number != 0)
    {
        length++;
        number /= base;
    }

    return length;
}

int sizeof_long_long_uint(unsigned long long number, int base)
{
    if (number == 0)
        return 1;

    int length = 0;

    while (number != 0)
    {
        length++;
        number /= base;
    }

    return length;
}

int print_int(char *buffer, int number,
size_t size, char *symbols, int base)
{
    int result_size = sizeof_int(number, base);
    int negative = 0;

    if (number < 0)
    {
        negative = 1;
        *buffer = '-';
        buffer++;
        result_size--;
    }

    char *ptr;

    if (result_size < size)
        ptr = buffer + result_size - 1;
    else
        ptr = buffer + size - 1;

    int i = 0;

    for (i = result_size - 1; i >= 0; i--)
    {
        if (i < size)
        {
            if (!negative)
                *ptr = symbols[number % base];
            else
                *ptr = symbols[-(number % base)];
            
            ptr--;
        }

        number /= base;
    }

    if (negative)
        result_size++;

    return result_size;
}

int print_short_int(char *buffer, short int number,
size_t size, char *symbols, int base)
{
    int result_size = sizeof_short_int(number, base);
    int negative = 0;

    if (number < 0)
    {
        negative = 1;
        *buffer = '-';
        buffer++;
        result_size--;
    }

    char *ptr;

    if (result_size < size)
        ptr = buffer + result_size - 1;
    else
        ptr = buffer + size - 1;

    int i = 0;

    for (i = result_size - 1; i >= 0; i--)
    {
        if (i < size)
        {
            if (!negative)
                *ptr = symbols[number % base];
            else
                *ptr = symbols[-(number % base)];
            
            ptr--;
        }

        number /= base;
    }

    if (negative)
        result_size++;

    return result_size;
}

int print_long_int(char *buffer, long int number,
size_t size, char *symbols, int base)
{
    int result_size = sizeof_long_int(number, base);
    int negative = 0;

    if (number < 0)
    {
        negative = 1;
        *buffer = '-';
        buffer++;
        result_size--;
    }

    char *ptr;

    if (result_size < size)
        ptr = buffer + result_size - 1;
    else
        ptr = buffer + size - 1;

    int i = 0;

    for (i = result_size - 1; i >= 0; i--)
    {
        if (i < size)
        {
            if (!negative)
                *ptr = symbols[number % base];
            else
                *ptr = symbols[-(number % base)];
            
            ptr--;
        }

        number /= base;
    }

    if (negative)
        result_size++;

    return result_size;
}

int print_long_long_int(char *buffer, long long number,
size_t size, char *symbols, int base)
{
    int result_size = sizeof_long_long_int(number, base);
    int negative = 0;

    if (number < 0)
    {
        negative = 1;
        *buffer = '-';
        buffer++;
        result_size--;
    }

    char *ptr;

    if (result_size < size)
        ptr = buffer + result_size - 1;
    else
        ptr = buffer + size - 1;

    int i = 0;

    for (i = result_size - 1; i >= 0; i--)
    {
        if (i < size)
        {
            if (!negative)
                *ptr = symbols[number % base];
            else
                *ptr = symbols[-(number % base)];
            
            ptr--;
        }

        number /= base;
    }

    if (negative)
        result_size++;

    return result_size;
}

int print_uint(char *buffer, unsigned int number, 
size_t size, char *symbols, int base)
{
    int result_size = sizeof_uint(number, base);
    char *ptr;

    if (result_size < size)
        ptr = buffer + result_size - 1;
    else
        ptr = buffer + size - 1;

    int i = 0;

    for (i = result_size - 1; i >= 0; i--)
    {
        if (i < size)
        {
            *ptr = symbols[number % base];
            ptr--;
        }

        number /= base;
    }

    return result_size;
}

int print_short_uint(char *buffer, unsigned short number, 
size_t size, char *symbols, int base)
{
    int result_size = sizeof_short_uint(number, base);
    char *ptr;

    if (result_size < size)
        ptr = buffer + result_size - 1;
    else
        ptr = buffer + size - 1;

    int i = 0;

    for (i = result_size - 1; i >= 0; i--)
    {
        if (i < size)
        {
            *ptr = symbols[number % base];
            ptr--;
        }

        number /= base;
    }

    return result_size;
}

int print_long_uint(char *buffer, unsigned long number, 
size_t size, char *symbols, int base)
{
    int result_size = sizeof_long_uint(number, base);
    char *ptr;

    if (result_size < size)
        ptr = buffer + result_size - 1;
    else
        ptr = buffer + size - 1;

    int i = 0;

    for (i = result_size - 1; i >= 0; i--)
    {
        if (i < size)
        {
            *ptr = symbols[number % base];
            ptr--;
        }

        number /= base;
    }

    return result_size;
}

int print_long_long_uint(char *buffer, unsigned long long number, 
size_t size, char *symbols, int base)
{
    int result_size = sizeof_long_long_uint(number, base);
    char *ptr;

    if (result_size < size)
        ptr = buffer + result_size - 1;
    else
        ptr = buffer + size - 1;

    int i = 0;

    for (i = result_size - 1; i >= 0; i--)
    {
        if (i < size)
        {
            *ptr = symbols[number % base];
            ptr--;
        }

        number /= base;
    }

    return result_size;
}

int print_string(char *buffer, char *string, size_t size)
{
    int result_size = 0;

    for (size_t i = 0; string[i] != '\0'; i++)
    {
        if (i < size)
            buffer[i] = string[i];

        result_size++;
    }

    return result_size;
}

int my_snprintf(char *restrict buffer, size_t size, 
const char *restrict format, ...)
{
    va_list vl;
    va_start(vl, format);

    if (buffer == NULL && size == 0)
        size = 1;

    if (size == 0)
        size = 1;

    int j = 0, i = 0, result_size = 0;
    int tmp = 0;

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;

            if (format[i] == 'c')
            {
                if (j < size - 1)
                    buffer[j++] = va_arg(vl, int);
                
                result_size++;
            }

            if (format[i] == 's')
            {
                tmp = print_string(buffer + j, 
                va_arg(vl, char *), size - j - 1);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'd' || format[i] == 'i')
            {
                tmp = print_int(buffer + j, va_arg(vl, int), 
                size - j - 1, DECIMAL, BASE_DEC);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'x')
            {
                tmp = print_uint(buffer + j, va_arg(vl, unsigned int), 
                size - j - 1, HEXADECIMAL, BASE_HEX);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'o')
            {
                tmp = print_uint(buffer + j, va_arg(vl, unsigned int), 
                size - j - 1, OCTAL, BASE_OCT);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'h' && 
                (format[i + 1] == 'd' || format[i + 1] == 'i'))
            {
                i++;

                tmp = print_short_int(buffer + j, va_arg(vl, int), 
                size - j - 1, DECIMAL, BASE_DEC);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'h' && format[i + 1] == 'x')
            {
                i++;

                tmp = print_short_uint(buffer + j, va_arg(vl, unsigned int), 
                size - j - 1, HEXADECIMAL, BASE_HEX);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'h' && format[i + 1] == 'o')
            {
                i++;

                tmp = print_short_uint(buffer + j, va_arg(vl, unsigned int), 
                size - j - 1, OCTAL, BASE_OCT);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'l' && 
                (format[i + 1] == 'd' || format[i + 1] == 'i'))
            {
                i++;

                tmp = print_long_int(buffer + j, va_arg(vl, long int), 
                size - j - 1, DECIMAL, BASE_DEC);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'l' && format[i + 1] == 'x')
            {
                i++;

                tmp = print_long_uint(buffer + j, va_arg(vl, unsigned long), 
                size - j - 1, HEXADECIMAL, BASE_HEX);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'l' && format[i + 1] == 'o')
            {
                i++;

                tmp = print_long_uint(buffer + j, va_arg(vl, unsigned long), 
                size - j - 1, OCTAL, BASE_OCT);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'l' && format[i + 1] == 'l' && 
                (format[i + 2] == 'd' || format[i + 2] == 'i'))
            {
                i += 2;

                tmp = print_long_long_int(buffer + j, va_arg(vl, long long), 
                size - j - 1, DECIMAL, BASE_DEC);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'l' && format[i + 1] == 'l' && 
                format[i + 2] == 'x')
            {
                i += 2;

                tmp = print_long_long_uint(buffer + j, 
                va_arg(vl, unsigned long long), 
                size - j - 1, HEXADECIMAL, BASE_HEX);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == 'l' && format[i + 1] == 'l' && format[i + 2] == 'o')
            {
                i += 2;

                tmp = print_long_long_uint(buffer + j, va_arg(vl, unsigned long long), 
                size - j - 1, OCTAL, BASE_OCT);

                result_size += tmp;

                if (result_size > size - j - 1)
                    j = size - 1;
                else
                    j += tmp;
            }

            if (format[i] == '%')
            {
                if (j < size - 1)
                    buffer[j++] = '%';
                
                result_size++;
            }
        }
        else
        {
            if (j < size - 1)
                buffer[j++] = format[i];
            
            result_size++;
        }
    }

    if (buffer != NULL)
        buffer[j] = '\0';

    va_end(vl);

    return result_size;
}
