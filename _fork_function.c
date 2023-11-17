#include "main.h"
/**
 * _forkfunction - create a fork
 *@arg: command values path
 *@av: program nm
 *@env: env
 *@lineptr: user commandline
 *@np: process id
 *@c: new test checker
 *Return: 0
 */

int _forkfunction(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	/*initialize vars*/
	pid_t child;
	int status;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
