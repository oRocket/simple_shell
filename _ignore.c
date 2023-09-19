#include "shell.h"

/**
 * custom_ignore - Custom function to ignore spaces and newlines in a string.
 *
 * @str: The input string.
 *
 * Return: A new string with leading spaces and newlines removed.
 */
char *custom_ignore(char *str)
{
	for (; *str == ' ' || *str == '\n'; str++)
		;

	return (str);
}

/**
 * non_interactive - Handle when the user pipes commands into the shell via a pipeline.
 *
 * @env: Environmental variables.
 */
void non_interactive(list_t *env)
{
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command = NULL, *n_command = NULL, **n_line, **token;

	i = get_line(&command);
	if (i == 0)
	{
		free(command);
		exit(0);
	}

	n_command = command;
	command = custom_ignore(command);
	n_line = _str_tok(command, "\n"); /* Tokenize each command string */

	if (n_command != NULL)
		free(n_command);

	n = 0;

	while (n_line[n] != NULL)
	{
		command_line_no++;
		token = NULL; /* Tokenize each command in the array of commands */
		token = _str_tok(n_line[n], " ");
		exit_stat = built_in(token, env, command_line_no, n_line);

		if (exit_stat)
		{
			n++;
			continue;
		}

		exit_stat = _execve(token, env, command_line_no);
		n++;
	}

	free_double_ptr(n_line);
	free_linked_list(env);
	exit(exit_stat);
}
