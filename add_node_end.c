#include "holberton.h"
/**
 * add_node_end - adds a new node to end of list of integers
 * @head: pointer to pointer of head of node
 * @a: key value
 * @b: value
 * Return: list of integers with new node added
 */
listint_t *add_node_end(listint_t **head, char *a, char *b)
{
	listint_t *tmp_node, *new_node;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	new_node->a = a;
	new_node->b = b;
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		return (*head);
	}
	tmp_node = *head;
	while (tmp_node->next)
		tmp_node = tmp_node->next;
	tmp_node->next = new_node;
return (*head);
}
