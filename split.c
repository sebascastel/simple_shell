#include "holberton.h"
/**
 * make_key_val - takes a string and split it into key value pair
 * @tempstr: string to split
 * Return: the value
 */
char *make_key_val(char *tempstr)
{
	int col = 0;
	char *temp_val;

	while (tempstr[col] != '=' && tempstr[col])
		col++;
	temp_val = &tempstr[col + 1];
	tempstr[col] = '\0';
return (temp_val);
}
