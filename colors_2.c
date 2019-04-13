#include "holberton.h"
#define RESETB "\033[0;30m"
#define CYAN "\033[1;36m"
/**
 * resetb - resets color to dark
 */
void resetb(void)
{
	write(STDOUT_FILENO, RESETB, _strlen(RESETB));
}
/**
 * cyan - resets color to dark
 */
void cyan(void)
{
	write(STDOUT_FILENO, CYAN, _strlen(CYAN));
}
