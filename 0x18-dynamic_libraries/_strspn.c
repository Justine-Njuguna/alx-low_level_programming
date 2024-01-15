#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to search
 * @accept: The set of characters to accept in the prefix
 *
 * Return: The length of the prefix substr.
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int counter = 0;

	while (*s != '\0' && _strchr(accept, *s) != NULL)
	{
		counter++;
		s++;
	}

	return (counter);
}
