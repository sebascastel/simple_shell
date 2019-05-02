#include "holberton.h"
/**
 * free_list - frees memory for list
 * @head: pointer to head of list
 */
void free_list(listint_t *head)

{
    listint_t *next;
    while (head)
    {
        next = head->next;
        free(head);
        head = next;
    }
    return;
}
	




	

