#include "sort.h"
#include <stdlib.h>
/**
 * insertion_sort_list - Sorts a doubly linked list using the insertion sort.
 * @list: A pointer to the head of the list.
 *
 * The function swaps the nodes and prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;

listint_t *current;
listint_t *temp;
listint_t *swap;
current = (*list)->next;

while (current)
{
	temp = current;
	while (temp->prev && temp->n < temp->prev->n)
	{
	swap = temp->prev;
	if (swap->prev)
	swap->prev->next = temp;
	temp->prev = swap->prev;
	swap->next = temp->next;
	if (temp->next)
	temp->next->prev = swap;
	temp->next = swap;
	swap->prev = temp;
	if (!temp->prev)
	*list = temp;
	print_list(*list);
	}
	current = current->next;
}
}
