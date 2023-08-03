#ifndef MAIN_H
#define MAIN_H

/* Our .h files */
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

/* Custom _putchar function */
int _putchar(char c);

/* Function to convert a binary string to an unsigned int - Task 0 */
unsigned int binary_to_uint(const char *b);

/* Function that prints the binary representation of a number Task 1 */
void print_binary(unsigned long int n);

#endif /* MAIN_H */
