#include "shell.h"

/**
 * initialize_data - Initializes program_data structure
 * @data: data structure pointer
 * @argv: argument vector
 * @argc: argument count
 */
void initialize_data(program_data *data, char *argv[], int argc)
{
	data->name = argv[0];
	data->input = NULL;
	data->cmd = NULL;
	data->exe = 0;

	if (argc == 1)
		data->fd = STDIN_FILENO;
	else
	{
		data->fd = open(argv[1], O_RDONLY);
		if (data->fd == -1)
		{
			print(data->name);
			print(": 0: Failed to open ");
			print(argv[1]);
			print("\n");
			exit(127);
		}
	}
}
