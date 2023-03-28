#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - prints output to stdout according to a given format
 * @format: format string
 *
 * Return: number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *p = format;

    va_start(args, format);
    while (*p != '\0')
    {
        if (*p == '%')
        {
            p++;
            switch (*p)
            {
                case 'c':
                {
                    int value = va_arg(args, int);
                    count += write(1, &value, sizeof(int));
                    break;
                }
                case 's':
                {
                    char *str = va_arg(args, char *);
                    count += write(1, str, strlen(str));
                    break;
                }
                case '%':
                    count += write(1, "%", 1);
                    break;
            }
        }
        else
        {
            count += write(1, p, 1);
        }
        p++;
    }

    va_end(args);

    return count;
}
