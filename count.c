#include "shell.h"

/**
 * count_tokens - counts the number of tokens separated by delimiters
 * @str: user's command typed into shell
 * @delimiter: delimiter character (e.g., ' ')
 * Return: number of tokens
 */
int count_tokens(char *str, char delimiter)
{
    int token_count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == delimiter)
        {
            token_count++;
        }
    }
    return (token_count + 1); /* Add 1 to account for the last token */
}

/**
 * custom_strtok - tokenizes a string even with continuous delimiters
 * (e.g., "path" --> ":/bin::/bin/usr")
 * @str: user's command typed into shell
 * @delimiter: delimiter character (e.g., ' ')
 * Return: an array of tokens (e.g., {"", "/bin", "", "/bin/usr"})
 * (purpose is to have "which" command look through the current directory if ":")
 */
char **custom_strtok(char *str, char *delimiter)
{
    int buffer_size = 0, token_index = 0, string_index = 0, len = 0, string_end = 0;
    char **tokens = NULL, delimiter_char;

    /* Set the delimiter character */
    delimiter_char = delimiter[0];

    /* Determine the number of tokens */
    buffer_size = count_tokens(str, delimiter_char);

    /* Allocate memory for the array of tokens */
    tokens = malloc(sizeof(char *) * (buffer_size + 2));

    if (tokens == NULL)
    {
        return NULL;
    }

    /* Find the end of the string */
    for (; str[string_end] != '\0'; string_end++) {}

    /* Iterate from the beginning of the string to the end */
    while (string_index < string_end)
    {
        /* Allocate memory for each token */
        len = token_length(str, string_index, delimiter_char);
        tokens[token_index] = malloc(sizeof(char) * (len + 1));

        if (tokens[token_index] == NULL)
        {
            return NULL;
        }

        /* Copy the characters of the token into the array */
        for (int i = 0; (str[string_index] != delimiter_char) && (str[string_index] != '\0'); i++, string_index++)
        {
            tokens[token_index][i] = str[string_index];
        }

        /* Null-terminate the token */
        tokens[token_index][len] = '\0';
        
        /* Move to the next token */
        token_index++;
        
        /*  Move to the next character after the delimiter */
        string_index++;
    }

    /* Set the last array pointer to NULL */
    tokens[token_index] = NULL;

    return tokens;
}
