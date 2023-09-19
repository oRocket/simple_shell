#include "shell.h"
#include <unistd.h>
/**
 * main - Entry point for the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	int arg_count = 0;
	char input[MAX_INPUT_LENGTH], *token, *args[MAX_ARGS];

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);

		/* Read user input */
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			/* Handle Ctrl+D (end of file) */
			write(STDOUT_FILENO, "\nExiting shell.\n", 16);
			exit(0);
		}

		input[strlen(input) - 1] = '\0'; /* Remove the newline character */

		/* Tokenize input into command and arguments */
		token = strtok(input, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		if (arg_count == 0)
		{
			continue; /* No command entered, prompt again */
		}

		/* Check if the command exists in PATH and execute it */
		if (execvp(args[0], args) == -1)
		{
			perror("exec");
			write(STDOUT_FILENO, "Command not found: ", 19);
			write(STDOUT_FILENO, args[0], strlen(args[0]));
			write(STDOUT_FILENO, "\n", 1);
		}
	}

	return (0);
}

