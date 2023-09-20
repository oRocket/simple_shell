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
