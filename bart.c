#include "holberton.h"
/**
 * bart - print bart
 * Return: Always 1
 */
int bart(void)
{
	int txt_file, total, read_status;
	size_t letters = 5000;
	char *filename = "bart.txt";
	char buffer[1024];

	if (filename == NULL)
		return (0);
	txt_file = open(filename, O_RDONLY);

	if (txt_file == -1)
		return (0);
	total = 0;
	read_status = 1;

	while (letters > 1024 && read_status != 0)
	{
		read_status = read(txt_file, buffer, 1024);
		write(STDOUT_FILENO, buffer, read_status);
		total += read_status;
		letters -= 1024;
	}
	read_status = read(txt_file, buffer, letters);
	write(STDOUT_FILENO, buffer, read_status);
	total += read_status;
	close(txt_file);
return (1);
}
