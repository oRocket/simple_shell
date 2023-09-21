#include "shell.h"

/**
 * str_l - a function that returns string length
 * @string: pointer to string.
 * Authors: Albert and Benedict.
 * Return: length of string.
 */
int str_l(char *string)
{
	int len = 0;

	if (string == NULL)
		return (0);

	while (string[len++] != '\0')
	{
	}

	return (--len);
}
