#include "holberton.h"

/**
 * _memset - fills memory with a constant byte
 *
 * @s: memory area to fill
 * @b: constant byte to fill the memory area
 * @n: n bytes of the memory area pointed to by s
 * Return: pointer to the memory area
 */
void *_memset(void *s, int b, unsigned int n)
{
	unsigned int i = 0;

	for (i = 0; i < n; i++)
	{
		((char *) s)[i] = b;
	}

	return (s);
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
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if true, 0 if false
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
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

	copy = (char *) malloc(sizeof(char) * len + 1);
	if (!copy)
		return (NULL);

	_memset(copy, 0, sizeof(char) * (len + 1));

	for (i = 0; i < len; i++)
		copy[i] = str[i];

	copy[i] = 0;

	return (copy);
}
