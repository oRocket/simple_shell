#include "shell.h"
/**
 * print_err - a function that writes in \n
 * the standard output's array of characters
 * @data: a pointer to the program's data
 * @err: print error
 * Authors: Albert and benedict
 * Return: No Return
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
