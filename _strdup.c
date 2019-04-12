#include "holberton.h"
/**
 * _strdup - duplicates a string
 * @str: string to duplicated
 * Return: pointer to new string
 */
char *_strdup(char *str)
{
	char *s;
	int size = 0, i;

	if (!str)
		_exit(1);
	while (*(str + size))
		size++;
	s = malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		_exit(1);
	for (i = 0; i < size; i++)
		s[i] = str[i];
	s[i] = '\0';
return (s);
}
