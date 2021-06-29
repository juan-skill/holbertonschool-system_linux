#include "multithreading.h"


/**
 * thread_entry - it will serve as the entry point to a new thread
 *
 * @arg: holds the address of a string that must be printed
 *
 * Return: nothing
 */
void *thread_entry(void *arg)
{
	printf("%s\n", (char *)arg);
	pthread_exit(NULL);
}
