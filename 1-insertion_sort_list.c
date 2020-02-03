#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * swaper - Swap two nodes
 * @current: Current node
 * @next: Next node to the current
 *
 * Return: Nothing
 */

void swaper(listint_t *current, listint_t *next)
{
	if (current->prev)
	{
		current->prev->next = next;
	}
	if (next->next)
	{
		next->next->prev = current;
	}
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

	while (front)
	{
		if (front->next && front->n > front->next->n)
		{
			swaper(front, front->next);
			print_list(*list);
			back = front->prev;
			while (back)
			{
				if (back->prev && back->prev->n > back->n)
				{
					swaper(back->prev, back);
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
