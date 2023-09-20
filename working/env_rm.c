#include "shell.h"
/**
 * env_rm - a function that remove an environment key
 * @key: the key to be removed
 * @data: program's data
 * Return: 0 success
 */
int env_rm(char *key, program_data *data)
{
	int i = 0, key_len = 0;

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
