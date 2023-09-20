#include "shell.h"

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
