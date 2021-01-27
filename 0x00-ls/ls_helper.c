#include "holberton.h"

/**
 * free_array - frees memory area
 *
 * @s: array of string to free
 * @size: size of the array
 * Return: nothing
 */
void free_array(char **s, size_t size)
{
	size_t i = 0;

	for (i = 0; i < size; ++i)
		if (s[i] != NULL)
		{
			free(*(s + i));
			(*(s + i)) = NULL;
		}
	free(s);
	s = NULL;
}


/**
 * print_array - prints the array of string
 *
 * @argv: array of string to print
 * Return: void
 */
void print_array(char **argv)
{
	char **ptr = NULL;

	ptr = argv;
	while (*ptr != NULL)
	{
		puts(*ptr);
		putchar(' ');
		putchar('\n');

		ptr++;
	}

	/* _putchar('\n'); */
	/* _putchar(FLUSH); */
}
