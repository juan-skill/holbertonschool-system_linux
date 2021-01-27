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
				if (i == 1 && dirpath_size > 1)
					putchar('\n');

				if (dirpath_size != 1)
				{
					sprintf(bufmsg, "%s:", dirpath[i]);
					puts(bufmsg); /* _putchar(FLUSH); */
				}

				if (_ls_only(dirpath[i])) /* num of files and dir */
					putchar('\n');
			}
			free(options_command); /* _putchar(FLUSH); */
			free_array(dirpath, dirpath_size);
		}
	}

	return (EXIT_SUCCESS);
}
