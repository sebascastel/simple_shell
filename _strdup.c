#include "holberton.h"
/**
 * _strdup - duplicates a string
 * @str: string to duplicated
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	char *s;
	int i = 0, j;

	if (!str)
	{
		_exit(1);
	}
	while (*(str + i))
		i++;
	s = malloc(sizeof(char) * i);
	if (s == NULL)
	{
		_exit(1);
	}
	for (j = 0; j < i; j++)
		s[j] = str[j];
return (s);
}
