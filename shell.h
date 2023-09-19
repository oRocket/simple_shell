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

void handle_unsetenv(char *args[], int arg_count);
void handle_setenv(char *args[], int arg_count);
void handle_exit(ShellState *shell, char *args[], int arg_count);
void print_exit_msg(int status);
void run_shell(void);
void print_usage(const char *program_name);

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
size_t my_strlen(const char *str);
int my_strcmp(const char *str1, const char *str2);

#endif /* shell.h */
