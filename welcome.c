#include "holberton.h"
/**
 * welcome - prints welcome message
 * Return: Always 1
 */
int welcome(void)
{
	char *filename = "welcome.txt";
	FILE *fptr = NULL;
	char *error = "error opening file \n";

	fptr = fopen(filename, "r");
	if (!fptr)
	{
		write(STDERR_FILENO, error, _strlen(error));
		return (1);
	}
	display_splash_screen(fptr);
	fclose(fptr);
return (0);
}
