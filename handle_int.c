#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
/**
 * handle_int - handle int in printf
 * @format: string
 * Return: count
 */
int handle_int(const char *format, ...)
{
	int count = 0, i;

	va_list av;

	for (i = 0; *format != '\0'; i++)
	{
		if (*format == '%')
		{
			format++;
			count++;
			switch (*format)
			{
				case 'i':
				case 'd':
					{
						char buffer[40];

						sprintf(buffer, "%d", va_arg(av, int));
						count += write(1, buffer, sizeof(buffer));
						break;

					}
				default:
					count += write(1, "%", 1);
					count += write(1, &(*format), 1);
					break;
			}

		}
		else
		{
			count += write(1, &(*format), 1);
		}

	}
	va_end(av);
	return (count);

}
