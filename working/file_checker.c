#include "shell.h"
/**
 * file_checker - a function that checks if a file is available
 * @whole_path: pointer to the full file name
 * Return: 0 success
 */
int file_checker(char *whole_path)
{
	struct stat cu;

	if (stat(whole_path, &cu) != -1)
	{
		if (S_ISDIR(cu.st_nd) || access(whole_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
