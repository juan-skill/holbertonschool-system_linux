#include "signals.h"

#define FAIL -1


/**
 * print_msg - prints msg to the stdout
 *
 * @signal: signal to print
 *
 * Return: nothing
 */
void print_msg(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}

/**
 * handle_signal - Sets a handler for the signal SIGINT
 *
 * Return: 0 if it is SUCCESS, otherwise -1 (if error)
 */
int handle_signal(void)
{
	if (signal(SIGINT, print_msg) == SIG_ERR)
	{
		return (FAIL);
	}

	return (EXIT_SUCCESS);
}
