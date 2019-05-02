#include "holberton.h"
/**
 * delete_node_at_index - deletes a node at index given
 * @head: pointer to pointer of head of list
 * @index: element to delete
 * Return: 1 if deletion successful -1 if failed
 */
int delete_node_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev_node = NULL, target_node = NULL;

	unsigned int counter = 0;

	if (!*head)
		return (-1);
	target_node = *head;
	while (counter < index && target_node)
	{
		prev_node = target_node;
		target_node = target_node->next;
		counter++;
	}
	if (counter != index)
		return (-1);
	if (!prev_node)
		*head = target_node->next;
	else
		prev_node->next = target_node->next;
	free(target_node->a);
	free(target_node);
return (1);
}
