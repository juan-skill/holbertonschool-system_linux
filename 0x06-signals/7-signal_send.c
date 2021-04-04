#include "signals.h"

/**
* main - sends the signal SIGINT to a process, given its PID
*
* @argc: number of arguments
* @argv: pointer to the array of arguments
*
* Return: EXIT_SUCCESS on success, or EXIT_FAILURE
*/
int main(int argc, char **argv)
{
	int pid = 0;

	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	pid = atoi(argv[1]);

	if (kill(pid, SIGINT))
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
