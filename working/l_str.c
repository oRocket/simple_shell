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
