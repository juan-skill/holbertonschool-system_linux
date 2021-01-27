#include "holberton.h"


/**
 * main - Entry point
 *
 * @argv: array of string of arguments
 * @argc: number of elements of array
 *
 * Return: Always (0)
 */
int main(int argc, char *argv[])
{
	char *options_command = NULL;
	char **dirpath = NULL;
	char bufmsg[KILOBYTE] = {0};
	size_t dirpath_size = 0, i = 0;

	if (argc == 1) /* No arguments - use current directory */
		_ls_only(".");
	else
	{
		options_command = get_command_options(argv, argc);
		dirpath_size = get_command_filename(argv, argc, &dirpath);

		if (options_command == NULL)
		{
			for (i = 0; i < dirpath_size; ++i)
			{
				if (i == 1)
					_putchar('\n');

				if (dirpath_size != 1)
				{
					sprintf(bufmsg, "%s:\n", dirpath[i]);
					_puts(bufmsg);
					_putchar(FLUSH);
				}

				_ls_only(dirpath[i]);

				_putchar('\n');
			}
			_putchar(FLUSH);
			free(options_command);
			free_array(dirpath, dirpath_size);
		}

	}

	return (EXIT_SUCCESS);
}
