#include "shell.h"
/**
 * main - variable initializtion
 * @argc: argument count
 * @argv: argument vector
 * @env: values received
 * Return: Always 0 success
 */
int main(int argc, char *argv[], char *env[])
{
	program_data data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	start_d(data, argc, argv, env);

	signal(SIGINT, ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	benedict(prompt, data);
	return (0);
}
/**
 * ctrl_c - prompt printing
 *
 * @UNUSED: optional
 */
void ctrl_c(int opr UNUSED)
{
	print_f("\n");
	print_f(PROMPT_MSG);
}

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

	data->alias_list = malloc(sizeof(char *) * 20);

	i = 0;
	while (i < 20)
	{
		data->alias_list[i] = NULL;
		i++;
	}
}
/**
 * benedict - shows prompt in a loop
 * @prompt: print prompt
 * @data: data to be showed of prompt
 */
void benedict(char *prompt, program_data *data)
{
	int err = 0, str_l = 0;

	while (++(data->exe))
	{
		print_f(prompt);
		err = str_l = get_line(data);

		if (err == EOF)
		{
			free_dt(data);
			exit(errno);
		}
		if (str_l >= 1)
		{
			icr_alias(data);
			icr_var(data);
			tok(data);
			if (data->tokens[0])
			{
				err = exc(data);
				if (err != 0)
					print_err(err, data);
			}
			free_rec(data);
		}
	}
}
