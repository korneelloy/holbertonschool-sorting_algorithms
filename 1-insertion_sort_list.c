#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order by rearranging nodes in place.
 *
 * @list: Pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;
	listint_t *prev;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
	prev = current->prev;
	while (prev && current->n < prev->n)
	{
	temp = current->next;
	if (prev->prev)
	prev->prev->next = current;
	current->prev = prev->prev;

	prev->next = temp;
	if (temp)
	temp->prev = prev;

	current->next = prev;
	prev->prev = current;

	if (!current->prev)
	*list = current;

	print_list(*list);

	prev = current->prev;
	}
current = current->next;
	}
}
