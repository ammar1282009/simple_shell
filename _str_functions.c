#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: input
 * Return: integer
 */

int _atoi(char *s)
{

	unsigned int nombre = 0;
	int signe = 1;

	for (; *s != '\0'; s++)
	{
		if (*s == 45)
			signe *= -1;
		else if (*s >= 48 && *s <= 57)
			nombre = (nombre * 10) + (*s - 48);
		else if (nombre > 0)
			break;
	}
	return (nombre * signe);
}

/**
 * _strcmp - compare string values
 * @s1: input
 * @s2: input
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * *_strcpy - copies the string pointed
 * to by src to the buffer pointed to
 * by dest
 * @dest: input
 * @src: input
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = -1;

	while (src[i] != '\0')
	{

		dest[i] = src[i];
		i++;
	}

	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: input
 * Return: i
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	for (; *s != '\0'; s++)
		i++;
	return (i);
}
