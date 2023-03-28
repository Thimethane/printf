#include "main.h"
#include <stdio.h>
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
                char *s;
                sprintf(buffer, "%d", num);
                s = buffer;
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
