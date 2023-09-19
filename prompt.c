#include "shell.h"

/**
 * ctrl_c - Ignore Ctrl-C input and print the prompt again.
 *
 * @n: Integer from signal (unused).
 */
void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * built_in - Handle builtins (exit, env, cd).
 *
 * @token: User's typed command.
 * @env: Environmental variables.
 * @num: Nth user command typed to write an error message.
 * @command: Command to free (unused).
 * Return: 1 if acted on a builtin, 0 if not.
 */
int built_in(char **token, list_t *env, int num, char **command)
{
	int i = 0;

	/* If the user types "exit", free cmd tokens, and exit */
	if (_strcmp(token[0], "exit") == 0)
	{
		i = __exit(token, env, num, command);
	}
	/* If the user types "env", print, free cmd tokens, and reprompt */
	else if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		i = 1;
	}
	/* If the user types "cd", change the directory */
	else if (_strcmp(token[0], "cd") == 0)
	{
		i = _cd(token, env, num);
	}
	/* If the user types "setenv", create or modify linked list node */
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		i = 1;
	}
	/* If the user types "unsetenv", remove linked list node */
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		i = 1;
	}
	return (i);
}

/**
 * ignore_space - Return string without spaces in front.
 *
 * @str: String.
 * Return: New string.
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * ctrl_D - Exit the program if Ctrl-D was pressed.
 *
 * @i: Characters read via get_line.
 * @command: User's typed-in command.
 * @env: Environmental variable linked list.
 */
void ctrl_D(int i, char *command, list_t *env)
{
	if (i == 0) /* Handles Ctrl+D */
	{
		free(command); /* Exit with newline if in shell */
		free_linked_list(env);
		if (isatty(STDIN_FILENO))/* Ctrl+D prints newline */
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * prompt - Repeatedly prompts the user and executes user's commands if applicable.
 *
 * @en: Environmental variables.
 * Return: 0 on success.
 */
int prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		command_line_no++;
		if (isatty(STDIN_FILENO)) /* Reprompt if in an interactive shell */
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c); /* Makes ctrl+c not work */
		command = NULL;
		i = get_line(&command); /* Read user's cmd from stdin */
		ctrl_D(i, command, env); /* Exits shell if ctrl-D */
		n_command = command;
		command = ignore_space(command);
		n = 0;
		while (command[n] != '\n') /* Replace get_line's \n with \0 */
			n++;
		command[n] = '\0';
		if (command[0] == '\0') /* Reprompt if user hits enter only */
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = _str_tok(command, " "); /* Tokenize user cmd */
		if (n_command != NULL)
			free(n_command);
		exit_stat = built_in(token, env, command_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(token, env, command_line_no);
	} while (1); /* Keep repeating until the user exits the shell */
	return (exit_stat);
}
