#include "laps.h"


/**
 * insert_sort - adds a new node  in ascending order using the Insertion sort
 *               of a linked_l list;
 *
 * @head: reference to head of list
 * @car_number: int identified the number of car
 *
 * Return: address of new node
 */
linked_l *insert_sort(linked_l **head, int car_number)
{
	linked_l *newNode = NULL;
	linked_l *last = NULL;

	newNode = (linked_l *) malloc(sizeof(linked_l));
	if (!newNode)
	{
		perror("Malloc failed\n");
		exit(errno);
	}

	newNode->car = car_number;
	newNode->laps = 0;
	newNode->next = NULL;

	if (!*head || (*head)->car > newNode->car)
	{
		*head = newNode;
		return (newNode);
	}

	last = (*head);
	while (last->next != NULL && last->next->car < newNode->car)
		last = last->next;

	newNode->next = last->next;
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
		printf("Car %d [%d laps]\n", h->car, h->laps);
		h = h->next;
		count++;
	}

	return (count);
}


/**
 * update_list - returns the number of elements in a linked list
 * @h: head of linked list
 * @number_car: number of car of the race
 * Return: number of elements in list_t
 */
size_t update_list(linked_l *h, int number_car)
{
	register unsigned int count = 0;

	while (h)
	{
		if (h->car == number_car)
			h->laps += 1;

		h = h->next;
		count++;
	}
	return (count);
}



/**
 * freeList - frees a linked list
 * @head: double pointer to head of list
 */
void freeList(linked_l *head)
{
	linked_l *current = NULL;
	linked_l *tmp = NULL;

	if (!head)
		return;

	current = head;
	while (current)
	{
		tmp = current;
		current = tmp->next;
		free(tmp);
	}
	head = NULL;
}


/**
 * race_state - keeps track of the number of laps made by several cars in race
 *
 * @id: array of intergers represent the identifier of each car
 * @size: is the size of the array
 */
void race_state(int *id, size_t size)
{
	unsigned int i = 0;
	int check = 0, number_of_car_insert = 0;
	linked_l *tmp = NULL;
	static linked_l *cars_list;

	if (id == NULL || size == 0)
	{
		freeList(cars_list);
		return;
	}
	if (cars_list == NULL)
	{
		for (i = 0; i < size; ++i)
		{
			insert_sort(&cars_list, *(id + i));
			printf("Car %d joined the race\n", *(id + i));
		}
		printf("Race state:\n");
		printList(cars_list);
		return;
	}
	for (i = 0; i < size; ++i)
	{
		for (check = 0, tmp = cars_list; tmp; tmp = tmp->next)
		{
			if (tmp->car == *(id + i))
				check = 1;
		}
		if (!check)
		{
			insert_sort(&cars_list, *(id + i));
			printf("Car %d joined the race\n", *(id + i));
			number_of_car_insert++;
		}
	}
	printf("Race state:\n");
	if (number_of_car_insert == 0)
		for (i = 0; i < size; ++i)
			update_list(cars_list, *(id + i));
	printList(cars_list);
}
