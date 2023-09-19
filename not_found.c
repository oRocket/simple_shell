#include "shell.h"

/**
 * not_found - Write an error message ("sh: 1: lss: not found").
 *
 * @str: User's typed command.
 * @c_n: Nth user's typed command.
 * @env: Environmental variables linked list to write the shell name.
 */
void not_found(char *str, int c_n, list_t *env)
{
	int count = 0;
	char *shell, *num;

	shell = get_env("_", env); /* Get shell name to write */
	for (count = 0; shell[count] != '\0'; count++)
		;

	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n); /* Convert command line number to string to write */
	for (count = 0; num[count] != '\0'; count++)
		;

	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	for (count = 0; str[count] != '\0'; count++)
		;

	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

/**
 * cant_cd_to - Write an error message ("sh: 2: cd: can't cd to xyz").
 *
 * @str: User's typed argument after the "cd" command.
 * @c_n: Nth user's typed command.
 * @env: Environmental variables linked list to write the shell name.
 */
void cant_cd_to(char *str, int c_n, list_t *env)
{
	int count = 0;
	char *shell, *num;

	shell = get_env("_", env);
	for (count = 0; shell[count] != '\0'; count++)
		;

	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	num = int_to_string(c_n);
	for (count = 0; num[count] != '\0'; count++)
		;

	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "cd: can't cd to ", 16);
	for (count = 0; str[count] != '\0'; count++)
		;

	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, "\n", 1);
}
