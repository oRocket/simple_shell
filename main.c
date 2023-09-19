#include "shell.h"
/**
 * main - Entry point
 *
 * Return: Always 0 Success
 */
int main(void)
{
	char exit_msg[50], input[MAX_INPUT_LENGTH], *args[MAX_ARGS];
	int i, arg_count, exit_status, len;
	ShellState shell;

	init_shell(&shell);

	while (1)
	{
		char prompt[] = "$ ";
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			char exit_msg[] = "\nExiting shell.\n";
			write(STDOUT_FILENO, exit_msg, sizeof(exit_msg) - 1);
			exit(shell.exit_status);
		}

		input[my_strlen(input) - 1] = '\0';

		split_input(input, args, &arg_count);

		if (arg_count == 0)
		{
			continue;
		}

		if (my_strcmp(args[0], "exit") == 0)
		{
			if (arg_count == 1)
			{
				char exit_msg[] = "Exiting shell.\n";
				write(STDOUT_FILENO, exit_msg, sizeof(exit_msg) - 1);
				for (i = 0; i < arg_count; i++)
				{
					free(args[i]);
				}
				exit(shell.exit_status);
			}
			else if (arg_count == 2)
			{
				exit_status = atoi(args[1]);
				len = snprintf(exit_msg, sizeof(exit_msg), "Exiting shell with status %d.\n", exit_status);
				write(STDOUT_FILENO, exit_msg, len);
				for (i = 0; i < arg_count; i++)
				{
					free(args[i]);
				}
				exit(exit_status);
			}
			else
			{
				char usage_msg[] = "Usage: exit [status]\n";
				write(STDOUT_FILENO, usage_msg, sizeof(usage_msg) - 1);
			}
		}
		else if (my_strcmp(args[0], "setenv") == 0)
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
		else if (my_strcmp(args[0], "unsetenv") == 0)
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
		else if (my_strcmp(args[0], "cd") == 0)
		{
			cd_command(&shell, args, arg_count);
		}
		else
		{
			execute_command(&shell, args);
		}

		for (i = 0; i < arg_count; i++)
		{
			free(args[i]);
		}
	}
	return (0);
}
