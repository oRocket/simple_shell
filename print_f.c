#include "shell.h"

/**
 * print_f - a function that writes in the std output's array of characters
 * @string: pointer to the array of chars
 * Return: the number of bytes otherwise -1
 */
int print_f(char *string)
{
	return (write(STDOUT_FILENO, string, str_l(string)));
}

/**
 * print - a function that writes in the std output's array of characters
 * @string: pointer to the array of chars
 * Return: the number of bytes otherwise -1
 */
int print(char *string)
{
	return (write(STDERR_FILENO, string, str_l(string)));
}
