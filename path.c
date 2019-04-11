#include "holberton.h"
/**
 * aux_path - auxiliar function for path
 * @path_cp: the environment variable PATH
 * @concat_path: variable that holds the concatenated path
 * @path_tk: path token
 * @buff_tk: the first argument of user input
 * @argv: program name
 * @input_count: number of commands processed
 * @stat: exit status
 * Return: return NULL.
 */
char *aux_path(char *argv, char *path_cp, char *concat_path, char **path_tk,
	char **buff_tk, size_t input_count, int *stat)
{
	error_message(argv, input_count, ": Permission denied\n", buff_tk);
	free(path_cp);
	free(path_tk);
	*stat = 126;
	free(buff_tk);
	free(concat_path);
return (NULL);
}
/**
 * path_helper - searches the correct path of command and
 * concatenates the path with '/' and command
 * @path: the environment variable PATH
 * @buff_tk: the first argument of user input
 * @argv: program name
 * @input_count: number of commands processed
 * @stat: exit status
 * Return: return the concatenate string if found,
 * otherwise, return NULL if not found.
 */
char *path_helper(char *path, char **buff_tk, char *argv,
	size_t input_count, int *stat)
{
	char *path_cp = NULL, *concat_path = NULL;
	char **path_tk = NULL;
	int i = 0;

	if (path)
	{
		if (path[0] == ':' && path[_strlen(path) - 1] == ':')
			path_cp = _strcat(".", path, ".");
		else if (path[0] == ':')
			path_cp = _strcat(".", path, "");
		else if (path[_strlen(path) - 1] == ':')
			path_cp = _strcat(path, ".", "");
		else
			path_cp = _strdup(path);
		path_tk = create_arg_list(path_tk, path_cp, ":");
	}
	else
		path_tk = NULL;
	while (path_tk && path_tk[i] != NULL)
	{
		concat_path = _strcat(path_tk[i], "/", buff_tk[0]);
		if (access(concat_path, X_OK) == 0)
		{
			free(path_cp);
			free(path_tk);
			return (concat_path);
		}
		if (access(concat_path, F_OK) == 0)
		{
			aux_path(argv, path_cp, concat_path, path_tk, buff_tk, input_count, stat);
		}
		i++;
		free(concat_path);
	}
	free(path_cp);
	free(path_tk);
	*stat = 127;
	error_message(argv, input_count, ": not found\n", buff_tk);
	free(buff_tk);
return (NULL);
}
