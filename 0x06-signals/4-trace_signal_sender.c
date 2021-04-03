#include "signals.h"

/**
 * print_msg - catches the signal CTRL-C or SIGINT
 *
 * @signum: the signal
 * @siginfo: the signal's info
 * @context: the signal's context
 *
 * Return: Nothing
 */
void print_msg(int signum, siginfo_t *siginfo, void *context)
{
	(void)signum;
	(void)context;
	printf("SIGQUIT sent by %d\n", (int) siginfo->si_pid);
}

/**
 * trace_signal_sender - defines a handler for the signal SIGQUIT
 * (Control-\ in a shell)
 *
 * Return: -1 if on error or 0 when success
 */
int trace_signal_sender(void)
{
	struct sigaction act;

	memset(&act, '\0', sizeof(act));
	act.sa_sigaction = print_msg;
	act.sa_flags = SA_SIGINFO;

	return (sigaction(SIGQUIT, &act, NULL));
}
