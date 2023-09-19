#include "shell.h"

/**
 * custom_strcmp - Compare two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: 0 if the strings are exactly the same, otherwise the difference
 *         between the ASCII values of the first differing characters.
 */
int custom_strcmp(char *str1, char *str2)
{
    for (int i = 0; str1[i] == str2[i] && str1[i]; i++)
    {
        if (!str2[i])
            return 0;
    }

    return (str1[i] - str2[i]);
}
