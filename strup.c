#include "shell.h"

/**
 * custom_strdup - Duplicate a string and return a pointer to the duplicated string.
 *
 * @str: The string to duplicate.
 *
 * Return: A pointer to the duplicated string in allocated memory.
 */
char *custom_strdup(const char *str)
{
	char *duplicate_str;
	int len = 0;

	if (str == NULL) /* Validate str input */
		return (NULL);

	while (str[len] != '\0')
		len++;

	len++; /* Add null terminator to length */

	duplicate_str = malloc(sizeof(char) * len); /* Allocate memory */
	if (duplicate_str == NULL)
		return (NULL);

	for (int i = 0; i < len; i++)
		duplicate_str[i] = str[i];

	return duplicate_str;
}
