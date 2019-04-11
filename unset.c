#include "holberton.h"
/**
 * _unsetenv -  removes environment variable
 * @buff_tk: tokenized buffer
 * @env: linked list of environment variable
 * @buff: input buffer
 * @argv: program name
 * @input_count: number of commands executed
 * @stat: exit code
 * Return: 0 if successful 1 otherwise
 */
int _unsetenv(char **buff_tk, listint_t **env, char *buff,
	char *argv, size_t input_count, int *stat)
{
	listint_t *temp = *env;
	unsigned int index = 0;
	int tokens = 0;

	(void) buff;
	while (buff_tk[tokens])
		tokens++;
	if (tokens < 2)
	{
		*stat = 0;
		error_message(argv, input_count,
			": Invalid Argument for unsetenv\n", buff_tk);
	}
	else
	{
		while (temp && _strcmp(buff_tk[1], temp->a))
		{
			index++;
			temp = temp->next;
		}
		if (temp)
		{
			if (delete_node_at_index(env, index) == -1)
			{
				error_message(argv, input_count,
					": unsetenv failed\n", buff_tk);
			}
		}
		else
		{
			*stat = 1;
			error_message(argv, input_count,
				": Environment Variable not found\n", buff_tk);
		}
		*stat = 0;
	}
	free(buff_tk);
return (1);
}
