#include "shell.h"

/**
 * get_line - Read and store the user's command in a dynamically allocated buffer.
 * @user_input: Pointer to the buffer that will store the user's command.
 *
 * Return: Number of characters read on success, -1 on error.
 */
ssize_t get_line(char **user_input)
{
    ssize_t chars_read = 0;
    ssize_t total_chars = 0;
    char buffer[1024];

    int newline_found = 0;

    for (; !newline_found && (chars_read = read(STDIN_FILENO, buffer, sizeof(buffer) - 1));)
    {
        if (chars_read == -1) /* Check if read errored */
            return -1;

        buffer[chars_read] = '\0'; /* Terminate buffer with '\0' to use with _strcat */

        ssize_t i = 0;
        while (buffer[i] != '\0')
        {
            if (buffer[i] == '\n')
                newline_found = 1;
            i++;
        }

        if (*user_input == NULL) /* Allocate memory for the first time */
        {
            chars_read++;
            *user_input = malloc(sizeof(char) * chars_read);
            *user_input = _strcpy(*user_input, buffer);
            total_chars = chars_read;
        }
        else /* Reallocate using _strcat in each iteration */
        {
            total_chars += chars_read;
            *user_input = _strcat(*user_input, buffer);
        }
    }

    return total_chars;
}
