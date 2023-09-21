#include "shell.h"

/**
 * buffer_sum - a function that appends a string
 * @buffer: filled buffer
 * @str_sum: copied string
 * Authors: Albert and Benedict
 * Return: No return
 */
int buffer_sum(char *buffer, char *str_sum)
{
	int len;
	int i;

	len = str_l(buffer);
	i = 0;

	while (str_sum[i])
	{
		buffer[len + i] = str_sum[i];
		i++;
	}
	buffer[len + i] = '\0';

	return (len + i);
}
