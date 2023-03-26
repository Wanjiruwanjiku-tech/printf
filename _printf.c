g#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int count = 0, i;
	char c;
	char *s;
	va_list av;

	va_start(av, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(av, int);
				putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(av, char*);
				while (*s != '\0')
				{
					putchar(*s);
					count++;
				}
			}


		}
		else
		{
			putchar(format[i]);
		}

	}
	va_end(av);
	return (count);
}
