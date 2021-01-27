#include "holberton.h"

/**
 * isDash - determines if char is a '/' character
 * @c: input char
 * Return: true or false
 */
int isDash(char c)
{
	return (c == '-');
}


/**
 * count_directories - count the number of directories
 *
 * @str: array of string of ls command
 * @size: size of the array
 * Return: the number of directories to list
 */
int count_directories(char **str, int size)
{
	int i = 0, count = 0;

	for (i = 1; i < size; i++)
	{
		if (!isDash(str[i][0]))
		{
			count++;
		}
	}

	return (count);
}



/**
 * get_command_options - splits string into an array of strings
 * separated by spaces
 * @str: input string
 * @argc: number of elements of arrays of string
 * Return: array of strings
 */
char *get_command_options(char **str,  int argc)
{
	register int i = 0, j = 0;
	char *res = NULL;

	res = (char *) malloc(sizeof(char) * FLAG_SIZE);
	if (!res)
		return (NULL);
	_memset(res, 0,  sizeof(char) * FLAG_SIZE);
	_strcat(res, "-");
	for (i = 1; i < argc; i++)
	{
		if (isDash(str[i][0]))
		{
			for (j = 1; j < _strlen(str[i]); ++j)
			{
				switch (str[i][j])
				{
				case '1':
					_strcat(res, "1");
					break;
				case 'a':
					_strcat(res, "a");
					break;
				case 'A':
					_strcat(res, "A");
					break;
				case 'l':
					_strcat(res, "l");
					break;
				default:
					break;
				}
			}
		}
	}
	if (_strlen(res) == 1)
	{
		free(res);
		res = NULL;
	}
	return (res);
}



/**
 * get_command_filename - splits string into an array of strings
 * separated by spaces
 *
 * @str: input string
 * @argc: number of elements of array
 * @dirpath: pointer to the array of strings
 *
 * Return: array of strings
 */
size_t get_command_filename(char **str,  int argc, char ***dirpath)
{
	register int i = 0;
	int count = 0;
	size_t j = 0;

	count = count_directories(str, argc);
	if (count == 0)
	{
		return (0);
	}

	/* recibimos un triple puntero pero anteponemos asterisco */
	/* para que sea doble *dirpath */
	/* dirpath = "-1aAlrStR\0" 10 positions */
	*dirpath = (char **) malloc(sizeof(char *) * count);
	if (!dirpath)
		return (0);

	_memset(*dirpath, 0,  sizeof(char *) * count);

	/* i = 0 nombre del ejecutable,   */
	/* j solo cambia cuando se cumple if conditional */
	for (i = 0, j = 0; i < argc; i++)
	{
		if (!isDash(str[i][0]) && i != 0)
		{
			*(*dirpath + j) = _strdup(*(str + i));
			j++;
		}
	}

	return (j);
}
