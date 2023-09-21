#include "shell.h"

/**
 * env_key - A function that gets the environment variable value
 * @key: the environment variable
 * @data: program's data
 * Return: NULL
 */
char *env_key(char *key, program_data *data)
{
	int i = 0, key_len = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_len = str_l(key);

	while (data->env[i] != NULL)
	{
		if (str_c(key, data->env[i], key_len) && data->env[i][key_len] == '=')
		{
			return (data->env[i] + key_len + 1);
		}
		i++;
	}
	return (NULL);
}
