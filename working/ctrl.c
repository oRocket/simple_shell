#include "shell.h"
/**
 * ctrl_c - prompt printing
 *
 * @UNUSED: optional
 */
void ctrl_c(int opr UNUSED)
{
	print_f("\n");
	print_f(PROMPT_MSG);
}
