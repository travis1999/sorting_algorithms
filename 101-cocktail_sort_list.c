#include "sort.h"
/**
 * cocktail_sort_list - The coctail sort
 * Description: Bubble sort
 * @list: list to sort
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tail = NULL;
	int sort = 1;

	if (list == NULL || *list == NULL)
		return;
	head = *list;
	while (sort != 0)
	{
		sort = 0;
		while (head && head->next)
		{
			if (head->n > head->next->n)
			{
				swap_values(head, head->next, list);
				sort = 1;
				if (head->next != NULL)
					continue;
			}
			if (head->next == NULL)
				break;
			head = head->next;
		}
		if (sort == 0)
			break;
		tail = head;
		while (tail && tail->prev)
		{
			if (tail->prev->n > tail->n)
			{
				swap_values(tail->prev, tail, list);
				sort = 1;
				if (tail->prev != NULL)
					continue;
			}
			if (tail->prev == NULL)
				break;
			tail = tail->prev;
		}
		head = tail;
	}
}
/**
 * swap_values - swaps
 * @swap_1: first node
 * @swap_2: second node
 * @list: list
 */
void swap_values(listint_t *swap_1, listint_t *swap_2, listint_t **list)
{
	listint_t *aux_1, *aux_2;

	aux_1 = swap_1->prev, aux_2 = swap_2->next;
	if (aux_1 != NULL)
		aux_1->next = swap_2;
	else
		*list = swap_2;
	aux_2 != NULL ? aux_2->prev = swap_1 : aux_2;
	swap_2->prev = aux_1, swap_1->next = aux_2;
	swap_2->next = swap_1, swap_1->prev = swap_2;
	print_list(*list);
}
