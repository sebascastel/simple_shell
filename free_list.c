#include "holberton.h"
/**
 * free_list - frees memory for list
 * @head: pointer to head of list
 */
void free_list(listint_t *head)
{
	if (head)
	{
		if (head->next)
			free_list(head->next);
		free(head->a);
		free(head);
	}
}
