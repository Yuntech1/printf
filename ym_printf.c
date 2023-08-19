#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: pointer to string format
 *
 * Return: strings to the standard output
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				write(1, s, strlen(s));
				count += strlen(s);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int d = va_arg(args, int);
				char buffer[20];
				int len = snprintf(buffer, sizeof(buffer), "%d", d);

				write(1, buffer, len);
				count += len;
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
