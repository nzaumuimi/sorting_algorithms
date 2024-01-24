#include "sort.h"

/**
 * exchange_nodes - Exchange two nodes in doubly-linked list of type listint_t.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to be swapped.
 * @n2: The second node to be swapped.
 */
void exchange_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Applies the insertion sort algorithm to sort a
 * doubly linked list of integers.
 * @list: A pointer to the head of the doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			exchange_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
