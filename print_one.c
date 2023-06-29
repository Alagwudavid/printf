#include "main.h"

/**
  * _print_format - Prints a format
  * @format: The format to prints
  * @args: A list of variadic arguments
  *
  * Return: The length of the format
  */
int _printf(const char *format, ...){
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format){
		if (*format == '%')
		{
			format++;

			// Handle the conversion specifiers
		switch (*format)
		{
			case 'c':
				{
					char c = (char)va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
			case 's':
				{
					char *str = va_arg(args, char *);
					while (*str)
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				}
			case '%':
				{
					putchar('%');
					count++;
					break;
				}
		}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return count;
}
