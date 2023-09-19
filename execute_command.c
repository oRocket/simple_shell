#include "shell.h"

/**
 * execute_command - Execute the given command using fork and execvp
 * @cmd: Pointer to a Command structure containing \n
 * the command and arguments.
 * Return: No return.
 */
void execute_command(Command *cmd)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		execv(cmd->command, cmd->args);
		perror("execv");
		exit(EXIT_FAILURE);
	}

	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
	}
}

