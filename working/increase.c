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
