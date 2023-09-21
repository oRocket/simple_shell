#include "shell.h"

/**
 * p_alias - a function that add, remove or show aliases
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
						&&      data->alias_list[i][alias_len] == '='))
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
