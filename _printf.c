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
		return (0);
	}

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}


/**
 * numlen - Writes the length of a number
 * @num: number to calculate length
 *
 * Return: length of the number.
*/

int numlen(int num)
{
	if (num == 0)
		return (0);
	return (1 + numlen(num / 10));
}

/**
 * print_number - Writes the number n to stdout
 * @n: number to print
 *
 * Return: 0 on Success.
*/

int print_number(int n)
{
	if (n == -2147483648)
	{
		_putchar('-');
		_putchar('2');
		print_number(147483648);
	}
	else if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		print_number(n / 10);
		print_number(n % 10);
	}
	else if (n < 10)
	{
		_putchar(n + '0');
	}
	return (0);
}

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
