#include "holberton.h"
/**
 * _strcmp - compares 2 strings
 * @s1: string1 to compare
 * @s2: string2 to compare
 * Return: -1,0,1 if string1 <, =, > string2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, diff = 0;

	while (*(s1 + i) != 0 && *(s2 + i) != 0 && diff == 0)
	{
		diff = (*(s1 + i) - *(s2 + i));
		i++;
	}
	if (diff != 0)
	{
		return (diff);
	}
	else
	{
		if (*(s1 + i) == 0 && *(s2 + i) == 0)
			return (0);
		else
			return (*(s1 + i) - *(s2 + i));
	}
}
