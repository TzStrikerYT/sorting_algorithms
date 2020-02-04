#include "sort.h"

/**
 * shell_sort - sort array of integers whit shell sort algorithm
 * @array: the integer array to sort
 * @size: len of array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, a, b;
	int tmp;

	if (!array || !size)
		return;

	for (gap = maxgap(size); gap; gap = (gap - 1) / 3)
	{
		for (a = gap; a < size; a++)
		{
			tmp = array[a];
			for (b = a; b > gap - 1 && array[b - gap] > tmp;
			     b -= gap)
				array[b] = array[b - gap];

			array[b] = tmp;
		}
		print_array(array, size);
	}
}

/**
 * maxgap - knuth sequence gap for this size
 * @size: len of array
 * Return: gap size
 */

size_t maxgap(size_t size)
{
	size_t n = 1;

	while (n < size)
		n = n * 3 + 1;
	return ((n - 1) / 3);
}
