#include "shell.h"
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
