#include "shell.h"
/**
 * start_d - a function that receives the environment variable value
 * @key: environment variable
 * @data: program's data struct
 * Return: 0 success
 */
char *start_d(char *key, program_data *data)
{
	int i = 0, key_len = 0;

	if (key == NULL || data->env == NULL)
		return (NULL);

	key_len = str_l(key);

	while (data->env[i])
	{
		if (str_c(key, data->env[i], key_len) &&
				data->env[i][key_len] == '=')
		{
			return (data->env[i] + key_len + 1);
		}
		i++;
	}
	return (NULL);
}
