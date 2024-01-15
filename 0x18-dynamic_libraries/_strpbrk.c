#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to search
 * @accept: The set of characters to search for
 *
 * Return: A ptr to the first occurence in s of any char in accept else NULL.
 */

char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		if (_strchr(accept, *s) != NULL)
			return (s);

		s++;
	}

	return (NULL);
}
