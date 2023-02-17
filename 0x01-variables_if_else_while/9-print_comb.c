#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 starting from 0
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
        int num;

        for (num = 0; num < 10; num++)
                putchar(num + '0');

        putchar('\n');

        return (0);
}
