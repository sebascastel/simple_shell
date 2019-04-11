#include "holberton.h"
/**
 * get_env - makes a copy of the environment variables
 * @head: pointer to pointer to head of list
 * @env: pointer to pointer of env to make copy of
 */
void get_env(listint_t **head, char **env)
{
	int row = 0;
	char *temp_key,  *temp_val;
	char *tempstr;

	while (env && env[row])
	{
		tempstr = _strdup(env[row]);
		temp_val = make_key_val(tempstr);
		temp_key = tempstr;
		*head = add_node_end(head, temp_key, temp_val);
		row++;
	}
}
