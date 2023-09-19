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
int print_number(int num)
{
	int count = 0;
	int digits = 0;
	int divisor = 1;
	int temp = 0;
	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	temp = num;	
	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}

	for (; digits > 1; digits--)
	{
		divisor *= 10;
	}

	while (divisor > 0)
	{
		int digit = num / divisor;
		_putchar('0' + digit);
		count++;
		num %= divisor;
		divisor /= 10;
	}

	return (count);
}
/**
 * print_binary - Prints an unsigned integer in binary format.
 * @num: The unsigned integer to be printed.
 * Return: The number of binary digits printed.
 */
int print_binary(unsigned int num)
{
	int num_digits = 0;
	unsigned int mask = 1 << 31; /* start with the leftmost bit */

	while (mask > 0)
	{
		putchar((num & mask) ? '1' : '0');
		mask >>= 1; /*move the mask to the right */
		num_digits++;
	}
	if (num_digits == 0) /* Edge case for num == 0 */
	{
		putchar('0');
		num_digits = 1;
	}
	return (num_digits);
}
/**
 * print_hexadecimal - Prints an unsigned integer in hexadecimal format.
 * @num: The unsigned integer to print.
 * @uppercase: Indicates whether to use uppercase letters (X) or lowercase (x).
 * Return: The number of characters printed.
 */
int print_hexadecimal(unsigned int num, int uppercase)
{
	const char *hex_digits = (uppercase) ?
		"0123456789ABCDEF" : "0123456789abcdef";
	char buffer[32];
	int count = 0, i = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}
	while (num != 0)
	{
		buffer[i] = hex_digits[num % 16];
		num /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		_putchar(buffer[i]);
		count++;
	}
	return (count);
}
