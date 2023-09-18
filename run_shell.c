#include "shell.h"
/**
 * Run the shell program.
 */
void run_shell(void)
{
	char input[MAX_INPUT_LENGTH], *args[MAX_ARGS];
	int arg_count, i;
	ShellState shell;

	init_shell(&shell);

	while (1)
	{
		char prompt[] = "$ ";

		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			print_exit_msg(shell.exit_status);
			exit(shell.exit_status);
		}
		input[my_strlen(input) - 1] = '\0';
		split_input(input, args, &arg_count);
		if (arg_count == 0)
		{
			continue;
		}

		if (my_strcmp(args[0], "exit") == 0)
		{
			handle_exit(&shell, args, arg_count);
		}
		else if (my_strcmp(args[0], "setenv") == 0)
		{
			handle_setenv(args, arg_count);
		}
		else if (my_strcmp(args[0], "unsetenv") == 0)
		{
			handle_unsetenv(args, arg_count);
		}
		else if (my_strcmp(args[0], "cd") == 0)
		{
			cd_command(&shell, args, arg_count);
		}
		else
		{
			execute_command(&shell, args);
		}
		for (i = 0; i < arg_count; i++)
		{
			free(args[i]);
		}
	}
}
