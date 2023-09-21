#include "shell.h"

/**
 * e_xit - a function that exit a program
 * @data: program data struct
 * Return: 0 success
 */
int e_xit(program_data *data)
{
	int i = 0;

	if (data->tokens[1] != NULL)
	{
		while (data->tokens[1][i])
		{
			if ((data->tokens[1][i] < '0' || data->tokens[1][i] > '9')
					&& data->tokens[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
			i++;
		}
		errno = a_toi(data->tokens[1]);
	}
	free_dt(data);
	exit(errno);
}
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
/**
 * _help - a function that shows the environment in shell
 * @data: program data struct
 * Return: 0 success
 */
int _help(program_data *data)
{
	int i, len = 0;
	char *alx[6] = {NULL};

	alx[0] = HELP_MSG;

	if (data->tokens[1] == NULL)
	{
		print_f(alx[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->cmd);
		return (5);
	}
	alx[1] = HELP_EXIT_MSG;
	alx[2] = HELP_ENV_MSG;
	alx[3] = HELP_SETENV_MSG;
	alx[4] = HELP_UNSETENV_MSG;
	alx[5] = HELP_CD_MSG;

	i = 0;
	while (alx[i])
	{
		len = str_l(data->tokens[1]);
		if (str_c(data->tokens[1], alx[i], len))
		{
			print_f(alx[i] + len + 1);
			return (1);
		}
		i++;
	}
	errno = EINVAL;
	perror(data->cmd);
	return (0);
}
/**
 * _alias - a function that add, remove or show aliases
 * @data: program data struct
 * Return: 0 success
 */
int _alias(program_data *data)
{
	int i;

	if (data->tokens[1] == NULL)
		return (p_alias(data, NULL));

	for (i = 1; data->tokens[i] != NULL; i++)
	{
		if (c_xtr(data->tokens[i], "="))
			s_alias(data->tokens[i], data);
		else
			p_alias(data, data->tokens[i]);
	}
	return (0);
}
