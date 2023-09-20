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
				vc = str_d(env_get(nam_cp, data));
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
