#include <stdarg.h>  // for variable arguments list
#include <stdio.h>   // for printf, sprintf, snprintf
#include <stdlib.h>  // for malloc, free
#include <string.h>  // for strlen, strncpy
#include <unistd.h>  // for write

/**
 * _printf - Custom implementation of printf function
 * @format: String that specifies the format of the output
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;         // Total number of characters printed
    va_list args;          // Variable argument list
    const char *p = format; // Pointer to traverse the format string

    va_start(args, format);

    while (*p != '\0') // Traverse the format string until end-of-string
    {
        if (*p == '%') // Found a format specifier
        {
            p++; // Move past the '%'

            // Check the format specifier and perform the corresponding action
            switch (*p)
            {
                case 'c': // Character
                    {
                        char c = va_arg(args, int);
                        count += write(1, &c, 1);
                        break;
                    }

                case 's': // String
                    {
                        char *s = va_arg(args, char *);
                        count += write(1, s, strlen(s));
                        break;
                    }

                case '%': // Percent sign
                    {
                        count += write(1, "%", 1);
                        break;
                    }

                default: // Unknown format specifier
                    {
                        count += write(1, "%", 1);
                        count += write(1, &(*p), 1);
                        break;
                    }
            }
        }
        else // Regular character
        {
            count += write(1, &(*p), 1);
        }

        p++; // Move to the next character in the format string
    }

    va_end(args); // End variable argument list

    return count; // Return total number of characters printed
}
