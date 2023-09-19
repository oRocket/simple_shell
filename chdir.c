#include "shell.h"

/**
 * custom_strcat - Concatenate two strings, ignoring the first character ("~" in cd).
 * @dest: The destination string to be appended to.
 * @src: The source string to append.
 *
 * Return: The concatenated string.
 */
char *custom_strcat(char *dest, char *src)
{
	int len_dest = 0;
	int len_src = 0;
	int total_len = 0;
	int j = 0;

	/* Find total length of both strings to realloc memory. */
	for (; dest[len_dest] != '\0'; len_dest++, total_len++);
	for (; src[len_src] != '\0'; len_src++, total_len++);

	/* Reallocate memory because 'dest' was malloced outside of the function. */
	dest = _realloc(dest, len_dest, sizeof(char) * (total_len + 1));

	j = 1; /* Ignore the first character. */
	for (; src[j] != '\0'; j++, len_dest++)
		dest[len_dest] = src[j];
	dest[len_dest] = '\0';

	return (dest);
}

/**
 * custom_setenv - Custom _setenv by concatenating strings before setting.
 * @env: Environmental variable linked list.
 * @name: Environmental variable name (e.g., "OLDPWD").
 * @dir: Directory path (e.g., "/home/vagrant/directory1").
 *
 * Return: 0 on success (e.g., "OLDPWD=/home/vagrant/directory1").
 */
int custom_setenv(list_t **env, char *name, char *dir)
{
	int index = find_env(*env, name); /* Get the index to the env var in the linked list. */
	char *cat;
	list_t *holder = *env;

	cat = _strdup(name); /* Create a new concatenated string. */
	cat = custom_strcat(cat, "=");
	cat = custom_strcat(cat, dir);

	/* Traverse to the index, free node data, reassign data. */
	for (int j = 0; j < index; j++)
		holder = holder->next;

	free(holder->var);
	holder->var = _strdup(cat);
	free(cat);

	return (0);
}

/**
 * change_directory_only - Change the directory to the home directory.
 * @env: Environmental linked list to update PATH and OLDPWD.
 * @current_dir: Current working directory.
 */
void change_directory_only(list_t *env, char *current_dir)
{
	char *home_dir = get_env("HOME", env);

	custom_setenv(&env, "OLDPWD", current_dir); /* Update env OLDPWD. */
	free(current_dir);

	if (access(home_dir, F_OK) == 0) /* If it exists, go to the home directory. */
		chdir(home_dir);

	current_dir = getcwd(NULL, 0);
	custom_setenv(&env, "PWD", current_dir); /* Update env PWD. */
	free(current_dir);
	free(home_dir);
}

/**
 * execute_cd - Executes the cd command.
 * @env: Environmental linked list to update PATH and OLDPWD.
 * @current_dir: Current working directory.
 * @target_dir: Directory path to change to.
 * @arg: The first argument to write out an error.
 * @line_num: The line number to write out an error.
 *
 * Return: 0 if success, 2 if failed.
 */
int execute_cd(list_t *env, char *current_dir, char *target_dir, char *arg, int line_num)
{
	int exit_status = 0;

	if (access(target_dir, F_OK) == 0)
	{
		custom_setenv(&env, "OLDPWD", current_dir); /* Update env OLDPWD. */
		free(current_dir);
		chdir(target_dir);
		current_dir = getcwd(NULL, 0); /* Get current working directory. */
		custom_setenv(&env, "PWD", current_dir); /* Update env PWD. */
		free(current_dir);
	}
	else
	{
		cannot_change_directory(arg, line_num, env);
		free(current_dir);
		exit_status = 2;
	}

	return (exit_status);
}

/**
 * shell_cd - Change directory.
 * @args: User's typed-in command and arguments.
 * @env: Environmental linked list to retrieve HOME and OLDPWD paths.
 * @line_num: The line number to write out an error.
 *
 * Return: 0 if success, 2 if failed.
 */
int shell_cd(char **args, list_t *env, int line_num)
{
	char *current_dir = getcwd(NULL, 0); /* Store the current working directory. */
	char *target_dir = NULL;
	int exit_status = 0;

	if (args[1] != NULL)
	{
		if (args[1][0] == '~') /* Usage: cd ~ */
		{
			target_dir = get_env("HOME", env);
			target_dir = custom_strcat(target_dir, args[1]);
		}
		else if (args[1][0] == '-') /* Usage: cd - */
		{
			if (args[1][1] == '\0')
				target_dir = get_env("OLDPWD", env);
		}
		else /* Usage: cd directory1 */
		{
			if (args[1][0] != '/')
			{
				target_dir = getcwd(NULL, 0);
				target_dir = custom_strcat(target_dir, "/");
				target_dir = custom_strcat(target_dir, args[1]);
			}
			else
				target_dir = _strdup(args[1]);
		}
		exit_status = execute_cd(env, current_dir, target_dir, args[1], line_num);
		free(target_dir);
	}
	else /* Usage: cd */
		change_directory_only(env, current_dir);

	free_double_ptr(args); /* Free user input. */

	return (exit_status);
}
