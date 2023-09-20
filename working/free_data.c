#include "shell.h"
/**
 * free_data - function that frees fields data
 * @data: program data
 * Return: No return
 */
void free_data(program_data *data)
{
	if (data->fd != 0)
	{
		if (close(data->fd))
			perror(data->name);
	}
	free_rec(data);
	free_ar_pt(data->env);
	free_ar_pt(data->alisr_l);
}
