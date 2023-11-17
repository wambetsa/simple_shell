#include "main.h"
/**
 * _path - separate the path in new strings.
 * @arg: input
 * @env: enviroment
 * Return: str pointer
 */
int _path(char **arg, char **env)
{
	/*var declaration and initialization*/
	char *token = NULL;
	char *path_absol = NULL;
	char *path_rela = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;
	/*if stt*/
	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	/*get path*/
	path_rela = _getpath(env);
	if (!path_rela)
		return (-1);
	/*get token*/
	token = _strtok(path_rela, ":");
	command = _strlen(*arg);
	/*while loop*/
	while (token)
	{
		value_path = _strlen(token);
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}
		/*get abs path*/
		path_absol = _strcpy(path_absol, token);
		_strcat(path_absol, "/");
		_strcat(path_absol, *arg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*arg = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);
		token = _strtok(NULL, ":");
	}
	/*end of while loop*/
	/*free memory and return 1*/
	free(path_rela);
	return (-1);
}
