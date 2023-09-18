#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}
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
