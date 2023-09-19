#include "shell.h"

/**
 * custom_strcpy - Copy the string pointed to by src, including the
 * terminating null byte ('\0'), to the buffer pointed to by dest.
 *
 * @dest: The buffer to copy the source to.
 * @src: The source string to copy.
 *
 * Return: The copy of the original source.
 */
char *custom_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return dest;
}
