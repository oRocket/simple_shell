#include "shell.h"

#include <stdio.h>

/**
 * my_strlen - Calculate the length of a string.
 *
 * Authors: Albert and Benedict
 *
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t my_strlen(const char *str)
{
	size_t len = 0;

	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}
