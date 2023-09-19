#include "shell.h"

/**
 * exit_shell - Free resources and exit the shell.
 * @command_tokens: An array of command tokens.
 * @env_list: A linked list of environment variables.
 */
void exit_shell(char **command_tokens, list_t *env_list)
{
    free_string_array(command_tokens);
    free_linked_list(env_list);
    _exit(0);
}

/**
 * execute_command - Execute the command typed by the user.
 * @command_tokens: An array of command tokens.
 * @env_list: A linked list of environment variables.
 * @num: The nth user command; used in error messages.
 * 
 * Return: 0 on success, 127 if the command is not found or not executable.
 */
int execute_command(char **command_tokens, list_t *env_list, int num)
{
    char *command_path;
    int status = 0;
    pid_t pid;

    /* Check if the command is an absolute path */
    if (access(command_tokens[0], F_OK) == 0)
    {
        command_path = command_tokens[0];
    }
    else
    {
        /* Otherwise, find the full path to the command */
        command_path = find_command_path(command_tokens[0], env_list);
    }

    /* Check if the command is executable */
    if (access(command_path, X_OK) != 0)
    {
        not_found(command_tokens[0], num, env_list);
        free_string_array(command_tokens);
        if (command_path != command_tokens[0])
            free(command_path);
        return 127;
    }

    pid = fork();
    if (pid == 0) /* Child process */
    {
        if (execve(command_path, command_tokens, NULL) == -1)
        {
            not_found(command_tokens[0], num, env_list); /* Special error message */
            exit_shell(command_tokens, env_list);
        }
    }
    else /* Parent process */
    {
        wait(&status);
        free_string_array(command_tokens);
        if (command_path != command_tokens[0])
            free(command_path);
    }

    return 0;
}
