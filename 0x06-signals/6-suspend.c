#include "signals.h"

void print_msg(int signal);

/**
* main - wait until the signal sigint be executed
*
* Return: 0 on success
*/
int main(void)
{
	struct sigaction act;

	/* Set up the structure to specify the new action. */
	memset(&act, '\0', sizeof(act));
	act.sa_handler = print_msg;
	act.sa_flags = SA_SIGINFO;

	sigaction(SIGINT, &act, NULL);
	pause();
	printf("Signal received\n");

	return (EXIT_SUCCESS);
}

/**
* print_msg - print a message
*
* @signal: The signal code to print
*
* Return: nothing
*/
void print_msg(int signal)
{
	printf("Caught %d\n", signal);
}
