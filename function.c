#include "main.h"

/**
 * _putchar  - The char to be written.
 *
 * @c: The character to be processed.
 *  This function takes a character "c" and writes it to the standard output
 * Return: 1 if succesful else -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * *print_number - The int to be printed.
 *
 * @num: int
 * This function takes an integer as a parameter and prints it
 * Return: if num < 0 result '-', else 0
 */
char *print_number(int num)
{
	static char numi[1024];
	int divisor = 1;
	char *result = numi;

	if (num < 0)
	{
		*result = '-';
		result++;
		num = -num;
	}
	while (num / divisor >= 10)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		int digit = num / divisor;
		*result = '0' + digit;
		result++;
		num %= divisor;
		divisor /= 10;
	}
		*result = '\0';
		return (numi);
}
