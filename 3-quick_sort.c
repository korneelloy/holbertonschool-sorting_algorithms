#include "sort.h"

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
	int pivot = size - 1, j = 0, i = 0;

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
	swap(array, pivot, i);
	quick_sort(&array[0], i);
	quick_sort(&array[i + 1], pivot - i);
}
