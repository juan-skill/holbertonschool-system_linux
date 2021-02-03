#include "_getline.h"


/**
 * _memset - fills the first n bytes of the memory area
 *               pointed to by @arr with the constant byte @c
 *
 * @arr: a pointer to the memory area to be filled
 * @c: the character to fill the memory area
 * @size: the number of bytes to be filled
 * Return: void
 */
void *_memset(void *arr, char c, size_t size)
{
	unsigned int index = 0;
	char *memory = arr, value = c;

	for (index = 0; index < size; index++)
		*(memory + index) = value;

	return (memory);
}


/**
 * _getline - reads an entire line from a file descriptor
 *
 * @fd: file descriptor to read from
 *
 * Return: returns the line, null-terminated string, otherwise NULL
 */
char *_getline(const int fd)
{
	ssize_t num_read = 0;
	char buff[READ_SIZE], *read_line = NULL;
	int i = 0;

	read_line = (char *) malloc(sizeof(char) * (READ_SIZE + 1));
	if (!read_line)
		return (NULL);

	_memset(read_line, '\0', sizeof(char) * (READ_SIZE + 1));

	while ((num_read = read(fd, buff, BUFF_SIZE)))
	{
		if (buff[0] != '\n' && buff[0] != 12)
		{
			*(read_line + i) = buff[0], i++;
		}
		else
		{
			*(read_line + i) = '\0';
			break;
		}
	}

	if (num_read == -1 || num_read == 0)
	{
		free(read_line);
		return (NULL);
	}

	return (read_line);
}
