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

	if (second == NULL || third == NULL)
		return (0);

	if (fourth = NULL)
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


/**
 * insertion_sort_list - sort doubly linked list by insertion sort
 * @list: double pointer to doubly linked list
 *
 * Return:void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *this_cycle = NULL;
	int swapping = 0;

	if ((*list)->next)
		current = (*list)->next;

	while (current != NULL)
	{
		this_cycle = current;
	
		if (current->n >= current->prev->n)
		{
			current = current->next;
		}
		else
		{
			swapping = 1;
			while (swapping == 1)
			{
				print_list(*list);
				printf("swapping\n");
				printf("current %d\n", current->n);
				if (current->prev)
					printf("current prev %d\n", current->prev->n);
				
				print_list(*list);		
				printf("before swapping\n");
		
				swapping = swap(current, list);
				printf("after swapping\n");
				
				print_list(*list);
				if (current->next)
					printf("a la fin: %d\n", current->next->n);
			}
		current = current->next;
		}
	}	
}
