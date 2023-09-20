#include "shell.h"

/**
 * str_l - a function that returns string length
 * @string: pointer to string.
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
/**
 * str_d - a function that duplicates a string
 * @string: String to be duplicated
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
/**
 * str_c - Compare two strings
 * @string1: String 1
 * @string2: String 2
 * @number: number of characters to be compared
 * Return: 1 if the strings are the same, otherwise 0
 */
int str_c(char *string1, char *string2, int number)
{
	int iterate = 0;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_l(string1) != str_l(string2))
			return (0);

		while (string1[iterate])
		{
			if (string1[iterate] != string2[iterate])
				return (0);
			iterate++;
		}

		return (1);
	}
	else
	{
		while (iterate < number)
		{
			if (string1[iterate] != string2[iterate])
				return (0);
			iterate++;
		}
		return (1);
	}
}
/**
 * str_ccat - a function that concatenates two strings.
 * @string1: String one
 * @string2: String two to be concatenated
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
/**
 * str_rev - a function that reverses a string.
 * @string: pointer to string.
 * Return: No return.
 */
void str_rev(char *string)
{
	int len = str_l(string) - 1;
	int i;
	char hold;

	for (i = 0; i < len; i++, len--)
	{
		hold = string[i];
		string[i] = string[len];
		string[len] = hold;
	}
}
