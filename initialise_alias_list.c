#include "shell.h"

/**
 * initialize_alias_list - Initializes alias_list
 * @data: data structure pointer
 * Authors: Albert and Benedict
 */
void initialize_alias_list(program_data *data)
{
	int i = 0;

	data->alias_list = malloc(sizeof(char *) * 20);

	while (i < 20)
	{
		data->alias_list[i] = NULL;
		i++;
	}
}
