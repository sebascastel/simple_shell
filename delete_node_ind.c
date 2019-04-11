#include "holberton.h"
/**
 * delete_node_at_index - deletes a node at index given
 * @head: pointer to pointer of head of list
 * @index: element to delete
 * Return: 1 if deletion successful -1 if failed
 */
int delete_node_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev_node = NULL;
	listint_t *tgt_node = NULL;
	unsigned int counter = 0;

	if (!*head)
		return (-1);
	tgt_node = *head;
	while (counter < index && tgt_node)
	{
		prev_node = tgt_node;
		tgt_node = tgt_node->next;
		counter++;
	}
	if (counter != index)
		return (-1);
	if (!prev_node)
		*head = tgt_node->next;
	else
		prev_node->next = tgt_node->next;
	free(tgt_node->a);
	free(tgt_node);
return (1);
}
