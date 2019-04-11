#include "holberton.h"
/**
 * create_arg_list - takes the input buffer and creates argument list
 * @buff_tk: pointer to where the argument lis will be stored
 * @buff: buffer to get argument list from
 * @delim: delimiter to use to delimit buffer
 * Return: pointer to pointer of argument list
 */
char **create_arg_list(char **buff_tk, char *buff, const char *delim)
{
	int count = 0;
	char *toprint, *buffdup;

	buffdup = _strdup(buff);
	toprint = _strtok(buffdup, delim);
	while (toprint)
	{
		toprint = _strtok(NULL, delim);
		count++;
	}
	free(buffdup);
	if (!count)
		return (NULL);
	buff_tk = (char **) malloc((count + 1) * sizeof(char *));
	if (!buff_tk)
		_exit(1);
	toprint = _strtok(buff, delim);
	count = 0;
	while (toprint)
	{
		buff_tk[count] = toprint;
		toprint = _strtok(NULL, delim);
		count++;
	}
	buff_tk[count]  = NULL;
return (buff_tk);
}
