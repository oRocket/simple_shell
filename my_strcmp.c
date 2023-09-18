#include "shell.h"
/**
 * my_strcmp - Compare two strings lexicographically.
 *
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Authors: Albert and Benedict.
 *
 * Return: 0 if the strings are equal, a negative value if str1 is
 */
int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return ((*str1 < *str2) ? -1 : 1);
		}
		str1++;
		str2++;
	}

	if (*str1 == '\0' && *str2 == '\0')
	{
		return (0); /* Strings are equal */
	}
	else if (*str1 == '\0')
	{
		return (-1); /* str1 is shorter */
	}
	else
	{
		return (1); /* str2 is shorter */
	}
}
