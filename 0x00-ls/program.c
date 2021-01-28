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
	int is_id = 0;
	int (*option_flag)(char *dir);

	options_command = get_command_options(argv, argc);
	dirpath_size = get_command_filename(argv, argc, &dirpath);

	option_flag = (options_command == NULL) ?
		get_op_func(DEFAULT_OPTION_COMMAND) :
		get_op_func(options_command);

	if (!option_flag)
		return (EXIT_SUCCESS);

	if (!dirpath)
		dirpath_size = get_current_directory(&dirpath);

	for (i = 0; i < dirpath_size; ++i)
	{
		is_id = (isDird(dirpath[i]));
		if (dirpath_size != 1 && is_id != ERROR_FOUND)
		{
			sprintf(bufmsg, "%s:", dirpath[i]);
			puts(bufmsg); /* _putchar(FLUSH); */
		}

		option_flag(dirpath[i]);
		if (is_id != ERROR_FOUND)
			putchar('\n');
	}
	free(options_command); /* _putchar(FLUSH); */
	free_array(dirpath, dirpath_size);

	return (EXIT_SUCCESS);
}
