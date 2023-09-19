#include "shell.h"

/**
 * token_length - returns the length of a token
 * @str: input string
 * @pos: starting position in the string
 * @delimiter: delimiter character
 * Return: length of the token
 */
int token_length(char *str, int pos, char delimiter) {
    int length = 0;

    for (; str[pos] != delimiter && str[pos] != '\0'; pos++, length++) {}

    return length;
}

/**
 * token_count - returns the number of tokens separated by delimiters
 * @str: input string
 * @delimiter: delimiter character
 * Return: number of tokens
 */
int token_count(char *str, char delimiter) {
    int num_delimiters = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if ((str[index] == delimiter) && (str[index + 1] != delimiter)) {
            /* Handle continuous delimiters */
            num_delimiters++;
        }
        if ((str[index] == delimiter) && (str[index + 1] == '\0')) {
            /* Handle continuous delimiters after the full command */
            num_delimiters--;
        }
    }

    return (num_delimiters + 1);
}

/**
 * trim_leading_delimiters - returns a version of the string without leading delimiters
 * @str: input string
 * @delimiter: delimiter character
 * Return: new string without leading delimiters
 */
char *trim_leading_delimiters(char *str, char delimiter) {
    for (; *str == delimiter; str++) {}

    return str;
}

/**
 * custom_strtok - tokenizes a string and returns an array of tokens
 * @str: input string
 * @delimiter: delimiter string
 * Return: an array of tokens
 */
char **custom_strtok(char *str, char *delimiter) {
    int buffer_size = 0, position = 0, start_index = 0, token_index = 0, length = 0, string_end = 0;
    char **tokens = NULL, delimiter_char;

    delimiter_char = delimiter[0];
    str = trim_leading_delimiters(str, delimiter_char);
    buffer_size = token_count(str, delimiter_char);
    tokens = malloc(sizeof(char *) * (buffer_size + 2));
    
    if (tokens == NULL) {
        return NULL;
    }

    for (; str[string_end] != '\0'; string_end++) {}

    for (; start_index < string_end; start_index++) {
        if (str[start_index] != delimiter_char) {
            length = token_length(str, start_index, delimiter_char);
            tokens[position] = malloc(sizeof(char) * (length + 1));
            
            if (tokens[position] == NULL) {
                return NULL;
            }

            for (token_index = 0; (str[start_index] != delimiter_char) && (str[start_index] != '\0'); token_index++, start_index++) {
                tokens[position][token_index] = str[start_index];
            }
            tokens[position][token_index] = '\0';
            position++;
        }

        if (start_index < string_end && (str[start_index + 1] != delimiter_char && str[start_index + 1] != '\0')) {
            position++;
        }
    }

    position++;
    tokens[position] = NULL;
    return tokens;
}
