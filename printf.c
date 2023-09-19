#include "main.h"

/**
 * _printf - print all with the formmated output
 * @format: the format
 * @...: the args
 * Return: 0 or NULL
 */
int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	va_list args;
	char chr;
	char *str;
	int count = 0;
	int num = 0;
	char *number;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break; /* avoid undefined behaviour for "%" */
			if (*format == 'c')
			{
				char chr = va_arg(args, int);

				_putchar(chr);
				count++;

			}
			else if (*format == 's')
			{
				char str = va_arg(args, char*);

				while (*str)
				{
					_putchar(*str);
					str++;
					count++;
				}
			}
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				char *number = print_number(num);

				while (*number)
				{
					_putchar(*number);
					number++;
					count++;
				}
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				count += 2;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}
