#include "_getline.h"

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
 * _strcat - concatenates two strings
 * @dest: copy destination
 * @src: copy source
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be copied
 * Return: copied string
 */
char *_strdup(char *str)
{
	int i, len;
	char *copy;

	if (!str)
		return (NULL);
	len = _strlen(str);
	copy = malloc(sizeof(char) * len + 1);
	if (!copy)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	_memset(copy, '\0', len + 1);
	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[i] = 0;
	return (copy);
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
	*dest = 0;
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
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[READ_SIZE];
	char *str = NULL;

	while (t2 == 0 && (i = read(fd, buff, READ_SIZE - 1)))
	{
		if (i == -1 || i == 0)
			return (NULL);

		buff[i] = '\0';

		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		if (t == 0)
		{
			i++;
			str = _strdup(buff);
			size = i;
			t = 1;
		}
		else
		{
			size += i;
			str = _strcat(str, buff);
		}
	}

	return (str);
}
