#include "shell.h"
/**
 * unset_env - a function that unset environment of the shell
 * @data: data struct
 * Return: 0 success
 */
int unset_env(program_data *data)
{
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->cmd);
		return (5);
	}
	env_rm(data->tokens[1], data);

	return (0);
}
