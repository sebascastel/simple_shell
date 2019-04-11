#include "holberton.h"
/**
 * change_pwd - changes current working directory
 * @env_cp:  copy of the environment
 * @a: environment variable to look for
 * @add: value of environment to add
 * Return: 1 if successful -1 if not
 */
int change_pwd(listint_t **env_cp, char *a, char *add)
{
	listint_t *temp = *env_cp;
	int index = 0;
	char *temp_str = NULL, *temp_val = NULL, *temp_key = NULL;

	while (temp && (_strcmp(temp->a, a) != 0))
	{
		index++;
		temp = temp->next;
	}
	if (temp)
	{
		if (delete_node_at_index(env_cp, index) == -1)
		{
			return (-1);
		}
	}
	temp_str = _strcat(a, "=", add);
	temp_val = make_key_val(temp_str);
	temp_key = temp_str;
	temp = add_node_end(env_cp, temp_key, temp_val);
	return (1);
}
