#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_unsigned - prints an unsigned integer
 * @n: the unsigned integer to print
 * @base: the base to print the number in
 * @digits: the digits to use for the base
 *
 * Return: the number of digits printed
 */
int print_unsigned(unsigned int n, int base, char *digits)
{
    int count = 0;

    if (n / base)
        count += print_unsigned(n / base, base, digits);

    count += putchar(digits[n % base]);

    return (count);
}

/**
 * _printf - prints output according to a format
 * @format: the format string
 *
 * Return: the number of characters printed
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
                if (num < 0)
                {
                    count += putchar('-');
                    num = -num;
                }
                count += print_unsigned(num, 10, "0123456789");
            }
            else if (*format == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_unsigned(num, 10, "0123456789");
            }
            else if (*format == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_unsigned(num, 8, "01234567");
            }
            else if (*format == 'x')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_unsigned(num, 16, "0123456789abcdef");
            }
            else if (*format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                count += print_unsigned(num, 16, "0123456789ABCDEF");
            }
            else if (*format == '%')
            {
                count += putchar('%');
            }
            else
            {
                count += putchar('%');
                count += putchar(*format);
            }
        }
        else
        {
            count += putchar(*format);
        }

        format++;
    }

    va_end(args);

    return (count);
}
