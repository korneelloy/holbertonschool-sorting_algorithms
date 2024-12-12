#include "sort.h"
#include <string.h>


void switching(listint_t *valeur, listint_t *previous)
{
	listint_t *temp2 = NULL;

	temp2 = previous;
	previous = valeur;
	valeur = temp2;

}

/**
 * insertion_sort_list - sort doubly linked list by insertion sort
 * @list: double pointer to doubly linked list
 *
 * Return:void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *temp = NULL;

	current = *(list);

	if (list == NULL)
	{
		return;
	}

	while (current->next != NULL)
	{
		if (current->n > current->next->n)
		{
			printf("current next si plus petit %d\n", current->next->n);
			temp = current;
			switching(temp, current->prev);
			
		}
		current = current->next;
	}
	print_list(*list);

}
