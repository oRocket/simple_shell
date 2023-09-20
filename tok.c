#include "shell.h"
/**
 * tok - separates the string
 * @data: data pointer
 * Return: an array of string parts
 */
void tok(program_data *data)
{
	char *del = " \t";
	int j, i = 0, len, counter = 2;

	len = str_l(data->input);
	if (len)
	{
		if (data->input[len - 1] == '\n')
			data->input[len - 1] = '\0';
	}

	while (data->input[i])
	{
		j = 0;
		while (del[j])
		{
			if (data->input[i] == del[j])
				counter++;
			j++;
		}
		i++;
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->name);
		exit(errno);
	}

	i = 0;
	data->tokens[i] = str_d(str_tok(data->input, del));
	data->cmd = str_d(data->tokens[0]);

	while (data->tokens[i++])
	{
		data->tokens[i] = str_d(str_tok(NULL, del));
	}
}
