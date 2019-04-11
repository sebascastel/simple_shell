#include "holberton.h"
/**
 * helper_builtin_cd - helper function for biuldtin cd
 * @buff_tk: tokenzied buffer
 * @str: pointer to string
 * @tmp_str: pointer to temp string
 * @argv: program name
 * @input_count: number of commands run so far
 * @stat: exit status
 * Return: always 1
 */
int helper_builtin_cd(char **buff_tk, char *argv, char *str,
	char *tmp_str, size_t input_count, int *stat)
{
	tmp_str = malloc(sizeof(char) * 3);
	tmp_str[0] = buff_tk[1][0];
	tmp_str[1] = buff_tk[1][1];
	tmp_str[2] = '\0';
	str = _strcat(": Illegal option ", tmp_str, "\n");
	error_message(argv, input_count, str, buff_tk);
	free(tmp_str);
	free(str);
	free(buff_tk);
	buff_tk = NULL;
	*stat = 2;
return (1);
}
/**
 * aux_add_str_cd - helper function for biuldtin cd
 * @add_str: pointer to add_str
 * @pwd: pointer to pwd variable
 * @temp: pointer to temp
 * @env: environment variable
 */
void aux_add_str_cd(char *add_str, char *pwd, listint_t *temp, listint_t **env)
{
	add_str = _getenv("OLDPWD", &temp);
	if (add_str == NULL)
	{
		add_str = getcwd(add_str, 0);
		change_pwd(env, "OLDPWD", add_str);
		write(STDOUT_FILENO, add_str, _strlen(add_str));
		write(STDOUT_FILENO, "\n", 1);
		free(add_str);
	}
	else if (chdir(add_str) == 0)
	{
		change_pwd(env, "OLDPWD", pwd);
		add_str = NULL;
		add_str = getcwd(add_str, 0);
		change_pwd(env, "PWD", add_str);
		write(STDOUT_FILENO, add_str, _strlen(add_str));
		write(STDOUT_FILENO, "\n", 1);
		free(add_str);
	}
}
/**
 * aux_check_cd - helper function for biuldtin cd
 * @add_str: pointer to string
 * @argv: arguments
 * @str: pointer to string
 * @pwd: current path
 * @buff_tk: buffer token
 * @env: environment variable
 * @check_cd: variable to check cd
 * @input_count: number of commands run so far
 * @stat: exit status
 * Return: return
 */
int ax_chck(char *add_str, char *argv, char *str, char *pwd,
char **buff_tk, listint_t **env, int check_cd, size_t input_count, int *stat)
{
	if (check_cd == 0)
	{
		add_str = getcwd(add_str, 0);
		change_pwd(env, "OLDPWD", pwd);
		change_pwd(env, "PWD", add_str);
		free(add_str);
	}
	else if (check_cd == -1)
	{
		str = _strcat(": can't cd to ", buff_tk[1], "\n");
		error_message(argv, input_count, str, buff_tk);
		free(str);
		*stat = 2;
		free(buff_tk);
		buff_tk = NULL;
		return (1);
	}
return (0);
}

/**
 * _cd - change current working directory
 * @buff_tk: tokenzied buffer
 * @env: copy of environment values
 * @buff: input string
 * @argv: program name
 * @input_count: number of commands run so far
 * @stat: exit status
 * Return: always 1
 */
int _cd(char **buff_tk, listint_t **env, char *buff,
		char *argv, size_t input_count, int *stat)
{
	int check_cd, tokens = 0, free_pwd = 0;
	listint_t *temp = *env;
	char *add_str = NULL, *pwd = NULL, *str = NULL, *tmp_str = NULL;
	char home[5] = "$HOME";
	(void) buff;

	while (buff_tk[tokens])
		tokens++;
	pwd = _getenv("PWD", &temp);
	if (pwd == NULL)
	{
		free_pwd = 1;
		pwd = getcwd(pwd, 0);
		change_pwd(env, "PWD", pwd);
	}
	if (tokens == 1 || (tokens >= 2 &&
				(buff_tk[1][0] == '~' || _strcmp(buff_tk[1], home) == 0)))
	{
		add_str = _getenv("HOME", &temp);
		check_cd = chdir(add_str);
		if (check_cd == 0)
		{
			change_pwd(env, "OLDPWD", pwd);
			change_pwd(env, "PWD", add_str);
		}
	}
	else if (tokens > 1 && buff_tk[1][0] == '-')
	{
		if (buff_tk[1][1] == '\0')
			aux_add_str_cd(add_str, pwd, temp, env);
		else if (buff_tk[1][1] != '\0')
			helper_builtin_cd(buff_tk, argv, str, tmp_str, input_count, stat);
	}
	else if (tokens > 1)
	{check_cd = chdir(buff_tk[1]);
	ax_chck(add_str, argv, str, pwd, buff_tk, env, check_cd, input_count, stat); }
	if (free_pwd == 1)
		free(pwd);
	free(buff_tk);
return (1);
}
