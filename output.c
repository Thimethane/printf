#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to write
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * _print_char - Prints a single character to the standard output
 * @args: The va_list containing the character to print
 *
 * Return: The number of characters printed
 */
int _print_char(va_list args)
{
	char c = va_arg(args, int);
	return (_putchar(c));
}

/**
 * _print_string - Prints a string to the standard output
 * @args: The va_list containing the string to print
 *
 * Return: The number of characters printed
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}

	return (len);
}

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;
	int i;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				len += _print_char(args);
			else if (format[i] == 's')
				len += _print_string(args);
			else if (format[i] == '%')
			{
				_putchar('%');
				len++;
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				len += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}

	va_end(args);

	return (len);
}
