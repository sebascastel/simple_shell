#include "holberton.h"
#define RESETB "\033[0;30m"
/**
 * resetb - resets color to dark
 */
void resetb(void)
{
	write(STDOUT_FILENO, RESETB, _strlen(RESETB));
}
