#include <stdio.h>
#include <stdarg.h>

/**
*_printf - A Function that handled the conversion
*specifiers d and i
*@format: A pointer to the character string
*@...: A variable number of variables
*Return: integer type
*/
int _printf(const char *format, ...)
{
	va_list args; /*The variable holds the '(...)' arguments*/
	int count; /*Keep track of number of printed characters*/
	char c; /* To print next arg when'%c' is 3ncountered*/
	char *s; /*To print next arg when'%s' is 3ncountered*/
	int num; /*To print next arg when'%d or %i' is encountered*/
	int i; /*Loop counter for the array digits*/
	int digits[10];

	va_start(args, format);

	count = 0;

	while (*format) /*Iterate through format str*/
	{
		if (*format == '%')
		{
			/*if we get '%'*/
			format++; /*Move to next char*/

			if (*format == 'c')
			{
				c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char*);
				/*iterate s to print string char by char*/
				while (*s)
				{
					putchar(*s++);
					count++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				num = va_arg(args, int);

				if (num < 0)
				{
					/*check if negative*/
					putchar('-');
					count++;
					num = -num;
				}
				if (num == 0)
				{
					putchar('0');
					count++;
				}
				else
				{
					i = 0;

					while (num > 0)
					{
						digits[i] = num % 10;
						num /= 10;
						i++;
					}
					putchar(digits[i] + '0');
					count++;
				}
			}
		}
		else
		{
			/*if char is not '%'*/
			putchar(*format);
			count++;
		}
		format++;
		putchar('\n');
	}
	va_end(args); /*Clean up va_list*/

	return (count); /*return num of printed char*/
}
