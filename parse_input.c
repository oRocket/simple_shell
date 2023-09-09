#include "shell.h"

/**
 * parse_input - Parse the user input into a Command structure.
 * @input: User input string.
 * @cmd: Pointer to a Command structure to store the parsed command.
 * Return: No return.
 */
void parse_input(char *input, Command *cmd)
{
	char *token = strtok(input, " ");
	int argc; /* argument count */

	if (token != NULL)
	{
		cmd->command = token;
		argc = 1;

		while ((token = strtok(NULL, " ")) != NULL)
		{
			cmd->args[argc++] = token;
		}
		cmd->args[argc] = NULL;
	}
}
