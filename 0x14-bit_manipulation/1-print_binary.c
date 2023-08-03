#include "main.h"

/**
 * print_binary - Prints the binary representation of a num.
 * @n: The number to convert and print.
 * Author - Aeldra
 *
 * Return: none.
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
