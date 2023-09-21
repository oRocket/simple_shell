#include "shell.h"
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
