#include "main.h"

/**
 * _strstr - Locates a substring in a string
 * @haystack: The string to search
 * @needle: The substring to locate
 *
 * Return: A ptr to the beginning of the located substr else NULL.
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *h = haystack;
		char *n = needle;

		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
			return (haystack);

		haystack++;
	}

	return (NULL);
}
