#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned int.
 * _putchar - Writes a character to std output.
 * @b: checker.
 *
 * Return: On success the character written is returned, else -1.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	int i;
	char c;

	if (b == NULL)
	{
		return (0);
	}

	for (i = 0; b[i] != '\0'; i++)
	{
		c = b[i];

		if (c != '0' && c != '1')
		{
			return (0);
		}

		result = (result << 1) | (c - '0');
	}

	return (result);
}
