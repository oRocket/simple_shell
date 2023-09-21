#include "shell.h"

/**
 * icr_var - Function that increases variable
 * Authors: Benedict and Albert
 * @data: Program's data pointer
 * Return: No return.
 */
void icr_var(program_data *data)
{
	char line[BUFFER_SIZE] = {0};

	if (data->input == NULL)
		return;

	buffer_sum(line, data->input);
	increase_errno_var(line, data);
}
