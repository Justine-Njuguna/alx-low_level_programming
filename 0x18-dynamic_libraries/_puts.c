#include "main.h"

/**
 * _puts - Prints a str to stdout.
 * @s: The str to print
 *
 * Return: void.
 */

void _puts(char *s)
{
	while (*s != '\0')
	{
		_putchar(*s);
		s++;
	}

	_putchar('\n');
}
