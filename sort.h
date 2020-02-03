#ifndef STRUCT
#define STRUCT

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

#endif /* STRUCT */

#ifndef HEADERS
#define HEADERS

#include <stdlib.h>
#include <stdio.h>

#endif /* HEADERS */

#ifndef PROTOTYPES
#define PROTOTYPES

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swaper(int *array, size_t size, int *a, int *b);
void quick_sort(int *array, size_t size);
/*size_t lomuto(int *array, size_t size , size_t low, size_t high);*/
/*void sorter(int *array, size_t size, size_t low, size_t high);*/

#endif /* PROTOTYPES */
