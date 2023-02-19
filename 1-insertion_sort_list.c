#include "sort.h"
/**
 * insertion_sort_list - sorts DLL of integers (ascending)
 * by Insertion sort algorithm
 * @list: double pointer to the head of DLL
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node != NULL)
	{
		tmp = node->next;

		while (node->prev && node->n < node->prev->n)
		{
			node->prev->next = node->next;

			if (node->next != NULL)
				node->next->prev = node->prev;

			node->next = node->prev;
			node->prev = node->next->prev;

			if (node->prev != NULL)
				node->prev->next = node;
			else
				*list = node;

			node->next->prev = node;
			print_list(*list);
		}
		node = tmp;
	}
}
