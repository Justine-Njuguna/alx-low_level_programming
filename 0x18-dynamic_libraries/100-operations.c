#include "main.h"

/**
 * add - Adds two intts
 * @a: 1st int
 * @b: Second integer
 *
 * Return: The sum of the two integers
 */

int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - Subtracts two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: result
 */

int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - Multiplies two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Result.
 */

int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - Divides two integers
 * @a: First integer (numerator)
 * @b: Second integer (denominator)
 *
 * Return: Result.
 */

int div(int a, int b)
{
	if (b == 0)
	{
		fprintf(stderr, "Error: Division by zero\n");
		return (0);
	}

	return (a / b);
}

/**
 * mod - Computes the remainder of dividing two integers
 * @a: First integer (dividend)
 * @b: Second integer (divisor)
 *
 * Return: The remainder.
 */

int mod(int a, int b)
{
	if (b == 0)
	{
		fprintf(stderr, "Error: Modulo by zero\n");
		return (0);
	}

	return (a % b);
}
