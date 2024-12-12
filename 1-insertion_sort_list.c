#include "sort.h"
#include <string.h>



/**
 * swap - swap 3rd and 2nd element of current position in the list (if 3rd is smaller)
 * @current: pointer to the current possition in the list
 *
 * Return: 1 on succes, 0 on impossibility (end of list, NULL pointers...)
 */

int swap(listint_t *current, listint_t** list)
{

	listint_t *first = NULL;
	listint_t *second = NULL;
	listint_t *third = NULL;
	listint_t *fourth = NULL;

	if (current)
	{
		third = current;
		if (current->next)
		{
			fourth = current->next;
		}
		if (current->prev)
		{
			second = current->prev;
			if (current->prev->prev)
			{
				first = current->prev->prev;
			}
		}
	}

	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;
	right->prev = left->prev;
	left->next = right->next;
	left->prev = right;
	right->next = left;
	if (!right->prev)
	*list = right;
	
	return (1);

}

 
/**
	listint_t *first = NULL;
	listint_t *second = NULL;
	listint_t *third = NULL;
	listint_t *fourth = NULL;

 left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;
	right->prev = left->prev;
	left->next = right->next;
	left->prev = right;
	right->next = left;
	if (!right->prev)
	*list = right;

	if (current)
	{
		third = current;
		if (current->next)
		{
			fourth = current->next;
		}
		if (current->prev)
		{
			second = current->prev;
			if (current->prev->prev)
			{
				first = current->prev->prev;
			}
		}
	}

	if (second == NULL || third == NULL)
		return (0);

	if (fourth == NULL)
		printf("fourth null\n");

	if (third->n < second->n)
	{
		if (current->prev->prev)
			current->prev->prev->next = third;
		if (current->next)
		{
			current->next->prev = second;
			current->next = second;
		}
		current->prev->next = fourth;
		current->prev->prev = third;
		current->prev = first;
	
		printf("in swapping\n");
		print_list(*list);


		if (first == NULL)
		{
			*list = third;
			return (0);
		}
		
		return (1);
	}
	return (0);

}
	*/


void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;
	right->prev = left->prev;
	left->next = right->next;
	left->prev = right;
	right->next = left;
	if (!right->prev)
	*list = right;
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
