#include "sort.h"

/**
 * selection_sort - Sorts an array of integers using Selection sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t a, b, c;
	int tmp;

	if (!array || !size)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = size - 1, c = a + 1; b > a; b--)
		{
			if (array[b] < array[c])
				c = b;
		}
		if (array[a] > array[c])
		{
			tmp = array[a];
			array[a] = array[c];
			array[c] = tmp;
			print_array(array, size);
		}
	}
}
