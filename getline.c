#include "holberton.h"
/**
 * aux_getline - aux function of getline
 * @p: double pointer
 * @n: size of characters
 * @buffer: buffer to be allocated
 * @b: size of character to be replaced
*/
void aux_getline(char **p, ssize_t *n, char *buffer, ssize_t b)
{
	if (*p == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*p = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*p = buffer;
	}
	else
	{
		_strcpy(*p, buffer);
		free(buffer);
	}
}
/**
 * _getline - aux function of getline
 * @p: double pointer
 * @n: size of characters
 * @s: pointer to file to be read
 * Return: j.
*/
ssize_t _getline(char **p, ssize_t *n, FILE *s)
{
	static ssize_t i;
	ssize_t j;
	char c = 'x';
	char *buffer;
	int a;

	if (i == 0)
		fflush(s);
	else
		return (-1);
	buffer = malloc(sizeof(char) * 120);
	if (buffer == NULL)
		return (-1);
	for (i = 0; c != '\n'; i++)
	{
		a = read(STDIN_FILENO, &c, 1);
		if (a == -1 || (a == 0 && a == 0))
		{
			free(buffer);
			return (-1);
		}
		if (a == 0 && i != 0)
		{
			i++;
			break;
		}
		if (i >= 120)
			buffer = _realloc(buffer, i, i + 1);
		buffer[i] = c;
	}
	buffer[i] = '\0';
	aux_getline(p, n, buffer, i);
	j = i;
	if (a != 0)
		i = 0;
return (j);
}
