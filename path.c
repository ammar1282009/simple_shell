#include "main.h"

/**
 * *creer_path_linked_list - create a linked list from PATH
 * Return: head pointer
 */

noeud *creer_path_linked_list()
{
	char *directory = NULL;
	char *path = NULL, *path_copy = NULL;
	noeud *head = NULL, *last_ptr = NULL;

	path = getenv("PATH");
	path_copy = strdup(path);

	directory = strtok(path_copy, "=:");

	while (directory != NULL)
	{
		noeud *new_n = (noeud *)malloc(sizeof(noeud));

		if (new_n == NULL)
			return (NULL);

		new_n->dir = strdup(directory);
		new_n->next = NULL;

		if (head)
		{
			last_ptr->next = new_n;
			last_ptr = new_n;
		}
		else
		{
			head = new_n;
			last_ptr = new_n;
		}

		directory = strtok(NULL, ":");
		if (directory == NULL)
			break;
	}

	free(path_copy);
	return (head);
}

/**
 * free_path_list - free the linked list
 * @head: pointer to the first node
 */

void free_path_list(noeud *head)
{
	noeud *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->dir);
		free(tmp);
	}
}

/**
 * *search_pathname - checks if the command exists in the PATH
 * @arg: command (argv[0])
 * Return: arg
 */

char *search_pathname(char *arg)
{
	char *result = NULL, *check_path = (char *)malloc(100);

	if (check_path == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	if ((access(arg, X_OK) != 0) && (arg[0] != '/' && arg[0] != '.'))
	{
		struct stat st;
		noeud *path_list = creer_path_linked_list();
		noeud *head = path_list;

		while (path_list != NULL)
		{
			strcpy(check_path, path_list->dir);
			strcat(check_path, "/");
			strcat(check_path, arg);
			strcat(check_path, "\0");
			if (!(stat(check_path, &st)))
			{
				result = strdup(check_path);
				free(check_path);
				break;
			}
			path_list = path_list->next;
		}
		if (result == NULL)
		{
			free(check_path);
		}
		free_path_list(head);
	}
	else /*if ((arg[0] == '/' || arg[0] == '.') && !(access(arg, X_OK) != 0))*/
	{
		result = arg;
		free(check_path);
	}
	return (result);
}
