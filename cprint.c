#include "shell.h"

/**
 * charP - cha to be checked
 *
 * Return - Characters
 *
 */

int cprint(const char *format, ...)
{
	int charP = 0;
	va_list list;
	
	if (format == NULL)
		return (-1);
	
	va_start(list, format);
	
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			charP++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == '%')
			{
				write(1, format, 1);
				charP++;
			}
			else if (*format == 'c')
			{
				char ch = va_arg(list, int);
				write(1, &ch, 1);
				charP++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(list, char *);
				write(1, s, strlen(s));
			}
			else if (*format == 'd' || *format == 'i')
			{
				int n = va_arg(list, int);
				char buffer[20];
				int len = snprintf(buffer, sizeof(buffer), "%d", n);
				write(STDOUT_FILENO, buffer, len);
			}
		}
		format++;
	}
	va_end(list);
	return (charP);
}
