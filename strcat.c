#include "holberton.h"
/**
 * _strcat - concatenates three strings.
 * @dest: the string need to concatenated
 * @src: the string need to concatenated
 * @str: the string need to concatenated
 * Return: return a pointer to the resultring string result
 */
char *_strcat(char *dest, char *src, char *str)
{
	int total_len = 0;
	int i = 0, l = 0, m = 0, n = 0;
	char *result = NULL;

	if (!dest || !src || !str)
		return (NULL);
	total_len = _strlen(dest) + _strlen(src) + _strlen(str);
	result = malloc(sizeof(char) * (total_len + 1));
	if (!result)
		_exit(1);
	for (i = 0; i < total_len; i++)
	{
		if (dest[l] != '\0')
		{
			result[i] = dest[l];
			l++;
		}
		else if (dest[l] == '\0' && src[m] != '\0')
		{
			result[i] = src[m];
			m++;
		}
		else if (src[m] == '\0' && str[n] != '\0')
		{
			result[i] = str[n];
			n++;
		}
	}
	result[i] = '\0';
	return (result);
}
