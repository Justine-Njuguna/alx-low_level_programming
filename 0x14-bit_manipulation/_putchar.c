#include "main.h"

/**
 * _putchar - Writes a character to standard output.
 * @c: The character to write.
 *
 * Return: On success, write char, else -1 and errno is set.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
