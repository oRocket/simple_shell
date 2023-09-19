#include "shell.h"

/**
 * _which - Get the full path of a command by searching in PATH directories.
 * @str: The command to find (e.g., "ls" from "ls -l").
 * @env: Environmental variable.
 * Return: A copy of the full path to the command (e.g., "/bin/ls" for "ls").
 */
char *_which(char *str, list_t *env)
{
	char *path, *concatenated_path = NULL, **path_tokens;
	int i = 0;

	/* Get and tokenize PATH directories, then free the original string */
	path = get_env("PATH", env);
	path_tokens = custom_strtok(path, ":");
	free(path);

	/* Append "/cmd" to each token to check if it's a valid command */
	for (i = 0; path_tokens[i] != NULL; i++)
	{
		if (path_tokens[i][0] == '\0')
			concatenated_path = getcwd(concatenated_path, 0);
		else
			concatenated_path = _strdup(path_tokens[i]);
		concatenated_path = _strcat(concatenated_path, "/");
		concatenated_path = _strcat(concatenated_path, str);
		if (access(concatenated_path, F_OK) == 0)
		{
			/* Free tokens before returning the legitimate full path */
			free_double_ptr(path_tokens);
			return (concatenated_path);
		}
		free(concatenated_path); /* Free concatenated string if the command is never found */
	}

	free_double_ptr(path_tokens);
	return (str); /* Return the original string if not found; won't pass execve */
}
