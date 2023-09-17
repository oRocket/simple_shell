#include "shell.h"
/**
 * split_input - Split a string into arguments
 * @input: The input string to split
 * @args: An array to store the split arguments
 * @arg_count: A pointer to an integer to store the number of arguments
 * Return: No return.
 */
void split_input(const char *input, char *args[], int *arg_count)
{
	const char *start = input;
	int length;
	*arg_count = 0;

	while (*input != '\0')
	{
		while (*input == ' ' || *input == '\t')
		{
			input++;
		}

		start = input;

		while (*input != ' ' && *input != '\t' && *input != '\0')
		{
			input++;
		}

		if (start != input)
		{
			length = input - start;
			args[*arg_count] = (char *)malloc(length + 1);
			if (args[*arg_count] == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strncpy(args[*arg_count], start, length);
			args[*arg_count][length] = '\0';
			(*arg_count)++;
		}

		if (*arg_count >= MAX_ARGS)
		{
			break;
		}
	}
}
