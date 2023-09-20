#include "shell.h"

/**
 * print_alias - a function that add, remove or show aliases
 * @data: program's data struct
 * @alias: name to be printed
 * Return: always 0 success
 */
int p_alias(program_data *data, char *alias)
{
	int i, j, alias_len;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_len = str_l(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_c(data->alias_list[i], alias, alias_len)
						&&	data->alias_list[i][alias_len] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_sum(buffer, "'");
				buffer_sum(buffer, data->alias_list[i] + j + 1);
				buffer_sum(buffer, "'\n");
				print_f(buffer);
			}
		}
	}

	return (0);
}

/**
 * g_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @name: name of the requested alias.
 * Return: NULL
 */
char *g_alias(program_data *data, char *name)
{
	int i, alias_len;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_len = str_l(name);

	for (i = 0; data->alias_list[i]; i++)
	{
		if (str_c(name, data->alias_list[i], alias_len) &&
				data->alias_list[i][alias_len] == '=')
		{
			return (data->alias_list[i] + alias_len + 1);
		}
	}
	return (NULL);
}

/**
 * s_alias - a function that add, or override alias
 * @alias_string: string
 * @data: data struct
 * Return: 0 success
 */
int s_alias(char *alias_string, program_data *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = g_alias(data, alias_string + i + 1);
			break;
		}

	for (j = 0; data->alias_list[j]; j++)
		if (str_c(buffer, data->alias_list[j], i) &&
				data->alias_list[j][i] == '=')
		{
			free(data->alias_list[j]);
			break;
		}

	if (temp)
	{
		buffer_sum(buffer, "=");
		buffer_sum(buffer, temp);
		data->alias_list[j] = str_d(buffer);
	}
	else
		data->alias_list[j] = str_d(alias_string);
	return (0);
}
