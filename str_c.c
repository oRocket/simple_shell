#include "shell.h"
/**
 * str_c - Compare two strings
 * @string1: String 1
 * @string2: String 2
 * @number: number of characters to be compared
 * Author: Albert and Benedict
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
