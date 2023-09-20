#include "shell.h"
/**
 * handle_unsetenv - Handle the 'unsetenv' command.
 * @args: An array of command arguments.
 * @arg_count: The number of arguments.
 */
void handle_unsetenv(char *args[], int arg_count)
{
	if (arg_count != 2)
	{
		char usage_msg[] = "Usage: unsetenv VARIABLE\n";

		write(STDOUT_FILENO, usage_msg, sizeof(usage_msg) - 1);
	}
	else
	{
		if (unsetenv(args[1]) != 0)
		{
			char err_msg[] = "Failed to unset environment variable.\n";

			write(STDERR_FILENO, err_msg, sizeof(err_msg) - 1);
		}
	}
}
