#include "shell.h"

/**
 * str_rev - a function that reverses a string.
 * @string: pointer to string.
 * Authors: Albert and Benedict.
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
