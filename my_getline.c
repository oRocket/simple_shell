#include "shell.h"
/**
 * my_getline - Custom implementation of getline to read input.
 * @lineptr: Pointer to the line buffer.
 * @n: Pointer to the size of the line buffer.
 * @stream: File stream to read from (usually stdin).
 * Returns the number of characters read, or -1 on error.
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t buffer_position = 0, total_chars_read = 0, line_length, remaining_chars;
	char *newline, input_buffer[MAX_INPUT_SIZE];
	ssize_t chars_read;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	/* Check if the buffer needs to be initialized */
	if (*lineptr == NULL || *n == 0)
	{
		*n = MAX_INPUT_SIZE;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
	}

	while (1)
	{
		/* If the buffer is empty, refill it */
		if (buffer_position == 0)
		{
			chars_read = read(STDIN_FILENO, input_buffer, MAX_INPUT_SIZE);
			if (chars_read <= 0)
			{
				/* End of input or error */
				if (total_chars_read == 0)
				{
					return (-1);
				}
				else
				{
					break;  /* Some data read, so return it */
				}
			}
		}
		/* Find the next newline character (if any) in the buffer */
		newline = memchr(input_buffer + buffer_position, '\n', chars_read - buffer_position);
		if (newline != NULL)
		{
			line_length = newline - (input_buffer + buffer_position) + 1;
			if (total_chars_read + line_length > *n)
			{
				/* Resize the line buffer if needed */
				*n = total_chars_read + line_length + 1;
				*lineptr = (char *)realloc(*lineptr, *n);
				if (*lineptr == NULL)
				{
					perror("realloc");
					exit(EXIT_FAILURE);
				}
			}
			/* Copy the line from the buffer to the lineptr */
			memcpy(*lineptr + total_chars_read, input_buffer + buffer_position, line_length);
			total_chars_read += line_length;
			buffer_position += line_length;

			(*lineptr)[total_chars_read] = '\0';
			return (total_chars_read);
		}
		else
		{
			/* No newline found in the buffer, copy the remaining data */
			remaining_chars = chars_read - buffer_position;
			if (total_chars_read + remaining_chars > *n)
			{
				/* Resize the line buffer if needed */
				*n = total_chars_read + remaining_chars + 1;
				*lineptr = (char *)realloc(*lineptr, *n);
				if (*lineptr == NULL)
				{
					perror("realloc");
					exit(EXIT_FAILURE);
				}
			}
			/* Copy the remaining data from the buffer to the lineptr */
			memcpy(*lineptr + total_chars_read, input_buffer + buffer_position, remaining_chars);
			total_chars_read += remaining_chars;
			buffer_position += remaining_chars;
		}
		/* Reset the buffer position if we have reached the end */
		if (buffer_position == (size_t)chars_read)
		{
			buffer_position = 0;
		}
	}
	return (total_chars_read);
}
