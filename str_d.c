#include "shell.h"

/**
 * str_d - a function that duplicates a string
 * @string: String to be duplicated
 * Authors: Benedict and Albert
 * Return: pointer to the array
 */
char *str_d(char *string)
{
	char *rslt;
	int i = 0, len;

	if (string == NULL)
		return (NULL);

	len = str_l(string) + 1;

	rslt = malloc(sizeof(char) * len);

	if (rslt == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	while (i < len)
	{
		rslt[i] = string[i];
		i++;
	}

	return (rslt);
}
