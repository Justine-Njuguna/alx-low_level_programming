#include "main.h"

/**
 * _memset - Fills the first n bytes of a memory area with a constant byte
 * @s: The memory area to fill
 * @b: The constant byte to fill with
 * @n: The number of bytes to fill
 *
 * Return: A ptr to the memory area s.
 */

char *_memset(char *s, char b, unsigned int n)
{
	while (n > 0)
	{
		*s = b;
		s++;
		n--;
	}

	return (s);
}
