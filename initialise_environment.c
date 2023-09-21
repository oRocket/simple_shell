#include "shell.h"

/**
 * initialize_environment - Initializes environment variables
 * @data: data structure pointer
 * @env: environment
 */
void initialize_environment(program_data *data, char **env)
{
	int i = 0;

	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);

	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_d(env[i]);
		}
	}

	data->env[i] = NULL;
	env = data->env;
}
