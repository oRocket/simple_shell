#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

/**
 * main - Entry point for the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	int arg_count = 0;
	char input[MAX_INPUT_LENGTH], *token;
	char* argv[] = {"/bin/ls", "/bin/ls -l"}
	char* envp[] = { "some", "environment", NULL };

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		/* Read user input */
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			/* Handle Ctrl+D (end of file) */
			printf("\nExiting shell.\n");
			exit(0);
		}

		input[strlen(input) - 1] = '\0'; /* Remove the newline character */

		char *args[MAX_ARGS];

		/* Tokenize input into command and arguments */
		*token = strtok(input, " ");
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
		if (execve(argv, envp) == -1)
		{
			perror("exec");
			printf("Command not found: %s\n", args[0]);
		}
	}

	return (0);
}
