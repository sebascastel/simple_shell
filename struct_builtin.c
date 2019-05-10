#include "holberton.h"
/**
 * get_builtin - function to find builtin function
 * @buff: program name
 * Return: integer
 */
int (*get_builtin(char **s))(char **buff)
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
		{NULL, NULL}
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
