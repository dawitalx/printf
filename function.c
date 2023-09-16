#include "main.h"

void custom_print(int value) /* take s as input to the console */
/* @param str The string to be printed. */
{
char buffer[20]; /* A buffer to store the converted string */
int i = 0;

/* Handle negative values */
if (value < 0)
{
putchar('-');
value = -value;
}

/* Convert the integer to a string*/
if (value == 0)
{
buffer[i++] = '0';
}
else
{
while (value > 0)
{
buffer[i++] = '0' + (value % 10);
value /= 10;
}
}

/* Print the string in reverse order */
while (i > 0)
{
putchar(buffer[--i]);
}
}
int main(void)
{
int num = 42;
custom_print(num); /* Use custom_print to print the integer */
return (0);
}
