#include "shell.h"

/**
 * custom_strcat - Concatenate two strings.
 * @dest: The destination string to be appended to.
 * @src: The source string to append.
 *
 * Return: The concatenated string.
 */
char *custom_strcat(char *dest, char *src)
{
    int dest_len = 0;
    int src_len = 0;

    /* Calculate the length of the destination string. */
    for (; dest[dest_len] != '\0'; dest_len++);

    /* Calculate the length of the source string. */
    for (; src[src_len] != '\0'; src_len++);

    int total_len = dest_len + src_len;
    char *result = malloc(sizeof(char) * (total_len + 1));

    if (result == NULL)
        return (NULL);

    int i, j;

    /* Copy the destination string to the result. */
    for (i = 0; i < dest_len; i++)
        result[i] = dest[i];

    /* Append the source string to the result. */
    for (j = 0; j < src_len; i++, j++)
        result[i] = src[j];

    result[i] = '\0';

    return result;
}
