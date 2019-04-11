#include "holberton.h"
/**
 * _getenv - searches for the environment string pointed to by name
 * @name: string containing the name of the requested variable.
 * @env: environment string
 * Return: returns the associated value to the string,
 * or NULL if that environment variable does not exist.
 */
char *_getenv(char *name, listint_t **env)
{
	listint_t *temp = *env;

	while (temp)
	{
	if (_strcmp(temp->a, name) == 0)
		return (temp->b);
		temp = temp->next;
	}
return (NULL);
}
