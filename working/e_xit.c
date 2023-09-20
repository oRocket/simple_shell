#include "shell.h"

/**
 * builtin_exit - a function that exit a program
 * @data: program data struct
 * Return: 0 success
 */
int e_xit(program_data *data)
{
	int i = 0;

	if (data->tokens[1] != NULL)
	{
		while (data->tokens[1][i])
		{
			if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
					&& data->tokens[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
			i++;
		}
		errno = a_toi(data->tokens[1]);
	}
	free_data(data);
	exit(errno);
}
