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
