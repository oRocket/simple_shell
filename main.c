#include "shell.h"
/**
 * main - Entry point
 *
 * Return: Always 0 Success
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH], *args[MAX_ARGS];
	int i, arg_count, exit_status;
	ShellState shell;

	init_shell(&shell);

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("\nExiting shell.\n");
			exit(shell.exit_status);
		}

		input[strlen(input) - 1] = '\0';

		split_input(input, args, &arg_count);

		if (arg_count == 0)
		{
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
		{
			if (arg_count == 1)
			{
				printf("Exiting shell.\n");
				for (i = 0; i < arg_count; i++)
				{
					free(args[i]);
				}
				exit(shell.exit_status);
			}
			else if (arg_count == 2)
			{
				exit_status = atoi(args[1]);
				printf("Exiting shell with status %d.\n", exit_status);
				for (i = 0; i < arg_count; i++)
				{
					free(args[i]);
				}
				exit(exit_status);
			}
			else
			{
				printf("Usage: exit [status]\n");
			}
		}
		else if (strcmp(args[0], "setenv") == 0)
		{
			if (arg_count != 3)
			{
				fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
			}
			else
			{
				if (setenv(args[1], args[2], 1) != 0)
				{
					fprintf(stderr, "Failed to set environment variable.\n");
				}
			}
		}
		else if (strcmp(args[0], "unsetenv") == 0)
		{
			if (arg_count != 2)
			{
				fprintf(stderr, "Usage: unsetenv VARIABLE\n");
			}
			else
			{
				if (unsetenv(args[1]) != 0)
				{
					fprintf(stderr, "Failed to unset environment variable.\n");
				}
			}
		}
		else if (strcmp(args[0], "cd") == 0)
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
