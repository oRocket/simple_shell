#include "shell.h"
/**
 * benedict - shows prompt in a loop
 * @prompt: print prompt
 * @data: data to be showed of prompt
 */
void benedict(char *prompt, program_data *data)
{
	int err = 0, str_l = 0;

	while (++(data->exe))
	{
		print_f(prompt);
		err = str_l = get_line(data);

		if (err == EOF)
		{
			free_data(data);
			exit(errno);
		}
		if (str_l >= 1)
		{
			icr_alias(data);
			icr_var(data);
			tok(data);
			if (data->tokens[0])
			{
				err = exc(data);
				if (err != 0)
					print_err(error_code, data);
			}
			free_rec(data);
		}
	}
}
