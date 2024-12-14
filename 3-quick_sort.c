#include "sort.h"

/**
 * swap - swap 2 elements of a list
 * @array: pointer to the array
 * @index1: 1st index to change
 * @index2: 1st index to change
 * @or_array: pointer to the original array
 * @or_size: size of the original array
 * (versus the array used in recursive calls)
 *
 * Return: void
 */

void swap(int *array, int index1, int index2, int *or_array, size_t or_size)
{
	int temp = array[index1];

	if (array[index1] != array[index2])
	{
		array[index1] = array[index2];
		array[index2] = temp;
		print_array(or_array, or_size);
	}
}

/**
 * quick_sort_rec - sort array accoring to quick sort method
 * @array: pointer to the array
 * @size: size of the array
 * @or_array: pointer to the original array
 * @or_size: size of the original array
 * (versus the array used in recursive calls)
 *
 * Return: void
 */


void quick_sort_rec(int *array, size_t size, int *or_array, size_t or_size)
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
				swap(array, i, j, or_array, or_size);
			}
			i++;
		}
	}
	swap(array, pivot, i, or_array, or_size);
	quick_sort_rec(&array[0], i, or_array, or_size);
	quick_sort_rec(&array[i + 1], pivot - i, or_array, or_size);
}

/**
 * quick_sort - launches quick_sort_recursion method
 * adding 2 parameters to original main call, so we can print allong the way
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return: void
 */


void quick_sort(int *array, size_t size)
{
	int *original_array = array;
	size_t original_size = size;

	quick_sort_rec(array, size, original_array, original_size);
}
