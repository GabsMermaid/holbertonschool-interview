#include "lists.h"

/**
* check_cycle - Check if singly linked list has cycle in it
* @list: poinys to linked list
* Return: 0 if there is no cycle or 1 if there is a cycle
*/

int check_cycle(listint_t *list)
{
	listint_t *turtle = list, *hare = list;

	if (list == NULL)
		return (0);
	while (hare != NULL && hare->next != NULL && hare->next->next != NULL)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if (turtle == hare)
			return (1);
	}
	return (0);
}
