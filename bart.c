#include "holberton.h"
#define MAX_LEN 128
/**
 * display_splash_screen - function that prints a file
 * @file_ptr: file to be opened
 */
void display_splash_screen(FILE *file_ptr)
{
	char read_string[MAX_LEN];

	while (fgets(read_string, sizeof(read_string), file_ptr) != NULL)
		write(STDOUT_FILENO, read_string, _strlen(read_string));
}
/**
 * bart - print bart
 * Return: Always 1
 */
int bart(void)
{
	char *filename = "bart.txt";
	FILE *fptr = NULL;

	fptr = fopen(filename, "r");
	if (!fptr)
	{
		fprintf(stderr, "error opening %s\n", filename);
		return (1);
	}
	display_splash_screen(fptr);
	fclose(fptr);
return (0);
}
