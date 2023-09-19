#ifndef SHELL
#define SHELL

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - linked list for environmental variables
 * @var: holds environmental variable string
 * @next: points to next node
 */
typedef struct list_t
{
	char *var;
	struct list *next;

} list_t;

size_t print_linked_list(list_t *head);
ist_t *add_node_to_end(list_t **head, const char *str);
list_t *create_env_linked_list(char **env_vars);
int delete_node_at_index(list_t **head, unsigned int index);
void free_linked_list(list_t *list);
int count_digits(int n);
char *int_to_string(int number);
char *custom_strdup_excluded(const char *str, int exclude_bytes);
char *get_environment_variable(const char *variable_name, list_t *env_list);
void free_string_array(char **array);
int display_env(char **command_tokens, list_t *env_list);
int count_tokens(char *str, char delimiter);
char **custom_strtok(char *str, char *delimiter);
char *_which(char *str, list_t *env);
int token_length(char *str, int pos, char delimiter);
int token_count(char *str, char delimiter);
char *trim_leading_delimiters(char *str, char delimiter);
char **custom_strtok(char *str, char *delimiter);
char *custom_strdup(const char *str);
char *custom_strcpy(char *dest, const char *src);
int custom_strcmp(char *str1, char *str2);
char *custom_strcat(char *dest, char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
ssize_t get_line(char **user_input);
void exit_shell(char **command_tokens, list_t *env_list);
int execute_command(char **command_tokens, list_t *env_list, int num);
char *custom_strcat(char *dest, char *src);
int custom_setenv(list_t **env, char *name, char *dir);
void change_directory_only(list_t *env, char *current_dir);
int execute_cd(list_t *env, char *current_dir, char *target_dir, char *arg, int line_num);
int shell_cd(char **args, list_t *env, int line_num);
int custom_atoi(char *str);
int exit_shell(char **args, list_t *env_list, char **command, int num_cmds);
void cleanup_memory(char **args, list_t *env_list, char **command);
void free_string_array(char **str_array);
void free_linked_list(list_t *list);
void print_error(char *msg, int num_cmds, list_t *env_list);
int main(void);



int find_env(list_t *env, char *str);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);
void ctrl_c(int n);
int built_in(char **token, list_t *env, int num, char **command);
char *ignore_space(char *str);
void ctrl_D(int i, char *command, list_t *env);
int prompt(char **en);
void not_found(char *str, int c_n, list_t *env);
void cant_cd_to(char *str, int c_n, list_t *env);
char *custom_ignore(char *str);
void non_interactive(list_t *env);
int main(int ac, char **av, char **env);


#endif
