#include "shell.h"
/**
 * icr_alias - function that expand aliases
 * @data: a pointer to data
 * Authors: Albert and Benedict
 * Return: No return
 */
void icr_alias(program_data *data)
{
	int i, j;
	int incr = 0;
	char line[BUFFER_SIZE] = {0}, increase[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input == NULL)
		return;

	buffer_sum(line, data->input);

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i + j] && line[i + j] != ' ')
		{
			increase[j] = line[i + j];
			j++;
		}
		increase[j] = '\0';

		temp = g_alias(data, increase);
		if (temp)
		{
			increase[0] = '\0';
			buffer_sum(increase, line + i + j);
			line[i] = '\0';
			buffer_sum(line, temp);
			line[str_l(line)] = '\0';
			buffer_sum(line, increase);
			incr = 1;
		}
		break;
	}
	if (incr)
	{
		free(data->input);
		data->input = str_d(line);
	}
}
