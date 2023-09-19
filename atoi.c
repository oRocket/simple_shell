#include "shell.h"

/**
 * custom_atoi - Custom string to integer conversion
 * @str: The input string
 *
 * Return: The integer value if successful, -1 on error
 */
int custom_atoi(char *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
        }
        else
        {
            return -1; // Invalid character found
        }
    }

    return result;
}

/**
 * exit_shell - Exit the shell program with an optional exit status
 * @args: An array of strings representing user input tokens
 * @env_list: A linked list representing environmental variables
 * @command: An array of strings representing a command
 * @num_cmds: The nth user command line input
 *
 * Return: 0 if successful, 2 on error
 */
int exit_shell(char **args, list_t *env_list, char **command, int num_cmds)
{
    int exit_status = 0;

    if (args[1] != NULL) // Check if an exit status is provided
    {
        exit_status = custom_atoi(args[1]);

        if (exit_status == -1) // Invalid exit status provided
        {
            print_error(args[1], num_cmds, env_list);
            cleanup_memory(args, env_list, command);
            return 2;
        }
    }

    cleanup_memory(args, env_list, command);
    exit(exit_status);
}

/**
 * cleanup_memory - Free memory allocated for arguments, environmental variables, and commands
 * @args: An array of strings representing user input tokens
 * @env_list: A linked list representing environmental variables
 * @command: An array of strings representing a command
 */
void cleanup_memory(char **args, list_t *env_list, char **command)
{
    free_string_array(args);
    free_linked_list(env_list);

    if (command != NULL)
    {
        free_string_array(command);
    }
}

/**
 * free_string_array - Free memory allocated for an array of strings
 * @str_array: An array of strings
 */
void free_string_array(char **str_array)
{
    if (str_array != NULL)
    {
        for (int i = 0; str_array[i] != NULL; i++)
        {
            free(str_array[i]);
        }
        free(str_array);
    }
}

/**
 * free_linked_list - Free memory allocated for a linked list (placeholder)
 * @list: A linked list
 */
void free_linked_list(list_t *list)
{
    /* Implement the code to free the linked list here (placeholder) */
}

/**
 * print_error - Print an error message (placeholder)
 * @msg: The error message to be printed
 * @num_cmds: The nth user command line input
 * @env_list: A linked list representing environmental variables (placeholder)
 */
void print_error(char *msg, int num_cmds, list_t *env_list)
{
    printf("Error: %s\n", msg);
    printf("Occurred during the execution of command #%d\n", num_cmds);
}
