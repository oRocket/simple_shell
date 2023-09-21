#include "shell.h"

/**
 * main - Variable initialization and main program loop
 * @argc: argument count
 * @argv: argument vector
 * @env: values received
 * Authors: Albert and Benedict
 * Return: Always 0 on success
 */
int main(int argc, char *argv[], char *env[])
{
	program_data data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	/* Initialize data related to the program's execution */
	initialize_data(data, argv, argc);

	signal(SIGINT, ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;

	/* Initialize environment-related data */
	initialize_environment(data, env);

	/* Initialize the alias list */
	initialize_alias_list(data);

	benedict(prompt, data);

	return (0);
}
