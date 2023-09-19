#include "shell.h"

/**
 * count_digits - Count the number of digits in an integer.
 *
 * @n: The integer to count digits for.
 *
 * Return: The count of digits.
 */
int count_digits(int n)
{
	int count = 0;
	int num = n;

	while (num > 9 || num < -9)
	{
		num /= 10;
		count++;
	}

	return (count);
}

/**
 * int_to_string - Convert an integer to a string.
 *
 * @number: The integer to convert.
 *
 * Return: A string representation of the integer. Returns NULL if failed.
 */
char *int_to_string(int number)
{
	int digits, tens, i = 0, t = 0, x;
	char *res;

	digits = number;
	tens = 1;

	if (number < 0)
		t = 1;

	res = malloc(sizeof(char) * (count_digits(digits) + 2 + t));
	if (res == NULL)
		return (NULL);

	if (number < 0)
	{
		res[i] = '-';
		i++;
	}

	for (x = 0; digits > 9 || digits < -9; x++)
	{
		digits /= 10;
		tens *= 10;
	}

	while (x >= 0)
	{
		if (digits < 0)
		{
			res[i] = (digits / tens) * -1 + '0';
			i++;
		}
		else
		{
			res[i] = (digits / tens) + '0';
			i++;
		}

		digits %= tens;
		tens /= 10;
		x--;
	}

	res[i] = '\0';
	return (res);
}
