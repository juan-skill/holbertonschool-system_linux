#include "holberton.h"

/**
 * _ls_only - print list the content of the current directory
 *
 * @dirpath: name of the current directory
 * Return: nothing
 */
void _ls_only(char *dirpath)
{
	DIR *dir = NULL;
	struct dirent *entry = NULL;
	struct stat sb;
	char buffer[KILOBYTE] = {0}, filename[KILOBYTE] = {0};
	linked_l *files = NULL, *directories = NULL;

	dir = opendir(dirpath);
	if (!dir)
	{
		if (errno == ENOENT)
			sprintf(buffer, "./hls: cannot access %s", dirpath);
		else
			sprintf(buffer, "./hls: cannot open directory %s", dirpath);
		perror(buffer);
		return;
	}

	for (;;)
	{
		errno = 0;
		entry = readdir(dir);
		if (!entry)
			break;

		sprintf(filename, "%s/%s", dirpath, entry->d_name);
		if (lstat(filename, &sb) == -1)
			perror("lstat ");

		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue; /* Skip . and .. */

		switch (sb.st_mode & S_IFMT)
		{
		case S_IFREG:
			addNode(&files, entry->d_name);
			break;
		case S_IFDIR:
			addNode(&directories, entry->d_name);
			break;
		default:
			_puts("unknown file type?\n");
			break;
		}
	}

	printList(files);
	printList(directories);
	_putchar('\n');
	_putchar(FLUSH);

	freeList(files);
	freeList(directories);

	if (errno && !entry)
		perror("readdir");

	if (closedir(dir) == -1)
		perror("closedir");
}
