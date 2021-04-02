#include "signals.h"

/**
 * print_msg - catchs the signal CTRL-C or SIGINT
 *
 * @signal: the signal nothing
 *
 * Return: Nothing
 */
void print_msg(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}

/**
 * handle_sigaction - sets a handler for the signal SIGINT
 *
 * Return: -1 if on error or 0 when success
 */
int handle_sigaction(void)
{
	struct sigaction act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = print_msg;

	return (sigaction(SIGINT, &act, NULL));
}
