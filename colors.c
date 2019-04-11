#include "holberton.h"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"
/**
 * red - adds red color to stdin
 */
void red(void)
{
	write(STDOUT_FILENO, RED, _strlen(RED));
}
/**
 * green - adds green color to stdin
 */
void green(void)
{
	write(STDOUT_FILENO, GREEN, _strlen(GREEN));
}
/**
 * yellow - adds yellow color to stdin
 */
void yellow(void)
{
	write(STDOUT_FILENO, YELLOW, _strlen(YELLOW));
}
/**
 * blue - adds blue color to stdin
 */
void blue(void)
{
	write(STDOUT_FILENO, BLUE, _strlen(BLUE));
}
/**
 * reset - resets color to normal
 */
void reset(void)
{
	write(STDOUT_FILENO, RESET, _strlen(RESET));
}
