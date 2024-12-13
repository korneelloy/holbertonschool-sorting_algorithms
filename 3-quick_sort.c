#include "sort.h"


void push_on_stack(int temp)
{
	printf("%d ,", temp);
}

/**
 * swap - swap 2 elements of a list
 * @array: pointer to the array
 * @index1: 1st index to change
 * @index2: 1st index to change
 *
 * Return: void
 */

void swap(int *array, int index1, int index2)
{
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}

/**
 * quick_sort - sort array accoring to quick sort method
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return: void
 */


void quick_sort(int *array, size_t size)
{
	int pivot = size - 1, j = 0, i = 0, k, n_one, n_two;
	int *array_one, *array_two;
	int temp;

	if (size == 0)
	{
		return;
	}
	for (j = 0; j < pivot; j++)
	{
		if (array[j] <= array[pivot])
		{
			if (array[i] != array[j])
			{
				swap(array, i, j);
				print_array(array, 9);
			}
			i++;
		}
	}
	
	temp = array[pivot];

	swap(array, pivot, i);
	 
	n_one = i;
	n_two = pivot - i;
/** 
	array_one = malloc(sizeof(int)* n_one);
	array_two = malloc(sizeof(int)* n_two);

	for (k = 0; k < n_one; k++)
		array_one[k] = array[k];
	for (k = i+1; k <= pivot; k++)
		array_two[k - i - 1] = array[k];
*/	

	quick_sort(&array[0], i);

	quick_sort(&array[i + 1], pivot - i);

}
