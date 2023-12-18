#include "sort.h"

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
