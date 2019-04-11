#include "holberton.h"
/**
 * _env - function to print env
 * @buff_tk: pointer to pointer of commands entered
 * @env: pointer to pointer of env
 * @buff: pointer to buffer
 * @argv: program name
 * @input_count: number of commands processed
 * @stat: exit status
 * Return: 1 if command is env, 0 otherwise
 */
int _env(char **buff_tk, listint_t **env, char *buff,
	char *argv, size_t input_count, int *stat)
{
	int   tokens = 0, len = 0;
	listint_t *temp = *env;
	char *tempstr;

	(void) buff;
	(void) argv;
	(void) input_count;
	(void) stat;
	while (buff_tk[tokens])
		tokens++;
	if (tokens > 1)
		return (0);
	while (temp)
	{
		tempstr = _strcat(temp->a, "=", temp->b);
		len = _strlen(tempstr);
		write(STDOUT_FILENO, tempstr, len);
		write(STDOUT_FILENO, "\n", 1);
		free(tempstr);
		temp = temp->next;
	}

	free(buff_tk);
return (1);
}
