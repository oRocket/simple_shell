#include "shell.h"

/**
 * _environmt - a function that prints the working environment
 * @data: program's data struct
 *
 * Authors: Albert and Benedict
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
