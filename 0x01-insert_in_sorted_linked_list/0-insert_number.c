#include "lists.h"
#include <stdlib.h>

/**
 * Write a function in C that inserts a number into a sorted singly linked list.
 * insert_node - add node to list
 * @head: pointer to a pointer - head of the list
 * @number: integer value to be inserted
 * Return: address of new node or NULL if fails
 **/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newNode, *tmp = *head;

	newNode = malloc(sizeof(listint_t)); /*Assign mwmory space for newNode*/
	if (newNode == NULL)  /*validate malloc is good, if not return null*/
		return (NULL);
	newNode->n = number;
	if (*head == NULL) /*Validate if there is not elements in the list*/
	{
		*head = newNode;
		newNode->next = NULL;
		return (newNode);
	}
	if (tmp->next == NULL)
	{ /* validate if there is only one element in the list*/
		newNode->next = NULL;
		tmp->next = newNode;
		return (newNode);
	}
	if (number <= tmp->n)
	{
		newNode->next = tmp;
		*head = newNode;
		return (newNode);
	}
	while (tmp->next != NULL)
	{/*go through the list*/
		if (number <= tmp->next->n)
		{
			newNode->next = tmp->next;
			tmp->next = newNode;
			return (newNode);
		}
		tmp = tmp->next;
	}
	tmp->next = newNode;
	newNode->next = NULL;
	return (newNode);
}
