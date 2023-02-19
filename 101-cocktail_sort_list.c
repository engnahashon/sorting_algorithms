#include "sort.h"
/**
 * swap_next - swaps forwards
 * @node: node to swap
 * @list: double pointer to the head of the list
 */
void swap_next(listint_t *node, listint_t **list)
{
	listint_t *swap = node->next;

	if (node->prev)
		node->prev->next = swap;
	else
		*list = swap;
	if (swap->next)
		swap->next->prev = node;
	swap->prev = node->prev;
	node->next = swap->next;
	node->prev = swap;
	swap->next = node;
}

/**
 * swap_previous - swaps backwards
 * @node: node to swap
 * @list: double pointer to the head of the list
 */
void swap_previous(listint_t *node, listint_t **list)
{
	listint_t *swap = node->prev;

	if (node->next)
		node->next->prev = swap;
	if (swap->prev)
		swap->prev->next = node;
	else
		*list = node;
	swap->next = node->next;
	node->prev = swap->prev;
	node->next = swap;
	swap->prev = node;
}

/**
 * cocktail_sort_list - sorts DLL of integers (ascending)
 *						by Cocktail shaker sort algorithm
 * @list: double pointer to the head of the DLL
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char flag_swap = 0;
	listint_t *node;

	if (list == NULL || *list == NULL)
		return;
	node = *list;
	do {
		while (node->next)
		{
			if (node->next->n < node->n)
			{
				swap_next(node, list);
				flag_swap = 1;
				print_list(*list);
			}
			else
				node = node->next;
		}
		if (flag_swap == 0)
			return;
		flag_swap = 0;
		while (node->prev)
		{
			if (node->prev->n > node->n)
			{
				swap_previous(node, list);
				flag_swap = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	} while (flag_swap != 0);
}
