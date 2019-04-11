#include "holberton.h"
/**
 * get_builtin - function to find builtin function
 * @argv: program name
 * @input_count: number of commands processed
 * @env: environment
 * @buff: buffer value
 * @stat: exit status
 * Return: integer
 *
 */
int (*get_builtin(char **s))(char **buff_tk, listint_t
	**env, char *buff, char *argv, size_t input_count, int *stat)
{
	builtin_t builtins[] = {
		{"exit", s_exit},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", _cd},
		{"bart", bart},
		{"help", _help},
		{"welcome", welcome},
		{NULL, _notfound}
	};
	int i = 0;

	while (builtins[i].name)
	{
		if (_strcmp(builtins[i].name, s[0]) == 0)
			return (builtins[i].func);
		i++;
	}
return (builtins[i].func);
}
