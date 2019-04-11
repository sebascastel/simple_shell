#include "holberton.h"
/**
 * _notfound - function core for whole shell
 * @buff_tk: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * @buff: buffer
 * @argv: program name
 * @input_count: number of commands processed
 * @stat: exit status
 * Return: always 2
 */
int _notfound(char **buff_tk, listint_t **env, char *buff,
	char *argv, size_t input_count, int *stat)
{
	(void) buff_tk;
	(void) env;
	(void) buff;
	(void) argv;
	(void) input_count;
	(void) stat;

	return (0);
}
