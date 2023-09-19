#include "shell.h"

/**
 * create_env_linked_list - Creates a linked list from environmental variables.
 *
 * @env_vars: Environmental variables.
 *
 * Return: A linked list containing environmental variables.
 */
list_t *create_env_linked_list(char **env_vars)
{
	list_t *head = NULL;

	for (int i = 0; env_vars[i] != NULL; i++)
	{
		add_end_node(&head, env_vars[i]);
	}

	return (head);
}

/**
 * display_env - Prints environmental variables.
 *
 * @command_tokens: User's command into the shell (e.g., "env").
 * @env_list: Linked list of environmental variables.
 *
 * Return: 0 on success.
 */
int display_env(char **command_tokens, list_t *env_list)
{
	free_double_ptr(command_tokens); /* Frees user input */
	print_list(env_list); /* Prints environmental variables */
	return (0);
}
