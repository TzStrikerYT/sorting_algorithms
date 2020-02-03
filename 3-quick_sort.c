#include "sort.h"

/* PARTICION DE LA MATRIZ DONDE LOW Y HIGH SON LOS INDICES DE LOS RANGOS*/
size_t lomuto(int *array, size_t size , ssize_t low, ssize_t high)
{
	int a, b, pivot = array[high];

	for (a = b = low; b < high; b++)
		if (array[b] < pivot)
			swaper(array, size, &array[b], &array[a++]);
	swaper(array, size,  &array[a], &array[high]);
	return(a);
}
/* ejecucion de la particion en esquema lomuto */
void sorter(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t l_p = lomuto(array, size, low, high);

		sorter(array, size, low, l_p - 1);
		sorter(array, size, l_p + 1, high);
	}
}


/* INTERCAMBIA DOS VALORES ENTEROS */

void swaper(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/* LLAMA A A LA FUNCION SORTER */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	sorter(array, size, 0, size - 1);
}
