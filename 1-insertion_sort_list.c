#include "sort.h"
/**
 * insertion_sort_list - sort doubly linked list by insertion sort
 * @list: double pointer to doubly linked list
 *
 * Return:void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;

	int swapping = 0;

	current = *(list);

	if (list == NULL)
	{
	return;
	}

	while (current->next != NULL)
	{
	if (current->n > current->next->n)
	{
	swapping = 1;
	while (swapping == 1)
	{
	printf("current next si plus petit %d\n", current->next->n);
	swapping = swap(current, list);
	printf("current = %d\n", current->n);
	print_list(*list);
	}
	}
	current = current->next;
	}
}
