#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
 * print_binary - prints a number in binary form
 * @n: the number to print
 *
 * Return: the number of digits printed
 */
int print_binary(unsigned int n)
{
    int count = 0;

    if (n > 1)
        count += print_binary(n >> 1);

    count += _putchar((n & 1) + '0');

    return (count);
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
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                char buffer[12];
                sprintf(buffer, "%d", num);
                char *s = buffer;
                while (*s)
                {
                    count += _putchar(*s);
                    s++;
                }
            }
            else if (*format == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_binary(num);
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
