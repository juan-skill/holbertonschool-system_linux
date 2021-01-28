#include "holberton.h"


/**
 * save_name_l - create a list of files and directories
 *
 * @sb: stat info
 * @entry: directory
 * @files: list of files
 * @directories: list fo directories
 * Return: nothing
 */
void save_name_l(const struct stat *sb, struct dirent **entry,
	  linked_l **files, linked_l **directories)
{
	(void) files;
	(void) directories;
	switch (sb->st_mode & S_IFMT)
	{
	case S_IFREG:
		/* addNode(*(&files), (*entry)->d_name); */
		printf("%s", (*entry)->d_name);
		break;
	case S_IFDIR:
		printf("%s", (*entry)->d_name);
		/* addNode(*(&directories), (*entry)->d_name); */
		break;
	default:
		break;
	}
	putchar('\n');
}

/**
 * _ls_minus_one - print list the content of the current directory
 *
 * @dirpath: name of the current directory
 * Return: the number of files + directories scanne
 */
int _ls_minus_one(char *dirpath)
{
	DIR *dir = NULL;
	int count = 0;
	struct dirent *entry = NULL;
	struct stat sb;
	char filename[KILOBYTE] = {0};
	linked_l *files = NULL, *directories = NULL;

	dir = opendir(dirpath);
	if (!dir)  /* if there is an error return -1 and then print dirname */
	{
		return (errMsg(errno, dirpath));
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

		if (check_hidden_files(&entry))
			continue; /* Skip . and .. */
		count++;
		save_name_l(&sb, &entry, &files, &directories);
	}
	/* printList(files); */
	/* files != NULL ? putchar(' ') : 1; */
	/* printList(directories); */
	/* freeList(files); */
	/* freeList(directories); */

	if (errno && !entry)
		perror("readdir");
	if (closedir(dir) == -1)
		perror("closedir");
	return (count);
}
