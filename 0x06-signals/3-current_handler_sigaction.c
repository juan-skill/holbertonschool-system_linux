#include "signals.h"

/**
* current_handler_sigaction - retrieves the current handler
* of the signal SIGINT
*
* Return: pointer to the current handler of SIGINT, or NULL on failure
*/
void (*current_handler_sigaction(void))(int)
{
	struct sigaction oldact;

	memset(&oldact, 0, sizeof(oldact));
	if (sigaction(SIGINT, NULL, &oldact) == -1)
		return (NULL);

	return (oldact.sa_handler);
}
