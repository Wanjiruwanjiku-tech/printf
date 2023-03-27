#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * _printf - prinf function with %c %s
 * @format: string
 * Return: count
 */
int _printf(const char *format, ...)
{
        int count = 0, i;
        char c, percent = '%';
        char *s;
        va_list av;

        va_start(av, format);

        for (i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%' && format[i] != '%')
                {
                        i++;
                        if (format[i] == 'c')
                        {
                                c = va_arg(av, int);
                                count += write(1, &c, 1);
                        }
                        else if (format[i] == 's')
                        {
                                s = va_arg(av, char*);
                                count += write(1, s, strlen(s));
					
                        }
			else if (format[i] == '%')
			{
				percent = va_arg(av, int);
				count += write(1, &percent, 1);
			}
			else
			{
				count += 0;
			}

                }
		else
		{
			write(1, &format[i], 1);
		}

        }
        va_end(av);
        return (count);
}


