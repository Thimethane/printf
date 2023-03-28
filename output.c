#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to write
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
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

            if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                char buffer[20];
                int i = 0;
                if (num == 0)
                {
                    count += _putchar('0');
                }
                else if (num < 0)
                {
                    count += _putchar('-');
                    num = -num;
                }
                while (num != 0)
                {
                    buffer[i++] = (num % 10) + '0';
                    num /= 10;
                }
                while (i > 0)
                {
                    count += _putchar(buffer[--i]);
                }
            }
            else if (*format == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                char buffer[20];
                int i = 0;
                if (num == 0)
                {
                    count += _putchar('0');
                }
                while (num != 0)
                {
                    buffer[i++] = (num % 10) + '0';
                    num /= 10;
                }
                while (i > 0)
                {
                    count += _putchar(buffer[--i]);
                }
            }
            else if (*format == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                char buffer[20];
                int i = 0;
                if (num == 0)
                {
                    count += _putchar('0');
                }
                while (num != 0)
                {
                    buffer[i++] = (num % 8) + '0';
                    num /= 8;
                }
                while (i > 0)
                {
                    count += _putchar(buffer[--i]);
                }
            }
            else if (*format == 'x' || *format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                char buffer[20];
                int i = 0;
                char *format_str = (*format == 'x') ? "%x" : "%X";
                if (num == 0)
                {
                    count += _putchar('0');
                }
                while (num != 0)
                {
                    buffer[i++] = (num % 16 < 10) ? (num % 16 + '0') : (num % 16 - 10 + 'a');
                    num /= 16;
                }
                while (i > 0)
                {
                    count += _printf(format_str, buffer[--i]);
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

    return count;
}
