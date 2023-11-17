#include "main.h"
/**
 * _getline - printer wait for the user type something.
 * Return: str line of user input
 */

char *_getline(void)
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
