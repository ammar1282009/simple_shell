#include "main.h"

int main(int argc, char **argv);

/**
 * main - Entry point
 * @argc: arg count
 * @argv: array of arg
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char **args = NULL;
	char *buffer = NULL, *pathname = NULL;
	size_t n = 1024;
	ssize_t num_read = 0;
	const char *separator = " \n\t\r";
	int res = 0, counter = 0;
	(void)argc;

	if (isatty(STDIN_FILENO))
	{
		while (1998)
		{
			write(1, "#cisfun$ ", 10);
			num_read = getline(&buffer, &n, stdin);
			if (num_read == -1)
			{
				free(buffer);
				buffer = NULL;
				return (-1);
			}

			if (_strcmp(buffer, "env\n") == 0)
				print_env();

			else if (_strcmp(buffer, "exit\n") == 0)
			{
				free(buffer);
				buffer = NULL;
				exit(res);
			}
			else
			{
				buffer[num_read - 1] = '\0';
				if (access(buffer, X_OK) == 0)
				{
					args = parsing(buffer, separator);

					if (args)
					{
						execute(args, buffer);
					}
					else
					{
						free(buffer);
						buffer = NULL;
						exit(res);
					}
					free_grid(args);
					args = NULL;
				}
				else
				{
					args = parsing(buffer, separator);

					if (args)
					{
						pathname = search_pathname(args[0]);
						res = execute(args, pathname);
					}
					free(pathname);
					pathname = NULL;
					free_grid(args);
				}
			}
			free(buffer);
			buffer = NULL;
		}
	}
	else
	{
		while ((num_read = getline(&buffer, &n, stdin)) != -1)
		{
			counter++;
			buffer[num_read - 1] = '\0';
			if (_strcmp(buffer, "env") == 0)
				print_env();
			else if (_strcmp(buffer, "exit") == 0)
			{
				free_ptr(buffer);
				exit(res);
			}
			else
			{
				args = parsing(buffer, separator);

				if (args)
				{
					pathname = search_pathname(args[0]);

					if (pathname)
					{
						res = execute(args, pathname);
					}
					else
					{
						fprintf(stderr, "%s: %i: %s: not found\n", argv[0], counter, args[0]);
						res = 127;
					}
					if (pathname != args[0])
					{
						free_ptr(pathname);
					}
					free_grid(args);
				}
			}
		}
		free_ptr(buffer);
	}
	return (res);
}

/**
 * free_grid - frees the 2D array
 * @args: array of args
 */
void free_grid(char **args)
{
	int i = 0;

	if (args != NULL)
	{
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

/**
 * free_ptr - frees safely the ptr
 * @ptr: pointer
 */
void free_ptr(char *ptr)
{
	free(ptr);
	ptr = NULL;
}
