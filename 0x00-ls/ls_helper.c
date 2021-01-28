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


/**
 * get_current_directory - splits string into an array of strings
 * separated by spaces
 *
 * @dirpath: pointer to the array of strings
 *
 * Return: size of the dirpath array
 */
size_t get_current_directory(char ***dirpath)
{
	register int i = 0;

	/* recibimos un triple puntero pero anteponemos asterisco */
	/* para que sea doble *dirpath */
	/* dirpath = "." 2 positions */
	*dirpath = (char **) malloc(sizeof(char *) * _strlen(CURRENT_DIRECTORY));
	if (!dirpath)
		return (0);

	_memset(*dirpath, 0,  sizeof(char *) * _strlen(CURRENT_DIRECTORY));

	*(*dirpath + i) = _strdup(CURRENT_DIRECTORY);


	return (i + 1);
}
