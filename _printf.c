#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
*_printf - A function that prints according
*to a format
*@format: Pointer to string
*@...: A variable number of arguments
*
*Return: integer type
*/
int _printf(const char *format, ...)
{
	int count = 0;
	int value;
	va_list args;

	va_start(args, format);

	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					value = va_arg(args, int);
					count += write(1, &value, 1);
					break;
				case 's':
					count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, "%", 1);
					count += write(1, &(*format), 1);
					break;
			}
		}
		else
			count += write(1, &(*format), 1);
	}
	va_end(args);

	return (count);
}
