#include "holberton.h"
/**
 * aux_shell - shell prompt function
 */
void aux_shell(void)
{
	char *pl_holder = "†Shell's Bells† ";

	signal(SIGINT, signalhandler);
	if (isatty(STDIN_FILENO))
	{
		red();
		write(STDOUT_FILENO, pl_holder, _strlen(pl_holder));
		reset();
	}
}
/**
 * rd_shell - aux read shell function
 * @leer: variable that holds _getline
 * @buff: buffer
 * @stat: status variable
 * @env_cp: environment copy
 */
void rd_shell(ssize_t leer, char *buff, int stat, listint_t *env_cp)
{
	if (leer == -1)
	{
		free(buff);
		free_list(env_cp);
		stat > 255 ? stat /= 256 : stat;
		_exit(stat);
	}
}
/**
 * stat_helper - aux stat shell function
 * @s: string
 * @buff_tk: buffer token
 * @argv: argument vector
 * @stat: status variable
 * @in_count: input counter
 */
void stat_helper(int stat, char *s, char **argv, char **buff_tk,
ssize_t in_count)
{
	stat = stat;
	error_message(*argv, in_count, s, buff_tk);
	free(buff_tk);
}
/**
 * aux_aux - aux function
 * @buff_tk: buffer token
 * @stat: status variable
 */
void aux_aux(int stat, char **buff_tk)
{
	stat = stat;
	free(buff_tk);
}
/**
 * main - main shell function
 * @argc: number of parameters
 * @argv: arguments list
 * @env: environment variables
 * Return: always 0
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{	listint_t *env_cp = NULL;
	char *path = NULL, *buff = NULL, *buff_tk1 = NULL, **buff_tk = NULL;
	ssize_t leer, in_count = 0, br = 0;
	int check_path = -1, stat = 0;

	get_env(&env_cp, env);
	for (; 1; in_count++)
	{	check_path = -1;
		aux_shell();
		leer = _getline(&buff, &br, stdin);
		rd_shell(leer, buff, stat, env_cp);
		if (buff && buff[0] == '\n')
			continue;
		buff_tk = create_arg_list(buff_tk, buff, " \t\n");
		if (!buff_tk)
			continue;
		if (get_builtin(buff_tk)(buff_tk, &env_cp, buff, argv[0], in_count, &stat))
			continue;
		if (buff_tk[0][0] == '.')
		{
			if (buff_tk[0][1] == '/' && !buff_tk[0][2])
			{ stat_helper(126, ": Permission denied\n", argv, buff_tk, in_count);
				continue; }
			else if (!buff_tk[0][1])
			{	aux_aux(0, buff_tk);
				continue; }	}
		if (buff_tk[0][0] == '/' || buff_tk[0][0] == '.')
		{	check_path = access(buff_tk[0], F_OK);
			if (check_path == -1)
			{ stat_helper(127, ": not found\n", argv, buff_tk, in_count);
				continue; }
			if (access(buff_tk[0], X_OK) == -1)
			{ stat_helper(126, ": Permission denied\n", argv, buff_tk, in_count);
				continue; }	}
		if (check_path == -1)
		{	path = _getenv("PATH", &env_cp);
			buff_tk1 = path_helper(path, buff_tk, argv[0], in_count, &stat);
			if (buff_tk1 == NULL)
				continue; }
		exec_command(argv[0], buff_tk, buff_tk1, buff, check_path, &stat);	}
return (0); }
