#include "shell.h"
/**
 * start_d - start struct
 * @data: data structure pointer
 * @argv: argument vector
 * @env: environment
 * @argc: argument count
 */
void start_d(program_data *data, int argc, char *argv[], char **env)
{
	int i = 0;

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
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_d(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_l = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alisr_l[i] = NULL;
	}
}
