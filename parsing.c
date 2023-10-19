#include "main.h"
char **parsing(char *buffer, const char *separator);
/**
 * **parsing - tokenizes the command line
 * @buffer: input line
 * @separator: delim
 * Return: double pointer
 */
char **parsing(char *buffer, const char *separator)
{
	char *buffer_copy = NULL, *token;
	char *temp_copy = NULL;
	int num_tokens = 0;
	int i, j;
	char **argv;

	buffer_copy = strdup(buffer);
	if (buffer_copy == NULL)
	{
		return (NULL);
	}

	temp_copy = strdup(buffer_copy);
	if (temp_copy == NULL)
	{
		free(buffer_copy);
		buffer_copy = NULL;
		return (NULL);
	}

	token = strtok(temp_copy, separator);

	if (token != NULL)
	{

		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, separator);
		}
		free(temp_copy);
		temp_copy = NULL;

		argv = malloc(sizeof(char *) * (num_tokens + 1));
		if (argv == NULL)
		{
			free(buffer_copy);
			return (NULL);
		}

		token = strtok(buffer_copy, separator);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = strdup(token);

			if (argv[i] == NULL)
			{
				for (j = 0; j < i; j++)
				{
					free(argv[j]);
					argv[i] = NULL;
				}
				free(argv);
				argv = NULL;
				free(buffer_copy);
				buffer_copy = NULL;
				return (NULL);
			}
			token = strtok(NULL, separator);
		}
		argv[i] = NULL;
	}
	else
	{
		free(temp_copy);
		temp_copy = NULL;
		free(buffer_copy);
		buffer_copy = NULL;
		return (NULL);
	}

	free(temp_copy);
	temp_copy = NULL;
	free(buffer_copy);
	buffer_copy = NULL;

	return (argv);
}
