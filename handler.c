#include "holberton.h"
/**
 * signalhandler - handles the ctrl-c key to keep looping
 * @sig: signal
 */
void signalhandler(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n\r$ ", 4);
}
