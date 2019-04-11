#ifndef DOGO
#define DOGO
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
/**
 * struct listint_s - linked list
 * @a: key value of environment variable
 * @b: value of environment variable
 * @next: Next node
 */
typedef struct listint_s
{
	char *a;
	char *b;
	struct listint_s *next;
} listint_t;
/**
 * struct builtin - Struct builtin
 *
 * @name: Name of builtin
 * @func: Function for the buildint
 */
typedef struct builtin
{
	char *name;
	int (*func)();
} builtin_t;
void exec_command(char *argv, char **buff_tk, char *buff_tk1,
		char *buff, int check_path, int *stat);
void signalhandler(int sig);
/**
 * get_builtin - function to find builtin function
 * @argv: program name
 * @input_count: number of commands processed
 * @buff: buffer value
 * @stat: exit status
 * Return: integer
 */
int (*get_builtin(char **s))(char **buff_tk, listint_t **env,
	char *buff, char *argv, size_t input_count, int *stat);
/* shell collection */
void aux_shell(void);
void rd_shell(ssize_t leer, char *buff, int stat, listint_t *env_cp);
void stat_helper(int stat, char *s, char **argv, char **buff_tk,
ssize_t in_count);
void aux_aux(int stat, char **buff_tk);

listint_t *add_node_end(listint_t **head, char *a, char *b);
int delete_node_at_index(listint_t **head, unsigned int index);
void get_env(listint_t **head, char **env);
void free_list(listint_t *head);
char *make_key_val(char *tempstr);
/* cd collection */
int helper_builtin_cd(char **buff_tk, char *argv, char *str,
	char *tmp_str, size_t input_count, int *stat);
int aux_check_cd(char *add_str, char *argv, char *str, char *pwd,
char **buff_tk, listint_t **env, int check_cd, size_t input_count, int *stat);
int builtin_cd(char **buff_tk, listint_t **env, char *buff,
	char *argv, size_t input_count, int *stat);
void aux_add_str_cd(char *add_str, char *pwd,
	listint_t *temp, listint_t **env);
/* end */
int change_pwd(listint_t **env_cp, char *a, char *add);
int builtin_unsetenv(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int builtin_setenv(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int builtin_notfound(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int builtin_env(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
/* exit collection */
int helper_builtin_exit(char **buff_tk,
	char *argv, char *str, size_t input_count, int *stat, int err_num);
int builtin_exit(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat);
int _strcmp(char *s1, char *s2);
char *_getenv(char *name, listint_t **env);
char *_strcat(char *dest, char *src, char *str);
/* path collection */
char *aux_path(char *argv, char *path_cp, char *concat_path, char **path_tk,
	char **buff_tk, size_t input_count, int *stat);
char *path_helper(char *path, char **buff_tk, char *argv,
		size_t input_count, int *stat);
int _strlen(char *s);
char *num_to_str(size_t n);
int error_message(char *argv, int input_count, char *error, char **buff_tk);
int permi(char **buff_tk, char *argv, int input_count, int *stat);
int check_input(char *buff);
char *_strdup(char *str);
char **create_arg_list(char **buff_tk, char *buff, const char *delim);
/* strtok collection */
unsigned int check_match(char c, const char *str);
char *_strtok(char *str, const char *delim);
/* new prototypes*/
char *_strcpy(char *dest, const char *src);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void aux_getline(char **p, ssize_t *n, char *buffer, ssize_t b);
ssize_t _getline(char **p, ssize_t *n, FILE *s);
/* colors collection */
void red(void);
void green(void);
void yellow(void);
void blue(void);
void reset(void);
void resetb(void);
/* beta testing */
int bart(void);
int welcome(void);
/* help collection */
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_all(void);
int _help(char **args);
#endif
