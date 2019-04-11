#include "holberton.h"
/**
 * num_to_str - convert integer to string
 * @n: the number that need to convert
 * Return: return the converted string
 */
char *num_to_str(size_t n)
{
	char *str = NULL;
	int len = 1, n_cp = n, i = 0, tmp;

	if (n_cp / 10 != 0)
	{
		len++;
		n_cp = n_cp / 10;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		_exit(1);
	str[i + len] = '\0';
	while (n >= 10)
	{
		tmp = n % 10;
		str[i + len - 1] = tmp + '0';
		len--;
		n = n / 10;
	}
	str[i] = n + '0';
return (str);
}
