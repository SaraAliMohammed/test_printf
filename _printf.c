#include "main.h"
#include <stdarg.h>

/**
 * print_string - Writes the string str to stdout
 * @str: string to print
 *
 * Return: length of the printed string.
*/

int print_string(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		print_string("(null)");
		return 0;
	}

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}

/**
 * _printf -  produces output according to a format.
 * @format: character string.
 *
 * Return: the number of characters printed.
*/

int _printf(const char *format, ...)
{
	int counter = 0;
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
			else
			{
				_putchar('%');
				counter++;
				if(*format)
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
}
