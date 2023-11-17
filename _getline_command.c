#include "my_shell.h"
/**
 * _getline_command - user type something.
 * Return: str input for user
 */

char *_getline_command(void)
{
	/*declare and initialize vars*/
	char *lineptr = NULL;
	size_t charter_user = 0;
	/*if stt*/
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineptr, &charter_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}
	/*return*/
	return (lineptr);
}
