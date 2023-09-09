#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

extern char **environ;

typedef struct {
	char *command;
	char *args[MAX_INPUT_SIZE / 2];
} Command;

void display_prompt(void);
void execute_command(Command *cmd);
void parse_input(char *input, Command *cmd);


#endif /* shell.h */
