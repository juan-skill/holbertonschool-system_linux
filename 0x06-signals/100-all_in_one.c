#include "signals.h"

/**
 * signal_handler - prints a message
 *
 * @signal: the signal number received
 * @info: signal info
 * @ucontext: signal context
 *
 * Return: nothing
 */
void signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	(void) signal;
	(void) ucontext;
	psiginfo(info, "Caught");
}

/**
 * all_in_one - set a handler for the signal SIGINT
 *
 * Return: Return 0 on success, or -1 on error
 */
void all_in_one(void)
{
	struct sigaction act;
	int signal = 0;

	memset(&act, 0, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = signal_handler;

	for (signal = SIGHUP; signal <= SIGRTMAX; signal++)
		sigaction(signal, &act, NULL);
}
