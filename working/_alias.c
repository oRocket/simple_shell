#include "shell.h"
/**
 * _alias - a function that add, remove or show aliases
 * @data: program data struct
 * Return: 0 success
 */
int _alias(program_data *data)
{
	int i;

	if (data->tokens[1] == NULL)
		return (p_alias(data, NULL));

	for (i = 1; data->tokens[i] != NULL; i++)
	{
		if (c_xtr(data->tokens[i], "="))
			s_alias(data->tokens[i], data);
		else
			p_alias(data, data->tokens[i]);
	}
	return (0);
}
