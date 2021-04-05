#include "signals.h"

#define SUCCESS 0
#define ONERROR -1

/**
 * sigset_init - initializes a sigset
 *
 * @set: sigset to initialize
 * @signals: 0-terminated array of signals
 * one each being a signal number
 *
 * Return: 0 if on success else -1 on error
 */
int sigset_init(sigset_t *set, int *signals)
{
	sigemptyset(set);
	/* *signals == 0 end of array */
	while (*signals != 0)
	{
		if (sigaddset(set, *signals))
			return (ONERROR);

		signals++;
	}

	return (SUCCESS);
}
