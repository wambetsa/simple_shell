#include "my_shell.h"
/**
 * main function
 * @argc: argumnent count @argv - arguments
 * @env: environment variable
 * Return: 0
 */
int main(int ac, char **av, char **env)
{
	/*declare and initialize variables*/
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, _exit = 0, n = 0;
	(void)ac;
	/*while true loop*/
	while (1)
	{
		/*retrieve user input*/
		getcommand = _getline_command();
		if (getcommand)
		{
			/*increment path values*/
			pathValue++;
			user_command = _get_token(getcommand);
			if (!user_command)
			{
				/*free space and continue*/
				free(getcommand);
				continue;
			}
			/*exit*/
			if ((!_strcmp(user_command[0], "exit")) && user_command[1] == NULL)
				_exit_command(user_command, getcommand, _exit);
			/*getenv*/
			if (!_strcmp(user_command[0], "env"))
				_getenv(env);
			else
			{
				n = _values_path(&user_command[0], env);
				_exit = _fork_fun(user_command, av, env, getcommand, pathValue, n);
				if (n == 0)
					free(user_command[0]);
			}
			/*free user_input space*/
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit);
		}
		/*free mycommandgetter*/
		free(getcommand);
	}
	/*return exit which is 0*/
	return (_exit);
}
