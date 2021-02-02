#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


/**
 * struct linkedList - linked list data structure
 *
 * @car: the number of car
 * @laps: the number of laps of a car
 * @next: pointer to next node
 */
typedef struct linkedList
{
	int car;
	int laps;
	struct linkedList *next;
} linked_l;


void race_state(int *d, size_t size);


/* linked list */
linked_l *insert_sort(linked_l **head, int car_number);
size_t update_list(linked_l *h, int number_car);
int check_car(linked_l *h, int number_car);
void freeList(linked_l *head);
size_t printList(const linked_l *h);

#endif


