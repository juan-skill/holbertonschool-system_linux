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
 * free_listint - frees a listint_t list
 * @head: pointer to list to be freed
 * Return: void
 */
void free_listint(linkedfd_t *head)
{
	linkedfd_t *node = NULL, *tmp = NULL;

	tmp = head;
	while (tmp != NULL)
	{
		node = tmp;
		tmp = tmp->next;
		free(node);
	}
}


/**
 * replace_other_char - set the characters the corresponding
 * to null-char string
 *
 * @str: string to replace a character to another
 * @len: size of the string
 * @null: character to replace
 * @nonull: charater replaced
 *
 * Return: void
 */
void replace_other_char(char *str, size_t len, char null, char nonull)
{
	size_t i = 0;

	for (i = 0; i < len; ++i)
	{
		if (*(str + i) == null)
			*(str + i) = nonull;
	}
}


/**
 * addnodefd - adding a node into a singly liked list for fd.
 *
 * @fd: The file descriptor
 * Return: A pointer to a node from listfd_s or NULL if failure.
 */
linkedfd_t *addnodefd(int fd)
{
	static linkedfd_t *head;
	linkedfd_t *node = NULL, *tmp = NULL, *prev = NULL;

	if (fd == -1)
	{
		tmp = head;
		free_listint(tmp);
		head = NULL;
		return (NULL);
	}

	node = (linkedfd_t *) malloc(sizeof(linkedfd_t));
	if (node == NULL)
		return (NULL);

	node->fd = fd, node->buffer_static[0] = '\0'; /* set all array */
	node->next = NULL;
	if (head == NULL)
		head = node;
	else
	{
		tmp = head;
		while (tmp != NULL)
		{
			if (tmp->fd != fd)
			{
				prev = tmp;
				tmp = tmp->next;
			}
			else
				break;
		}
		if (tmp != NULL)
		{	free(node);
			return (tmp);
		}
		prev->next = node;
	}
	return (node);
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
	char *buffer_static = NULL;
	linkedfd_t *node = NULL;

	while ((node = addnodefd(fd)) == NULL)
		return (NULL);
	buffer_static = node->buffer_static;
	read_line = (char *) malloc(sizeof(char) * (BUFF_STAT + 1));
	if (!read_line)
		return (NULL);
	memset(read_line, NULL_CHAR, sizeof(char) * (BUFF_STAT + 1));
	strcpy(read_line, buffer_static);
	memset(buffer_static, NULL_CHAR, sizeof(char) * (BUFF_STAT));
	new_line = _strchr(read_line, 10);
	if (new_line != NULL)
	{	new_line[0] = NULL_CHAR, new_line++;
		strcpy(buffer_static, new_line);
		return (read_line);
	}
	i = _strlen(read_line);
	while ((num_read = read(fd, buff_read, READ_SIZE)))
	{
		buff_read[num_read] = NULL_CHAR;
		replace_other_char(buff_read, num_read, NULL_CHAR, OTHER_CHAR);
		new_line = _strchr(buff_read, 10);
		if (new_line == NULL)
			strcpy((read_line + i), buff_read), i = i + num_read;
		else
		{	new_line[0] = NULL_CHAR, new_line++;
			strcpy((read_line + i), buff_read), strcpy(buffer_static, new_line);
			break;
		}
	}
	if ((num_read == -1 || num_read == 0) && _strlen(read_line) == 0)
	{	free(read_line);
		return (NULL);
	}
	replace_other_char(read_line, _strlen(read_line), OTHER_CHAR, NULL_CHAR);
	return (read_line);
}
