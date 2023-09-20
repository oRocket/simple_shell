#include "shell.h"
/**
 * execute_command - Execute an external command
 * @shell: A pointer to the ShellState structure containing shell state
 * @args: An array of command arguments
 */
void execute_command(ShellState *shell, char *args[])
{
	int status;

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("exec");
			exit(1);
		}
	}
	else
	{
		/* Parent process */
		wait(&status);
		shell->exit_status = WEXITSTATUS(status);
	}
}
