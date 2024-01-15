#include "main.h"

/**
 * _strncpy - Copies up to n characters from one string to another
 * @dest: The destination buffer
 * @src: The source string
 * @n: The maximum number of characters to copy
 *
 * Return: A ptr to the dest buffer.
 */

char *_strncpy(char *dest, char *src, int n)
{
	char *initDest = dest;

	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	while (n > 0)
	{
		*dest = '\0'; /* Pad with null bytes if n > the length of src */
		dest++;
		n--;
	}

	return (initDest);
}
