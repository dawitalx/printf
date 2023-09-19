#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024


int _printf(const char *format, ...);
int _putchar(char c);
int print_number(int num);
int handle_format_specifier(va_list *args, char specifier);

int print_char(int c);

int print_string(char *str);



#endif /*MAIN_H*/
