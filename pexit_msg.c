#include "shell.h"
/**
 * print_exit_msg - Print an exit message based on the status.
 * @status: The exit status.
 */
void print_exit_msg(int status)
{
	if (status == 0)
	{
		char exit_msg[] = "Exiting shell.\n";

		write(STDOUT_FILENO, exit_msg, sizeof(exit_msg) - 1);
	}
	else
	{
		char exit_msg[50];
		int len = snprintf(exit_msg, sizeof(exit_msg),
				"Exiting shell with status %d.\n", status);

		write(STDOUT_FILENO, exit_msg, len);
	}
}
