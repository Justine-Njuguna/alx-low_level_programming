#include "main.h"

/**
 * _putchar - Writes a char to stdout.
 * @c: Char to print.
 *
 * Return: On success 1 else -1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
