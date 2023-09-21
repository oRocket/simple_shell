#include "shell.h"
/**
 * chc_op - a function that checks and split for && and || operators
 * @array_cmd: commands.
 * @i: index
 * @array_optr: operators
 * Return: index
 */
int chc_op(char *array_cmd[], int i, char array_optr[])
{
	char *temp = NULL;
	int j;

	for (j = 0; array_cmd[i] != NULL  && array_cmd[i][j]; j++)
	{
		if (array_cmd[i][j] == '&' && array_cmd[i][j + 1] == '&')
		{
			temp = array_cmd[i];
			array_cmd[i][j] = '\0';
			array_cmd[i] = str_d(array_cmd[i]);
			array_cmd[i + 1] = str_d(temp + j + 2);
			i++;
			array_optr[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_cmd[i][j] == '|' && array_cmd[i][j + 1] == '|')
		{
			temp = array_cmd[i];
			array_cmd[i][j] = '\0';
			array_cmd[i] = str_d(array_cmd[i]);
			array_cmd[i + 1] = str_d(temp + j + 2);
			i++;
			array_optr[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
