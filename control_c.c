#include "shell.h"

/**
 * ctrl_c - prompt printing
 *
 * @UNUSED: optional
 *
 * Authors: Benedict and Albert
 *
 * Return: No return
 */
void ctrl_c(int opr UNUSED)
{
	print_f("\n");
	print_f(PROMPT_MSG);
}
