#include "main.h"

/**
 * _putchar - Writes a char to stdout
 * @c: The char to be written.
 *
 * Return: On success, else num of char.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
