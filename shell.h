#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define BUFFER_SIZE 1024

/* Define a static buffer for reading input */
static char input_buffer[MAX_INPUT_SIZE];
static size_t buffer_position = 0;  /* Position within the buffer */



extern char **environ;

typedef struct {
	char *command;
	char *args[MAX_INPUT_SIZE / 2];
} Command;

void display_prompt(void);
void execute_command(Command *cmd);
void parse_input(char *input, Command *cmd);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif /* shell.h */
