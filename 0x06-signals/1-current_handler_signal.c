#include "signals.h"

/**
 * current_handler_signal - retrieves the current handler of the
 * signal SIGINT
 *
 * Return: A pointer to the current handler, otherwise NULL (failure)
 */
void (*current_handler_signal(void))(int)
{
	void (*handler)(int) = NULL;

	handler = signal(SIGINT, NULL);
	signal(SIGINT, handler);

	return (handler);
}
