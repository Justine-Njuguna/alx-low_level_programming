#include "main.h"

/**
 * _strncat - Concatenates n characters from two strings
 * @dest: The destination buffer
 * @src: The source string to append
 * @n: The maximum number of characters to append
 *
 * Return: A ptr to the dest buffer.
 */

char *_strncat(char *dest, char *src, int n)
{
	char *initDest = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	*dest = '\0';

	return (initDest);
}
