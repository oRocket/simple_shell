#include "shell.h"

/**
 * custom_strdup_excluded - Custom string duplication, excluding beginning bytes.
 *
 * @str: The string to duplicate (e.g., environmental variable PATH=/bin:/bin/ls).
 * @exclude_bytes: The number of bytes to exclude (e.g., excludes "PATH=").
 *
 * Return: The duplicated string (e.g., /bin:/bin/ls).
 */
char *custom_strdup_excluded(const char *str, int exclude_bytes)
{
	int len = 0;

	if (str == NULL) /* Validate str input */
		return (NULL);

	/* Calculate len + null terminator to malloc */
	while (str[len] != '\0')
		len++;
	len++;

	/* Allocate memory but exclude environmental variable title (e.g., PATH=) */
	char *duplicate_str = malloc(sizeof(char) * (len - exclude_bytes));
	if (duplicate_str == NULL)
		return (NULL);

	int i = 0;
	for (; i < (len - exclude_bytes); i++)
		duplicate_str[i] = str[exclude_bytes + i];

	return duplicate_str;
}

/**
 * get_environment_variable - Find and return a copy of the requested
 * environmental variable.
 *
 * @variable_name: The name of the environmental variable to retrieve.
 * @env_list: The list of environmental variables.
 *
 * Return: A copy of the requested environmental variable.
 */
char *get_environment_variable(const char *variable_name, list_t *env_list)
{
	int title_length = 0;

	while (env_list != NULL)
	{
		int j = 0;
		while (env_list->var[j] == variable_name[j]) /* Find desired env variable. */
			j++;
		if (variable_name[j] == '\0' && env_list->var[j] == '=')
			break;
		env_list = env_list->next;
	}

	while (variable_name[title_length] != '\0') /* Find how many bytes in env variable title. */
		title_length++;
	title_length++; /* Counts 1 more for the = sign. */
	return custom_strdup_excluded(env_list->var, title_length); /* Make a copy of variable w/o title. */
}
