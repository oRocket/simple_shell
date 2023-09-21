#include "shell.h"
/**
 * env_rm - a function that receives the environment variable value
 * @key: environment variable
 * @data: program's data struct
 * Authors: Albert and Benedict
 * Return: 0 success
 */
int env_rm(char *key, program_data *data)
{
	int i = 0;
	int key_len = 0; /* Added initialization for key_len */

	if (key == NULL || data->env == NULL)
		return (0);

	key_len = str_l(key);

	while (data->env[i])
	{
		if (str_c(key, data->env[i], key_len) &&
				data->env[i][key_len] == '=')
		{
			free(data->env[i]);
			i++;

			/* Replace the for loop with a while loop */
			while (data->env[i])
			{
				data->env[i - 1] = data->env[i];
				i++;
			}
			data->env[i - 1] = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}
