#include "main.h"

/**
 * _strcpy - Copies a string to another
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: A ptr to the dest buffer
 */

char *_strcpy(char *dest, char *src)
{
	char *initDest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (initDest);
}
