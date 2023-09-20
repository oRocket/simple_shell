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
/**
 * env_set - a function that overwrite the environment variable value
 * @key: variable name
 * @value: new value
 * @data: program's data struct
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
/**
 * env_rm - a function that receives the environment variable value
 * @key: environment variable
 * @data: program's data struct
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
/**
 * _environmt - a function that prints the working environment
 * @data: program's data struct
 * Return: No return
 */
void _environmt(program_data *data)
{
	int j = 0;

	while (data->env[j])
	{
		print_f(data->env[j]);
		print_f("\n");
		j++;
	}
}
