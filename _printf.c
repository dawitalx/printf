#include "main.h"

/**
* _printf - Print formatted output to stdout
* @format: The format string
*
* Return: Number of characters printed (excluding the null byte)
*/
int _printf(const char *format, ...)
{
va_list args;
int printed_chars = 0;
va_start(args, format);
while (format && *format)
{
if (*format == '%')
{
format++;
/* Move past the '%' */
/* Handle conversion specifiers */
switch (*format)
{
case 'c':
{
char c = va_arg(args, int);
/* char is promoted to int */
printed_chars += write(1, &c, 1);
break;
}
case 's':
{
char *s = va_arg(args, char *);
if (s == NULL)
s = "(null)";
while (*s)
{
printed_chars += write(1, s, 1);
s++;
}
break;
}
case '%':
printed_chars += write(1, "%", 1);
break;
default:
printed_chars += write(1, "%", 1);
/* Handle unsupported specifiers as % */
if (*format)
printed_chars += write(1, format, 1);
break;
}
}
else
{
printed_chars += write(1, format, 1);
}
format++;
}
va_end(args);
return (printed_chars);
}
