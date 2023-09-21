#include "shell.h"

/**
 * _env - a function that reveals the environment of the shell
 * @data: program data struct
 * Return: 0 success
 */
int _env(program_data *data)
{
	int i = 0;
	char nam_cp[50] = {'\0'};
	char *vc = NULL;

	if (data->tokens[1] == NULL)
		_environmt(data);
	else
	{
		while (data->tokens[1][i])
		{
			if (data->tokens[1][i] == '=')
			{
				vc = str_d(env_key(nam_cp, data));
				if (vc != NULL)
					env_set(nam_cp, data->tokens[1] + i + 1, data);

				_environmt(data);
				if (env_key(nam_cp, data) == NULL)
				{
					print_f(data->tokens[1]);
					print_f("\n");
				}
				else
				{
					env_set(nam_cp, vc, data);
					free(vc);
				}
				return (0);
			}
			nam_cp[i] = data->tokens[1][i];
			i++;
		}
		errno = 2;
		perror(data->cmd);
		errno = 127;
	}
	return (0);
}
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
