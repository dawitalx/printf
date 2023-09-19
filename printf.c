#include "main.h"

/**
 * _printf - print all with the formatted output
 * @format: the format
 * @...: the args
 * Return: Number of characters printed
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
			count += handle_format_specifier(&args, *format);
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

int handle_format_specifier(va_list *args, char specifier)
{
	switch (specifier)
	{
		case 'c':
			return (print_char(va_arg(*args, int)));
		case 's':
			return (print_string(va_arg(*args, char *)));
		case '%':
			_putchar('%');
			return (1);
		case 'd':
		case 'i':
			return (print_number(va_arg(*args, int)));
			return (0);
		default:
			_putchar('%');
			_putchar(specifier);
			return (2); /* Return 2 because we printed '%' and the unsupported specifier. */
	}
}

int print_char(int c)
{
	_putchar(c);
	return (1);
}

int print_string(char *str)
{
	int count = 0;
	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}

