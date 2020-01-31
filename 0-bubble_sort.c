#include "sort.h"

/**
 * bubble_sort - sorts a array of numbers with a bubble sort algorithm
 * @array: array of ints
 * @size: len of array
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, position;

	if (!size || !array)
		return;

	i = 0;

	while (i < size)
	{
		for (position = 0; position < size - 1; position++)
		{
			if (array[position] > array[position + 1])
			{
				tmp = array[position];
				array[position] = array[position + 1];
				array[position + 1] = tmp;
				print_array(array, size);
			}
		}
		i++;
	}
}
