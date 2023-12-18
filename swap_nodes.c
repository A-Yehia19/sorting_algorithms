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