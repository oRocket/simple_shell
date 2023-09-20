#include "shell.h"
/**
 * free_ar_pt - frees array pointers
 * @array: pointers to arrays
 * Return: no return
 */
void free_ar_pt(char **array)
{
	int i = 0;

	if (array != NULL)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}

		free(array);
		array = NULL;
	}
}
/**
 * free_rec - fields freeing function
 * @data: program data struct
 * Return: No return
 */
void free_rec(program_data *data)
{
	if (data->tokens)
		free_ar_pt(data->tokens);
	if (data->input)
		free(data->input);
	if (data->cmd)
		free(data->cmd);

	data->input = NULL;
	data->cmd = NULL;
	data->tokens = NULL;
}
/**
 * free_dt - function that frees fields data
 * @data: program data
 * Return: No return
 */
void free_dt(program_data *data)
{
	if (data->fd != 0)
	{
		if (close(data->fd))
			perror(data->name);
	}
	free_rec(data);
	free_ar_pt(data->env);
	free_ar_pt(data->alias_list);
}
