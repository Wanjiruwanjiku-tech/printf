#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int num_chars_printed = 0;
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                num_chars_printed++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                int len = 0;
                while (str[len] != '\0')
                {
                    len++;
                }
                write(1, str, len);
                num_chars_printed += len;
            }
            else if (*format == '%')
            {
                write(1, "%", 1);
                num_chars_printed++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                char num_str[12]; // maximum number of digits in a 32-bit integer plus null byte
                sprintf(num_str, "%d", num);
                int len = 0;
                while (num_str[len] != '\0')
                {
                    len++;
                }
                write(1, num_str, len);
                num_chars_printed += len;
            }
        }
        else
        {
            write(1, format, 1);
            num_chars_printed++;
        }
        format++;
    }

    va_end(args);

    return num_chars_printed;
}