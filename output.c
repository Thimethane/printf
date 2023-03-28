#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            if (*format == 'c')
            {
                int c = va_arg(args, int);
                count += _putchar(c);
            }
            else if (*format == 's')
            {
                char *s = va_arg(args, char *);
                if (s == NULL)
                    s = "(null)";
                while (*s)
                {
                    count += _putchar(*s);
                    s++;
                }
            }
            else if (*format == '%')
            {
                count += _putchar('%');
            }
            else
            {
                count += _putchar('%');
                count += _putchar(*format);
            }
        }
        else
        {
            count += _putchar(*format);
        }

        format++;
    }

    va_end(args);

    return (count);
}
