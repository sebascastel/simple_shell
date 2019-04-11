#include "holberton.h"
/**
 * _strcpy - copies the string pointed by src to ptr dest
 * @src: pointer to source string
 * @dest: pointer to be included src into
 * Return: dest pointer.
*/
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
