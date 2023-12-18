#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a linked list
 * @node1: first node to swap
 * @node2: second node to swap
 * Return: NONE
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	listint_t *tmp1, *tmp2;

	tmp2 = node2->prev;
	tmp1 = node1->prev;

	node1->prev = tmp2;
	tmp2->next = node1;
	node2->prev = tmp1;

	if (tmp1 != NULL)
		tmp1->next = node2;

	tmp1 = node1->next;
	tmp2 = node2->next;

	tmp1->prev = node2;
	node2->next = tmp1;

	node1->next = tmp2;
	if (tmp2 != NULL)
		tmp2->prev = node1;
}


/**
 * insertion_sort_list - Sorts an list of integers in ascending order
 * @list: The list to be printed
 * Return: NONE
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL)
		return;

	current = *list;
	while (current != NULL)
	{
		tmp = current;
		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			swap_nodes(tmp->prev, tmp);
			if (tmp->prev == NULL)
				*list = tmp;
			print_list(*list);
		}
		current = current->next;
	}
}
