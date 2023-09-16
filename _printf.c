#include "main.h"

int print_char(char c)
{
return (write(1, &c, 1));
}

int print_str(const char *str)
{
int len = 0;
while (str[len])
{
len++;
}
return (write(1, str, len));
}

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;

while (*format)
{
if (*format == '%')
{
format++;
if
(*format == '\0') break;
switch (*format)
{
case 'c':
count += print_char(va_arg(args, int));
break;
case 's':
count += print_str(va_arg(args, const char*));
break;
case '%':
count += print_char('%');
break;
default:
/* Handle unsupported format specifiers here (if needed) */
break;
}
}
else
{
count += print_char(*format);
}

format++;
}

va_end(args);
return (count);
}

int main(void)
{
int chars_printed = _printf("Hello, %s! answer is %d%c\n", "world", 42, '%');
_printf("\nTotal characters printed: %d\n", chars_printed);
return (0);
}
