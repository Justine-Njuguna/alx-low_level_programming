#include "main.h"

/**
 * _memcpy - Copies n bytes from source to destination
 * @dest: The destination buffer
 * @src: The source buffer
 * @n: The number of bytes to copy
 *
 * Return: A ptr to the dest buffer.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *initDest = dest;

	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}

	return (initDest);
}
