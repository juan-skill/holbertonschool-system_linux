#include "multithreading.h"

void mutex_init(void) __attribute__((constructor));
void mutex_destroy(void) __attribute__((destructor));

static pthread_mutex_t mtx;


/**
 * errExitEN - print message error and exit program
 * @message: data to print
 */
void errExitEN(char *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

/**
 * mutex_init - initializes a mutex lock
 */
void mutex_init(void)
{
	int s = pthread_mutex_init(&mtx, NULL);

	if (s != 0)
		errExitEN("Mutex init failed");
}

/**
 * mutex_destroy - destroys a mutex lock
 */
void mutex_destroy(void)
{
	int s = pthread_mutex_destroy(&mtx);

	if (s != 0)
		errExitEN("Mutex destroy failed");
}

/**
 * tprintf - uses printf family to print out given formatted string
 * @format: string to print
 * Return: EXIT_SUCCESS
 */
int tprintf(char const *format, ...)
{
	va_list arguments;
	int s = 0;

	va_start(arguments, format);


	s = pthread_mutex_lock(&mtx);
	if (s != 0)
		errExitEN("Mutex Lock Failed\n");


	printf("[%lu] ", pthread_self());
	vprintf(format, arguments);


	s = pthread_mutex_unlock(&mtx);
	if (s != 0)
		errExitEN("Mutex unlock Failed\n");

	va_end(arguments);
	return (EXIT_SUCCESS);
}
