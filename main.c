#include "shell.h"
/**
 * main - Entry point for the simple shell program
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	int status;
	char *args[] = {input, NULL};
	char *envp[] = {NULL};
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		/* Display a prompt */
		if (write(STDOUT_FILENO, "simple_shell> ", 14) == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}

		/* Read user input */
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (write(STDOUT_FILENO, "\n", 1) == -1)
			{
				perror("write");
				exit(EXIT_FAILURE);
			}
			break;
		}

		/* Remove the newline character at the end */
		input[strlen(input) - 1] = '\0';

		/* Fork a child process */
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0) /* Child process */
		{
			/* Execute the command using execve */
			if (execve(input, args, envp) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else /* Parent process */
		{
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}

	/* Display exit message */
	if (write(STDOUT_FILENO, "Exiting the simple shell.\n", 27) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
