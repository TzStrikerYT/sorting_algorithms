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
 * find_forward - Sort node forward
 * @list: Doubly linked list
 * @head: Pointer to list head
 *
 * Return: Nothing
 */

listint_t *find_forward(listint_t **head, listint_t *list)
{
	while (list->next)
	{
		if (list->next && list->n > list->next->n)
		{
			list_swaper(head, list, list->next);
			print_list(*head);
			continue;
		}
		list = list->next;
	}
	return (list);
}

/**
 * find_back - Sort node back
 * @list: Doubly linked list
 * @head: Pointer to list head
 *
 * Return: Nothing
 */

listint_t *find_back(listint_t **head, listint_t *list)
{
	while (list->prev)
	{
		if (list->prev && list->n < list->prev->n)
		{
			list_swaper(head, list->prev, list);
			print_list(*head);
			continue;
		}
		list = list->prev;
	}
	return (list);
}

/**
 * list_checker - Check if a doubly linked list is sort
 * @list: Doubly linked list
 *
 * Return: Nothing
 */

int list_checker(listint_t **list)
{
	listint_t *check = *list;

	while (check->next)
	{
		if (check->n > check->next->n)
		{
			return (0);
		}
		check = check->next;
	}
	return (1);
}

/**
 * cocktail_sort_list - Sorts list using the Cocktail shaker sort algorithm
 * @list: Pointer to head of the list
 *
 * Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp = *list;
	int check = 0;

	if (!list || !(*list))
	{
		return;
	}
	while (!check)
	{
		if (!tmp->prev)
		{
			tmp = find_forward(list, tmp);
		}
		if (!tmp->next)
		{
			tmp = find_back(list, tmp);
		}
		check = list_checker(list);
		if (check)
		{
			break;
		}
	}
}
