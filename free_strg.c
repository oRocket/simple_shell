#include "shell.h"

/**
 * free_string_array - Free a dynamically allocated array of strings.
 *
 * @array: The array of strings to free.
 */
void free_string_array(char **array)
{
	if (array == NULL)
		return;

	for (int i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}

	free(array);
}
