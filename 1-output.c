#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
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
 * _printf - prints output according to a format
	@@ -11,62 +25,64 @@
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
				char *s = buffer;
				sprintf(buffer, "%d", num);
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
