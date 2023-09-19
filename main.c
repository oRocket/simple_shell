#include "shell.h"
int main(void)
{
	pid_t pid;
	int status;
	char input[MAX_INPUT_LENGTH];
	char *tokens[MAX_INPUT_LENGTH], *token;

	while (1)
	{
		int token_count = 0;

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

		/* Parse the input into command and arguments */
		token = strtok(input, " ");
		while (token != NULL)
		{
			tokens[token_count++] = token;
			token = strtok(NULL, " ");
		}

		tokens[token_count] = NULL; /* Null-terminate the tokens array */

		/* Fork a child process */
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid == 0) /* Child process */
		{
			/* Execute the command using execvp */
			if (execvp(tokens[0], tokens) == -1)
			{
				perror("execvp");
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
