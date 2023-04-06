#include "main.h"
#include <stdio.h>

/**
 * print_binary - print binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int temp;
	int myShifts;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (temp = n, myShifts = 0; (temp >>= 1) > 0; myShifts++)
		;

	for (; myShifts >= 0; myShifts--)
	{
		if ((n >> myShifts) & 1)
			printf("1");
		else
			printf("0");
	}
}
