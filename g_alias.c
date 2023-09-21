#include "shell.h"

/**
 * g_alias - add, remove or show aliases
 * @data: struct for the program's data
 * @name: name of the requested alias.
 * Authors: Albert and Benedict.
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
