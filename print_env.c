#include "holberton.h"
/**
 * permi - check permission
 * @buff_tk: pointer to where the argument list will be stored
 * @argv: program name
 * @input_count: number of commands processed
 * @stat: exit status
 * Return: return 0 if file exist, otherwise, return -1
 */
int permi(char **buff_tk, char *argv, int input_count, int *stat)
{
	if (access(buff_tk[0], F_OK) == 0)
	{
		*stat = 126;
		error_message(argv, input_count, ": Permission denied\n",
			buff_tk);
		free(buff_tk);
		return (0);
	}
	else
		return (-1);
}
