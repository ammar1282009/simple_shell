#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

extern char **environ;

/**
 * struct node - structure
 * @dir: the directory
 * @next: pointer to the next node (directory)
 */

typedef struct node
{
	char *dir;
	struct node *next;
} noeud;

int _atoi(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);

char **parsing(char *buffer, const char *separateur);
int execute(char **argv, char *arg);

noeud *creer_path_linked_list();
void free_path_list(noeud *head);
char *search_pathname(char *arg);

void free_ptr(char *ptr);
void free_grid(char **argv);

void print_env(void);
void b_in_exit(char **argv);

#endif

