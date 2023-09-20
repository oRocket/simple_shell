#include "shell.h"
/**
 * main - Entry point for the shell program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Authors: Albert and Benedict.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 1)
	{
		print_usage(argv[0]);
		return (1); /* Return an error code */
	}

	run_shell();

	return (0);
}
