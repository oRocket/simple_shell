#include "shell.h"
/**
 * main - Entry point of the programme
 * Return: Always 0 (Success)
 */
int main(void)
{
	char input[MAX_INPUT_SIZE], **env = environ;
	ssize_t read_size;
	Command cmd;

	while (1)
	{
		display_prompt();
		read_size = read(STDIN_FILENO, input, MAX_INPUT_SIZE);

		if (read_size == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		else if (read_size == 0)
		{
			printf("\n");
			break;
		}
		input[read_size - 1] = '\0';

		if (strcmp(input, "env") == 0)
		{
			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			continue;
		}

		if (strcmp(input, "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}

		parse_input(input, &cmd);
		execute_command(&cmd);
	}
	return (0);
}
