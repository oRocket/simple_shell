#include "shell.h"
/**
 * set_env - a function that sets environment of the shell
 * @data: program data struct
 * Return: 0 success
 */
int set_env(program_data *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->cmd);
		return (5);
	}

	env_set(data->tokens[1], data->tokens[2], data);
	return (0);
}
