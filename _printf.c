#include "main.h"
#include <stdarg.h>

/**
 * _printf -  produces output according to a format.
 * @format: character string.
 *
 * Return: the number of characters printed.
*/

int _printf(const char *format, ...)
{
	int counter = 0, number;
	va_list arguments_list;
	char c, *str;

	va_start(arguments_list, format);
	if (!format || !format[counter])
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				str = va_arg(arguments_list, char *);
				counter += print_string(str);
			}
			else if (*format == 'c')
			{
				c = va_arg(arguments_list, int);
				_putchar(c);
				counter++;
			}
			else if (*format == '%')
			{
				_putchar('%');
				counter++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				number = va_arg(arguments_list, int);
				if (number < 0)
					counter++;
				counter += numlen(number);
				print_number(number);
			}
			else
			{
				_putchar('%');
				counter++;
				if (*format)
				{
					_putchar(*format);
					counter++;
				}
			}
		}
		else
		{
			_putchar(*format);
			counter++;
		}
		format++;
	}
	return (counter);
}
