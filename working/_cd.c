#include "shell.h"
/**
 * _cd - change the working directory
 * @data: program data struct
 * Return: 0 success
 */
int _cd(program_data *data)
{
	char *dir_home = env_key("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int err = 0;

	if (data->tokens[1])
	{
		if (str_c(data->tokens[1], "-", 0))
		{
			dir_old = env_key("OLDPWD", data);
			if (dir_old)
				err = pwd(data, dir_old);
			print_f(env_key("PWD", data));
			print_f("\n");

			return (err);
		}
		else
		{
			return (pwd(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (pwd(data, dir_home));
	}
	return (0);
}
