#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * list_swaper - Swap two nodes
 * @list: List head
 * @current: Current node
 * @next: Next node to the current
 *
 * Return: Nothing
 */

void list_swaper(listint_t **list, listint_t *current, listint_t *next)
{
	if (!list || !(*list) || !current || !next)
		return;
	if (current->prev)
		current->prev->next = next;
	if (next->next)
		next->next->prev = current;
	if (!current->prev)
		*list = next;

	current->next = next->next;
	next->prev = current->prev;
	current->prev = next;
	next->next = current;
}

/**
 * insertion_sort_list - Sorts a doubly linked using Insertion sort algorithm
 * @list: Array of doubly linked list
 *
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *front = *list, *back = NULL;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;
	while (front)
	{
		if (front->next && front->n > front->next->n)
		{
			list_swaper(list, front, front->next);
			print_list(*list);
			back = front->prev;
			while (back)
			{
				if (back->prev && back->prev->n > back->n)
				{
					list_swaper(list, back->prev, back);
					print_list(*list);
				}
				else
					break;

			}
			continue;
		}
		front = front->next;
	}
}
