#include "shell.h"
/**
 * tok_path - tokenize the PATH into directories
 * @data: a pointer to the program's data
 * Authors: Albert and Benedict
 * Return: array of path directories
 */
char **tok_path(program_data *data)
{
	int i = 0;
	int cnt_dir = 2;
	char **dir_tokens = NULL;
	char *PATH;

	PATH = env_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}

	PATH = str_d(PATH);

	while (PATH[i])
	{
		if (PATH[i] == ':')
			cnt_dir++;
		i++;
	}

	dir_tokens = malloc(sizeof(char *) * cnt_dir);

	i = 0;
	while ((dir_tokens[i] = str_d(str_tok(PATH, ":"))))
	{
		i++;
	}

	free(PATH);
	PATH = NULL;
	return (dir_tokens);
}
