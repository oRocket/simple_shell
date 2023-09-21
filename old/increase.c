#include "shell.h"
/**
 * icr_var - function that increase variable
 * Authors: Benedict and Albert
 * @data: program's data pointer
 * Return: No return.
 */
void icr_var(program_data *data)
{
	int i, j;
	char *temp, line[BUFFER_SIZE] = {0}, increase[BUFFER_SIZE] = {'\0'};

	if (data->input == NULL)
		return;

	buffer_sum(line, data->input);

	i = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			line[i--] = '\0';
		}
		else if (line[i] == '$' && line[i + 1] == '?' && line[i + 2] == ' ')
		{
			line[i] = '\0';
			l_str(errno, increase, 10);
			buffer_sum(line, increase);
			buffer_sum(line, data->input + i + 3);
		}
		else if (line[i] == '$' && line[i + 1] == '$' && line[i + 2] == ' ')
		{
			line[i] = '\0';
			l_str(getpid(), increase, 10);
			buffer_sum(line, increase);
			buffer_sum(line, data->input + i + 3);
		}
		else if (line[i] == '$' && (line[i + 1] == ' ' || line[i + 1] == '\0'))
		{
			i++;
			continue;
		}
		else if (line[i] == '$' && line[i + 1] == ' ')
		{
			j = 2;
			while (line[i + j] && line[i + j] != ' ')
			{
				increase[j - 2] = line[i + j];
				j++;
			}
			increase[j - 2] = '\0';
			temp = env_key(increase, data);
			line[i] = '\0';
			increase[0] = '\0';
			buffer_sum(increase, line + i + j);
			if (temp)
			{
				buffer_sum(line, temp);
			}
			else
			{
				i++;
				continue;
			}
			buffer_sum(line, increase);
		}
		i++;
	}
	if (!str_c(data->input, line, 0))
	{
		free(data->input);
		data->input = str_d(line);
	}
}
/**
 * icr_alias - function that expand aliases
 * @data: a pointer to data
 * Return: No return
 */
void icr_alias(program_data *data)
{
	int i, j, incr = 0;
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
/**
 * buffer_sum - a function that appends a string
 * @buffer: filled buffer
 * @str_sum: copied string
 * Return: No return
 */
int buffer_sum(char *buffer, char *str_sum)
{
	int len, i;

	len = str_l(buffer);
	i = 0;
	while (str_sum[i])
	{
		buffer[len + i] = str_sum[i];
		i++;
	}
	buffer[len + i] = '\0';
	return (len + i);
}
