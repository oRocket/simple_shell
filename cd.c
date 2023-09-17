#include "shell.h"
/**
 * cd_command - Handle the "cd" command
 * @shell: A pointer to the ShellState structure containing shell state
 * @args: An array of command arguments
 * @arg_count: The number of command arguments
 */
void cd_command(ShellState *shell, char *args[], int arg_count)
{
	const char *home_dir = getenv("HOME");

	if (arg_count == 1 || (arg_count == 2 && strcmp(args[1], "-") == 0))
	{
		if (home_dir == NULL)
		{
			fprintf(stderr, "HOME environment variable not set.\n");
		}
		else
		{
			if (chdir(home_dir) != 0)
			{
				perror("chdir");
			}
		}
	}
	else if (arg_count == 2)
	{
		if (chdir(args[1]) != 0)
		{
			perror("chdir");
		}
	}
	else
	{
		fprintf(stderr, "Usage: cd [DIRECTORY]\n");
	}

	if (getcwd(shell->current_dir, sizeof(shell->current_dir)) != NULL)
	{
		if (setenv("PWD", shell->current_dir, 1) != 0)
		{
			fprintf(stderr, "Failed to set PWD environment variable.\n");
		}
	}
	else
	{
		perror("getcwd");
	}
}
