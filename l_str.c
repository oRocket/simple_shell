#include "shell.h"

/**
 * l_str - a function that changes a number to a string.
 * @cocte: changed number to string.
 * @string: number to be saved as string.
 * @base: base
 * Return: No return.
 */
void l_str(long cocte, char *string, int base)
{
	int index = 0, Neg = 0;
	char num_word[] = {"0123456789abcdef"};

	if (cocte == 0)
		string[index++] = '0';

	if (string[0] == '-')
		Neg = 1;

	for (; cocte != 0; cocte /= base)
	{
		if (cocte < 0)
			string[index++] = num_word[-(cocte % base)];
		else
			string[index++] = num_word[cocte % base];
	}

	if (Neg)
		string[index++] = '-';

	string[index] = '\0';
	str_rev(string);
}
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
/**
 * c_xtr - a function that counts the character coincidences.
 * @string: pointer to str char
 * @xtr: character string
 * Return: counter
 */
int c_xtr(char *string, char *xtr)
{
	int i = 0, counter = 0;

	while (string[i] != '\0')
	{
		if (string[i] == xtr[0])
			counter++;
		i++;
	}

	return (counter);
}
