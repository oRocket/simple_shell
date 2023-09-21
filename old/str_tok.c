#include "shell.h"
/**
 * star_tok - a function that separates strings
 * @line: pointer to an array
 * @del: characters
 * Return: A pointer
 */
char *str_tok(char *line, char *del)
{
	int j;
	static char *str;
	char *copystr;

	if (line != NULL)
		str = line;

	while (*str != '\0')
	{
		j = 0;
		while (del[j] != '\0')
		{
			if (*str == del[j])
				break;
			j++;
		}
		if (del[j] == '\0')
			break;
		str++;
	}
	copystr = str;

	if (*copystr == '\0')
		return (NULL);

	while (*str != '\0')
	{
		j = 0;
		while (del[j] != '\0')
		{
			if (*str == del[j])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
			j++;
		}
		str++;
	}
	return (copystr);
}
