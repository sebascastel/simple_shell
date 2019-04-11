#include "holberton.h"
/**
 * helper_builtin_exit - checks if argument is exit.
 * @buff_tk: pointer to string to check
 * @argv: program name
 * @str: pointer to string
 * @input_count: number of commands processed
 * @stat: exit status
 * @err_num: error number
 * Return: Always 0.
 *
 */
int helper_builtin_exit(char **buff_tk,
	char *argv, char *str, size_t input_count, int *stat, int err_num)
{
	*stat = 2;
	str = _strcat(": Illegal number:", buff_tk[1], "\n");
	err_num = error_message(argv, input_count, str, buff_tk);
	free(str);
	if (err_num == 1)
	{
		free(buff_tk);
		buff_tk = NULL;
		return (1);
	}
return (0);
}

/**
 * s_exit - checks if argument is exit.
 * @buff_tk: pointer to string to check
 * @env: pointer to environment values
 * @buff: pointer to buffer
 * @argv: program name
 * @input_count: number of commands processed
 * @stat: exit status
 * Return: 0 if bad error message received in exit 1 otherwise
 *
 */
int s_exit(char **buff_tk, listint_t **env, char *buff,
	char *argv, size_t input_count, int *stat)
{
	int i = 0, error_num;
	unsigned long temp = 0;
	int shifter = ((sizeof(long) - 1) * 8);
	char *str = NULL;

	if (buff_tk && buff_tk[1])
	{
		for (i = 0; buff_tk[1][i]; i++)
		{
			if (buff_tk[1][i] < '0' || buff_tk[1][i] > '9')
			{
				str = _strcat(": Illegal number: ", buff_tk[1], "\n");
				error_num = error_message(argv, input_count, str, buff_tk);
				free(str);
				*stat = 2;
				if (error_num == 1)
				{
					free(buff_tk);
					buff_tk = NULL;
					return (1);
				}
			}
			else
			{
				temp = (temp * 10) + (buff_tk[1][i] - '0');
				if (temp > INT_MAX)
					helper_builtin_exit(buff_tk, argv, str, input_count, stat, error_num);
			}
		}
		*stat = (temp << shifter) >> shifter;
	}
	if (*stat > 255)
		*stat /= 256;
	free(buff);
	free(buff_tk);
	free_list(*env);
	fflush(NULL);
	_exit(*stat);
return (0);
}
