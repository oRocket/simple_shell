#include "shell.h"
/**
 * env_set - a function that overwrite the environment variable value
 * @key: variable name
 * @value: new value
 * @data: program's data struct
 * Authors: Albert and Benedict
 * Return: 0 success
 */

int env_set(char *key, char *value, program_data *data)
{
	int i = 0, key_len = 0, new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_len = str_l(key);

	while (data->env[i])
	{
		if (str_c(key, data->env[i], key_len) &&
				data->env[i][key_len] == '=')
		{
			new_key = 0;
			free(data->env[i]);
			break;
		}
		i++;
	}
	data->env[i] = str_ccat(str_d(key), "=");
	data->env[i] = str_ccat(data->env[i], value);

	if (new_key)
	{
		data->env[i + 1] = NULL;
	}
	return (0);
}
