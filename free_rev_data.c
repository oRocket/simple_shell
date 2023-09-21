#include "shell.h"
/**
 * free_rec - fields freeing function
 * @data: program data struct
 *
 * Authors: Albert and Benedict
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
