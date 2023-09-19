#include "main.h"

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

int print_char(int c)
{
	_putchar(c);
	return (1);
}
