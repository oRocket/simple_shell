#include "shell.h"

/**
 * print_usage - Print a usage message for the shell program.
 * Authors: Albert and Benedict.
 * @program_name: The name of the program.
 */
void print_usage(const char *program_name)
{
	char usage_msg[100];
	int len = snprintf(usage_msg, sizeof(usage_msg),
			"Usage: %s\n", program_name);

	write(STDERR_FILENO, usage_msg, len);
}

