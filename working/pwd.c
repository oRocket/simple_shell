#include "shell.h"
/**
 * pwd - a function that sets the working directory
 * @data: program data struct
 * @new_dir: path to be set for working directory
 * Return: 0 success
 */
int pwd(program_data *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err = 0;

	getcwd(old_dir, 128);

	if (!str_c(old_dir, new_dir, 0))
	{
		err = chdir(new_dir);
		if (err == -1)
		{
			errno = 2;
			return (3);
		}
		env_set("PWD", new_dir, data);
	}
	env_set("OLDPWD", old_dir, data);
	return (0);
}
