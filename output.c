#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_char - prints a character
 *
 * @args: list of arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int _print_char(va_list args)
{
	int count = 0;

	count += _putchar(va_arg(args, int));
	return (count);
}

/**
 * _print_string - prints a string
 *
 * @args: list of arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int _print_string(va_list args)
{
	int count = 0;
	char *s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		count += _putchar(*s);
		s++;
	}
	return (count);
}

/**
 * _print_number - prints a number
 *
 * @args: list of arguments
 *
 * Return: number of characters printed (excluding the null byte)
 */
int _print_number(va_list args)
{
	int count = 0, num = va_arg(args, int);
	char buffer[12], *s = buffer;

	sprintf(buffer, "%d", num);
	while (*s)
	{
		count += _putchar(*s);
		s++;
	}
	return (count);
}

/**
 * _printf - prints output according to a format
 *
 * @format: format string
 * @...: list of arguments
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
				count += _print_char(args);
			else if (*format == 's')
				count += _print_string(args);
			else if (*format == 'd' || *format == 'i')
				count += _print_number(args);
			else if (*format == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		else
			count += _putchar(*format);
		format++;
	}

	va_end(args);

	return (count);
}
