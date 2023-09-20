#include "shell.h"
/**
 * a_toi - a function that converts a string to an integer.
 * @s: pointer to string integer.
 * Return: 0 otherwise integer of string.
 */
int a_toi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	for (; '0' <= *s && *s <= '9' && *s != '\0'; s++)
	{
		num = (num * 10) + (*s - '0');
	}

	return (num * sign);
}
