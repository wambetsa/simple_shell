#include "main.h"

/**
 * main function
 * @argc - argumnent count @argv - arguments
 * @env - environment variable
 * Return: 0
 */

int main(int ac, char **av, char **env)
{
	/*declare and initialize variables*/
	char *mycommandgetter = NULL;
	char **user_input = NULL;
	int pathValue = 0, _exit = 0, n = 0;
	(void)ac;
	/*while true loop*/
	while (1)
	{
		/*retrieve user input*/
		mycommandgetter = _getline();
		if (mycommandgetter)
		{
			/*increment path values*/
			pathValue++;
			user_input = _gettoken(mycommandgetter);
			if (!user_input)
			{
				/*free space and continue*/
				free(mycommandgetter);
				continue;
			}
			/*exit*/
			if ((!_strcmp(user_input[0], "exit")) && user_input[1] == NULL)
				_exit_command(user_input, mycommandgetter, _exit);
			/*getenv*/
			if (!_strcmp(user_input[0], "env"))
				_getenv(env);
			else
			{
				n = _path(&user_input[0], env);
				_exit = _forkfunction(user_input, av, env, mycommandgetter, pathValue, n);
				if (n == 0)
					free(user_input[0]);
			}
			/*free user_input space*/
			free(user_input);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		/*free mycommandgetter*/
		free(mycommandgetter);
	}
	/*return exit which is 0*/
	return (_exit);
}