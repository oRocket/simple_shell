#include "shell.h"
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
