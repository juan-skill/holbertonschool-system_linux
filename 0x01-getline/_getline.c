#include "_getline.h"

/**
 * _strchr - Returns a pointer to the first occurence of c char in string s.
 * @s: The string
 * @c: The char
 * Return: A pointer to the position or NULL
 */
char *_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}

	return (NULL);
}


/**
 * _strlen - returns the length of a string
 * @s: string s
 * Return: length of string
 */
int _strlen(char *s)
{
	char *p = s;

	while (*s)
		s++;
	return (s - p);
}


/**
 * *_strcpy - copies the string pointed to by src,
 * including the terminating null byte
 * @dest: copied string
 * @src: string to be copied
 * Return: pointer to new copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return (ptr);
}


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
	ssize_t num_read = 0, i = 0;
	char buff_read[READ_SIZE + 1], *read_line = NULL, *new_line = NULL;
	static char buffer_static[BUFF_STAT];

	read_line = (char *) malloc(sizeof(char) * (BUFF_STAT + 1));
	if (!read_line)
		return (NULL);
	_memset(read_line, '\0', sizeof(char) * (BUFF_STAT + 1));
	_strcpy(read_line, buffer_static);
	_memset(buffer_static, '\0', sizeof(char) * (BUFF_STAT));

	new_line = _strchr(read_line, 10);
	if (new_line != NULL)
	{
		new_line[0] = '\0', new_line++;
		_strcpy(buffer_static, new_line);
		return (read_line);
	}
	i = _strlen(read_line);
	while ((num_read = read(fd, buff_read, READ_SIZE)))
	{
		buff_read[num_read] = '\0';
		new_line = _strchr(buff_read, 10);
		if (new_line == NULL)
			_strcpy((read_line + i), buff_read), i = i + num_read;
		else
		{
			new_line[0] = '\0', new_line++;
			_strcpy((read_line + i), buff_read);
			_strcpy(buffer_static, new_line);
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
