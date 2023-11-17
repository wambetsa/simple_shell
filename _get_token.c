#include "my_shell.h"
/**
 * _get_token - get token of string
 * @lineptr: comman user
 * Return: To a pointer
 */

char **_get_token(char *lineptr)
{
	/*declare and initialize var*/
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;
	/*if stt*/

	if (lineptr == NULL)
		return (NULL);
	/*for loop*/

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(lineptr))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);
	/*token*/

	token = _strtok(lineptr, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	user_command[i] = NULL;
	/*return user_input*/
	return (user_command);
}
