#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <limits.h> /* PATH_MAX */
#include <errno.h>  /* errno */

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
#define MAX_INPUT_SIZE 1024
extern size_t buffer_position;
extern char input_buffer[MAX_INPUT_SIZE];


/* Struct to hold shell state */
typedef struct {
    char current_dir[PATH_MAX];
    int exit_status;
} ShellState;

/* Custom function to split input into arguments */
void split_input(const char *input, char *args[], int *arg_count);

/* Function to initialize the shell state */
void init_shell(ShellState *shell);

/* Function to handle the "cd" command */
void cd_command(ShellState *shell, char *args[], int arg_count);


/* Function to execute external commands */
void execute_command(ShellState *shell, char *args[]);

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

#endif /* shell.h */
