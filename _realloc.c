#include "holberton.h"
/**
 * _realloc - function to reallocate memory
 * @ptr: void pointer
 * @old_size: old size to be reasigned
 * @new_size: new size to be allocated
 * Return: void pointer ret.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *ret = 0;
	char *write, *read;

	if (new_size == old_size)
		return (ptr);
	if (new_size > 0 || ptr == 0)
	{
		ret = malloc(new_size);
		if (ret == 0)
			return (0);
	}
	if (new_size > 0 && ptr != 0)
	{
		write = ret;
		read = ptr;
		if (new_size < old_size)
			old_size = new_size;
		while (old_size)
		{
			old_size--;
			*write++ = *read++;
		}
	}
	free(ptr);
return (ret);
}
