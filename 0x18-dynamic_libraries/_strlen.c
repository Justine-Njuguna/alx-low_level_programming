#include "main.h"

/**
 * _strlen - Computes the length of a string
 * @s: The string.
 *
 * Return: strlen.
 */

int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}

	return (len);
}
