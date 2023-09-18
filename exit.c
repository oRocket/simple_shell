#include "shell.h"
/**
 * handle_exit - Handle the 'exit' command.
 * @shell: A pointer to the ShellState structure.
 * @args: An array of command arguments.
 * @arg_count: The number of arguments.
 */
void handle_exit(ShellState *shell, char *args[], int arg_count)
{
	if (arg_count == 1)
	{
		print_exit_msg(shell->exit_status);
		exit(shell->exit_status);
	}
	else if (arg_count == 2)
	{
		int exit_status = atoi(args[1]);

		print_exit_msg(exit_status);
		exit(exit_status);
	}
	else
	{
		char usage_msg[] = "Usage: exit [status]\n";

		write(STDOUT_FILENO, usage_msg, sizeof(usage_msg) - 1);
	}
}
