#include "shell.h"
/**
 * exc - execute a command
 * @data: data pointer
 * Return: 0 if successful, otherwise -1.
 */
int exc(program_data *data)
{
	pid_t p_id;
	int rtv = 0, status;

	rtv = inbuilt_l(data);
	if (rtv != -1)
		return (rtv);

	rtv = f_p(data);
	if (rtv)
	{
		return (rtv);
	}
	else
	{
		p_id = fork();
		if (p_id == -1)
		{
			perror(data->cmd);
			exit(EXIT_FAILURE);
		}
		if (p_id == 0)
		{
			rtv = execve(data->tokens[0], data->tokens, data->env);
			if (rtv == -1)
				perror(data->cmd), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
