#include "shell.h"
int file_checker(char *whole_path);
/**
 * f_p - a function that identifies a program in path
 * @data: program's data pointer
 * Return: Always 0 (Success)
 */
int f_p(program_data *data)
{
	int i = 0, rt_c = 0;
	char **dir;

	if (!data->cmd)
		return (2);

	if (data->cmd[0] == '/' || data->cmd[0] == '.')
		return (file_checker(data->cmd));

	free(data->tokens[0]);
	data->tokens[0] = str_ccat(str_d("/"), data->cmd);
	if (!data->tokens[0])
		return (2);

	dir = tok_path(data);

	if (!dir || !dir[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; dir[i]; i++)
	{
		dir[i] = str_ccat(dir[i], data->tokens[0]);
		rt_c = file_checker(dir[i]);
		if (rt_c == 0 || rt_c == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_d(dir[i]);
			free_ar_pt(dir);
			return (rt_c);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_ar_pt(dir);
	return (rt_c);
}
/**
 * tok_path - tokenize the PATH into directories
 * @data: a pointer to the program's data
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
/**
 * file_checker - a function that checks if a file is available
 * @whole_path: pointer to the full file name
 * Return: 0 success
 */
int file_checker(char *whole_path)
{
        struct stat cu;

        if (stat(whole_path, &cu) != -1)
        {
                if (S_ISDIR(cu.st_mode) || access(whole_path, X_OK))
                {
                        errno = 126;
                        return (126);
                }
                return (0);
        }
        errno = 127;
        return (127);
}
