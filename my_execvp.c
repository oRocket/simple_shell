#include "shell.h"
/**
 * my_execvp - Custom implementation of execvp to execute a program.
 * Author: Albert and Benedict.
 * @file: The path to the executable file.
 * @argv: An array of strings representing the program arguments.
 * Return: Returns the exit status of the executed program or -1 on error.
 */
int my_execvp(const char *file, char *const argv[])
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		/* This code runs in the child process */
		if (execvp(file, argv) == -1)
		{
			perror("exec");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* This code runs in the parent process */
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (-1);
		}
		return (WEXITSTATUS(status));
	}
	return (0);
}
