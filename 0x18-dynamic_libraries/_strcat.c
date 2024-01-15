#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The dest buffer.
 * @src: The source str.
 *
 * Return: A ptr to th dest buffer.
 */

char *_strcat(char *dest, char *src)
{
	char *initDest = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (initDest);
}
