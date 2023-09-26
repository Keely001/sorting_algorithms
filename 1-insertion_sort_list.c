#include "sort.h"

/**
 * insertion_sort_list - sorts using the insertion method
 * @list: pointer to the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *nxt;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;
	while (curr != NULL) {
		nxt = curr->next;
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			curr->prev->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			curr->next = curr->prev;
			curr->prev = curr->next->prev;
			curr->next->prev = curr;
			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;
			print_list(*list);
		}
		curr = nxt;
	}
}
