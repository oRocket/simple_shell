#include "shell.h"

/**
 * init_shell - Initialize the shell state
 * @shell: A pointer to the ShellState structure to be initialized
 * This function initializes the shell state by setting the exit status to 0
 * and obtaining the current working directory using getcwd(). If getcwd()
 * fails, an error message is printed using perror().
 * Return: No return.
 */
void init_shell(ShellState *shell)
{
	shell->exit_status = 0;

	/* Attempt to get the current working directory */
	if (getcwd(shell->current_dir, sizeof(shell->current_dir)) == NULL)
	{
		perror("getcwd");
	}
}
