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
/**
 * print_err - a function that writes in the std output's array of characters
 * @data: a pointer to the program's data
 * @err: print error
 */
int print_err(int err, program_data *data)
{
	char n_as_string[10] = {'\0'};

	l_str((long) data->exe, n_as_string, 10);

	if (err == 2 || err == 3)
	{
		print(data->name);
		print(": ");
		print(n_as_string);
		print(": ");
		print(data->tokens[0]);
		if (err == 2)
			print(": Incorrect number: ");
		else
			print(": Failed to open ");
		print(data->tokens[1]);
		print("\n");
	}
	else if (err == 127)
	{
		print(data->name);
		print(": ");
		print(n_as_string);
		print(": ");
		print(data->name);
		print(": not found\n");
	}
	else if (err == 126)
	{
		print(data->name);
		print(": ");
		print(n_as_string);
		print(": ");
		print(data->name);
		print(": Permission denied\n");
	}
	return (0);
}
