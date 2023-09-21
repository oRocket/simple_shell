#include "shell.h"
/**
 * str_ccat - a function that concatenates two strings.
 * @string1: String one
 * @string2: String two to be concatenated
 *
 * Author: Albert and Benedict
 * Return: pointer
 */
char *str_ccat(char *string1, char *string2)
{
	char *rslt;
	int len1 = 0, len2 = 0, i, j;

	if (string1 == NULL)
		string1 = "";
	len1 = str_l(string1);

	if (string2 == NULL)
		string2 = "";
	len2 = str_l(string2);

	rslt = malloc(sizeof(char) * (len1 + len2 + 1));
	if (rslt == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	i = 0;
	while (string1[i] != '\0')
	{
		rslt[i] = string1[i];
		i++;
	}
	free(string1);

	j = 0;
	while (string2[j] != '\0')
	{
		rslt[i] = string2[j];
		i++;
		j++;
	}

	rslt[i] = '\0';
	return (rslt);
}
