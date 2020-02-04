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
 * cocktail_sort_list - Sorts list using the Cocktail shaker sort algorithm
 * @list: Pointer to head of the list
 *
 * Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *check = *list;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next))
		return;
	while (tmp)
	{
		if (tmp->next && tmp->n > tmp->next->n)
		{
			list_swaper(list, tmp, tmp->next), print_list(*list);
			continue;
		}
		if (!tmp->next)
		{
			tmp = tmp->prev;
			while (tmp->prev)
			{
				if (tmp->prev && tmp->n < tmp->prev->n)
				{
					list_swaper(list, tmp->prev, tmp);
					print_list(*list);
					continue;
				}
				tmp = tmp->prev;
			}
		}
		while (check)
		{
			if (check->n > check->next->n)
			{
				check = *list;
				break;
			}
			check = check->next;
			if (!check->next)
			{
				return;
			}
		}
		tmp = tmp->next;
	}
}
