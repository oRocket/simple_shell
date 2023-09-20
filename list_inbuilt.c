#include "shell.h"

/**
 * inbuilt_l - a function that searches for match
 * and execute the associate built-in function
 * @data: program data struct
 * Return: 0 otherwise -1.
 **/
int inbuilt_l(program_data *data)
{
	int iterate = 0;
	inbuilt opts[] = {
		{"exit", e_xit},
		{"help", _help},
		{"cd", _cd},
		{"alias", _alias},
		{"env", _env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{NULL, NULL}
	};

	while (opts[iterate].inbuilt != NULL)
	{
		if (str_c(opts[iterate].inbuilt, data->cmd, 0))
		{
			return (opts[iterate].function(data));
		}
		iterate++;
	}
	return (-1);
}
