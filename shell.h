#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

#include "alx.h" /* macros */
/************* STRUCTURES **************/

/**
 * struct program_data - struct for the program's data
 * @name: the name of the executable
 * @input: pointer to the input read for get_line
 * @cmd: pointer to the first command typed by the user
 * @exe: number of executed commands
 * @fd: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases.
 */
typedef struct program_data
{
	char *name;
	char *input;
	char *cmd;
	int exe;
	int fd;
	char **tokens;
	char **env;
	char **alias_list;
} program_data;

/**
 * struct builtins - struct for the inbuilt
 * @inbuilt: the name of the inbuilt
 * @function: the associated function to be called for each inbuilt
 */
typedef struct inbuilt
{
	char *inbuilt;
	int (*function)(program_data *data);
} inbuilt;


/************* MAIN FUNCTIONS *************/

/*========  shell.c  ========*/

void start_d(program_data *data, int arc, char *argv[], char **env);
void benedict(char *prompt, program_data *data);
void ctrl_c(int opr UNUSED);
int get_line(program_data *data);
int chc_op(char *array_cmd[], int i, char array_optr[]);
void icr_var(program_data *data);
void icr_alias(program_data *data);
int buffer_sum(char *buffer, char *str_to_add);
void tok(program_data *data);
char *str_tok(char *line, char *del);
int exc(program_data *data);


/*======== builtins_list.c ========*/

int inbuilt_l(program_data *data);


/*======== find_in_path.c ========*/

char **tok_path(program_data *data);
int f_p(program_data *data);
int file_checker(char *whole_path);

/************** HELPERS FOR MEMORY MANAGEMENT **************/

/*======== helpers_free.c ========*/

void free_ar_pt(char **dir);
void free_rec(program_data *data);
void free_dt(program_data *data);


/************** BUILTINS **************/


/*======== builtins_more.c ========*/

int e_xit(program_data *data);
int _cd(program_data *data);
int pwd(program_data *data, char *new_dir);
int _help(program_data *data);
int _alias(program_data *data);


/*======== builtins_env.c ========*/

int _env(program_data *data);
int set_env(program_data *data);
int unset_env(program_data *data);


/************** HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT **************/

/*======== env_management.c ========*/

char *env_key(char *name, program_data *data);
int env_set(char *key, char *value, program_data *data);
int env_rm(char *key, program_data *data);
void _environmt(program_data *data);


/************** HELPERS FOR PRINTING **************/

/*======== helpers_print.c ========*/

int print_f(char *string);
int print(char *string);
int print_err(int err, program_data *data);


/************** HELPERS FOR STRINGS MANAGEMENT **************/

/*======== helpers_string.c ========*/
int str_l(char *string);
char *str_d(char *string);
int str_c(char *string1, char *string2, int number);
char *str_ccat(char *string1, char *string2);
void str_rev(char *string);


/*======== helpers_numbers.c ========*/
void l_str(long cocte, char *string, int base);
int a_toi(char *s);
int c_xtr(char *string, char *xtr);


/*======== alias_management.c ========*/
int p_alias(program_data *data, char *alias);
char *g_alias(program_data *data, char *alias);
int s_alias(char *alias_string, program_data *data);


#endif /* SHELL_H */
