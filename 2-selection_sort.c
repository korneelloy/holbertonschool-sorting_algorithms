#include "sort.h"

/**
 * selection_sort - bubble sort an array
 * @array: pointer to the array
 * @size: size of the array
 *
 * Return : void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, mini_index;
	int mini, temp;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		mini = array[i];
		mini_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (mini > array[j])
			{
				mini = array[j];
				mini_index = j;
			}
		}
		if (mini != array[i])
		{
			temp = array[i];
			array[i] = mini;
			array[mini_index] = temp;
			print_array(array, size);
		}
	}
}
