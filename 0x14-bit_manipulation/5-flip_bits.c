#include "main.h"
#include <stdio.h>

/**
 * flip_bits - flip bits to convert one number to another number
 * @n: first number
 * @m: second number to convert to
 * Return: number of bit that was needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip;
	int count;

	flip = n ^ m;
	count = 0;

	while (flip)
	{
		count++;
		flip &= (flip - 1);
	}

	return (count);
}
