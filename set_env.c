#include "shell.h"

/**
 * find_env - Find the given environmental variable in the linked list.
 *
 * @env: Environmental variable linked list.
 * @str: Variable name.
 * Return: Index of node in linked list.
 */
int find_env(list_t *env, char *str)
{
	int index = 0;

	while (env != NULL)
	{
		int j = 0;
		while ((env->var)[j] == str[j]) /* Find desired env variable. */
			j++;
		if (str[j] == '\0') /* If matches entirely, break and return idx. */
			break;
		env = env->next;
		index++;
	}
	if (env == NULL)
		return (-1);
	return (index);
}

/**
 * _unsetenv - Remove a node in the environmental linked list.
 *
 * @env: Linked list.
 * @str: User's typed-in command (e.g., "unsetenv MAIL").
 * Return: 0 on success.
 */
int _unsetenv(list_t **env, char **str)
{
	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}

	int index = find_env(*env, str[1]); /* Get idx of node to delete. */
	free_double_ptr(str);

	if (index == -1) /* Check if index errored. */
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}

	int j = delete_nodeint_at_index(env, index); /* Delete node. */
	if (j == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}

/**
 * _setenv - Create or modify an existing environmental variable in the linked list.
 *
 * @env: Linked list.
 * @str: User's typed-in command (e.g., "setenv USER Superman").
 * Return: 0 on success, 1 on fail.
 */
int _setenv(list_t **env, char **str)
{
	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}

	char *cat = _strdup(str[1]); /* Concatenate strings to be new node data. */
	cat = _strcat(cat, "=");
	cat = _strcat(cat, str[2]);

	int index = find_env(*env, str[1]); /* Find idx to traverse to the node. */
	if (index == -1)
	{
		add_end_node(env, cat); /* Doesn't exist? Create env var. */
	}
	else
	{
		list_t *holder = *env;
		int j = 0;
		while (j < index)
		{
			holder = holder->next;
			j++;
		}
		free(holder->var); /* Free malloced data. */
		holder->var = _strdup(cat); /* Assign to new malloced data. */
	}
	free(cat);
	free_double_ptr(str);
	return (0);
}
