#include "shell.h"
#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Authors: Albert and Benedict
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int z;

	for (z = 0; z < 15; z++) /* A for loop to print a message 15 times */
	{
		cprint("Hello, Albert and Benedict!\n");
	}
	return (0);
}
