#include "holberton.h"

/**
 * addNode - adds a new node at the beginning of a linked_l list
 * @head: reference to head of linked list
 * @str: string to be added on new node
 * Return: address of new head;
 */
linked_l *addNode(linked_l **head, char *str)
{
	linked_l *newNode;
	char *newStr;

	if (!str)
		return (NULL);
	newNode = malloc(sizeof(linked_l));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newNode->string = newStr;
	newNode->next = *head;
	*head = newNode;
	return (*head);
}

/**
 * addNodeEnd - adds a new node at the end of a linked_l list;
 * @head: reference to head of list
 * @str: string to be added to linked list
 * Return: address of new node
 */
linked_l *addNodeEnd(linked_l **head, char *str)
{
	linked_l *newNode;
	linked_l *last = *head;
	char *newStr;

	if (!str)
		return (NULL);
	newNode = malloc(sizeof(linked_l));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	newStr = _strdup(str);
	if (!newStr)
	{
		free(newNode);
		perror("Malloc failed\n");
		exit(errno);
	}
	newNode->string = newStr;
	newNode->len = _strlen(str);
	newNode->next = NULL;
	if (!*head)
	{
		*head = newNode;
		return (newNode);
	}
	while (last->next)
		last = last->next;
	last->next = newNode;
	return (last);
}

/**
 * printList - prints all elements of a linked_l list
 * @h: pointer to head of list
 * Return: number of elements
 */
size_t printList(const linked_l *h)
{
	register int count = 0;

	while (h)
	{
		/* _puts(h->string); */
		/* _putchar(' '); */
		printf("%s", h->string);
		if (h->next != NULL)
			putchar(' ');
		h = h->next;
		count++;
	}
	/* _putchar(FLUSH); */

	return (count);
}


/**
 * freeList - frees a linked list
 * @head: double pointer to head of list
 */
void freeList(linked_l *head)
{
	linked_l *current;
	linked_l *tmp;

	if (!head)
		return;
	current = head;
	while (current)
	{
		tmp = current;
		current = tmp->next;
		free(tmp->string);
		free(tmp);
	}
	head = NULL;
}
