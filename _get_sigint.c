#include "main.h"

/**
 * get_sigint - the function that handle the crtl + c call in prompt
 *
 * @sig: is Signal handler
 *
 * Return: is nothing
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
