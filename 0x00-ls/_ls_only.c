#include "holberton.h"

/**
 * errMsg - show an error
 *
 * @err: err of errno
 * @dirpath: name of the directory
 * Return: nothing
 */
void errMsg(int err, char *dirpath)
{
	char buffer[KILOBYTE] = {0};

	if (err == ENOENT)
		sprintf(buffer, "./hls: cannot access %s", dirpath);
	else if (err == EACCES)
		sprintf(buffer, "./hls: cannot open directory %s", dirpath);
	perror(buffer);
}

/**
 * save_name - create a list of files and directories
 *
 * @sb: stat info
 * @entry: directory
 * @files: list of files
 * @directories: list fo directories
 * Return: nothing
 */
void save_name(const struct stat *sb, struct dirent **entry,
	  linked_l **files, linked_l **directories)
{
	switch (sb->st_mode & S_IFMT)
	{
	case S_IFREG:
		addNode(*(&files), (*entry)->d_name);
		break;
	case S_IFDIR:
		addNode(*(&directories), (*entry)->d_name);
		break;
	default:
		break;
	}
}

/**
 * check_hidden_files - determinates if there is a hidden file
 *
 * @entry: name of filename
 * Return: 1 if it found a dot into filename
 */
int check_hidden_files(struct dirent **entry)
{
	int i = 0;

	if (_strcmp((*entry)->d_name, ".") == 0 ||
	    _strcmp((*entry)->d_name, "..") == 0)
		return (1);

	/* 46 is . (dot askii)   start in dot or dot and something more */
	if ((*entry)->d_name[i] == 46 && (*entry)->d_name[i + 1] == 46)
		return (1);

	if ((*entry)->d_name[i] == 46 && (*entry)->d_name[i + 1] != 46)
		return (1);

	return (0);
}

/**
 * _ls_only - print list the content of the current directory
 *
 * @dirpath: name of the current directory
 * Return: the number of files + directories scanne
 */
int _ls_only(char *dirpath)
{
	DIR *dir = NULL;
	int count = 0;
	struct dirent *entry = NULL;
	struct stat sb;
	char filename[KILOBYTE] = {0};
	linked_l *files = NULL, *directories = NULL;

	dir = opendir(dirpath);
	if (!dir)
	{
		errMsg(errno, dirpath);
		return (0);
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
		save_name(&sb, &entry, &files, &directories);
	}
	printList(files);
	printList(directories);
	freeList(files);
	freeList(directories);

	if (errno && !entry)
		perror("readdir");
	if (closedir(dir) == -1)
		perror("closedir");
	return (count);
}
