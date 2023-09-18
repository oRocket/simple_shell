#include "shell.h"
/**
 * handle_setenv - Handle the 'setenv' command.
 * @args: An array of command arguments.
 * @arg_count: The number of arguments.
 */
void handle_setenv(char *args[], int arg_count)
{
	if (arg_count != 3)
	{
		char usage_msg[] = "Usage: setenv VARIABLE VALUE\n";

		write(STDOUT_FILENO, usage_msg, sizeof(usage_msg) - 1);
	}
	else
	{
		if (setenv(args[1], args[2], 1) != 0)
		{
			char err_msg[] = "Failed to set environment variable.\n";

			write(STDERR_FILENO, err_msg, sizeof(err_msg) - 1);
		}
	}
}
