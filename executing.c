#include "main.h"

/**
 * execute - runs the command in a child process
 * @argv: command line
 * @arg: command
 * Return: 0 on success, 127 in case of failure
 */

int execute(char **argv, char *arg)
{
	__pid_t id;

	if (access(arg, X_OK))
		return (127);

	id = fork();
	if (!id)
	{
		if (execve(arg, argv, NULL) == -1)
		{
			free_grid(argv);
			perror("./shell");
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
