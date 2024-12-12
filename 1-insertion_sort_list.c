#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using the insertion sort.
 * @list: A pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
	return;

	listint_t *current = (*list)->next;

	while (current)
	{
		sort_node(list, current);
		current = current->next;
	}
}
/**
 * sort_node - Sorts a specific node in the list.
 * @list: A pointer to the head of the list.
 * @node: The current node to sort.
 */
void sort_node(listint_t **list, listint_t *node)
{
	listint_t *temp = node;

	while (temp->prev && temp->n < temp->prev->n)
	{
		swap_nodes(list, temp);
		print_list(*list);
	}
}
/**
 * swap_nodes - Swaps two adjacent nodes in the doubly linked list.
 * @list: A pointer to the head of the list.
 * @node: The node to swap.
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev = node->prev;

	if (prev->prev)
	prev->prev->next = node;
	node->prev = prev->prev;
	prev->next = node->next;

	if (node->next)
	node->next->prev = prev;
	node->next = prev;
	prev->prev = node;

	if (!node->prev)
	*list = node;
}
