#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format - character string
 *
 * Return: number of character printed
 */

int _printf(const char *format, ...)
{
	va_list f_list;
	int char_count = 0;

	if (format == NULL)
		return (-1);

	va_start(f_list, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_count++;
		}
		else
		{
			format++;
			if (*format == '\0')	
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				char_count++;
			}
			else if (*format == 'c')
			{
				char c  = va_arg(f_list, int)
				write(1, &c, 1);
				char_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(f_list, char*);
				int str-len = 0;

				while (str[str_len] != '\0')
					str_len++;
				write(1, str, str_len);
				char_count += str_len;
			}
		}
		format++;
	}
	va_end(f_list);
	return char_count;
}
