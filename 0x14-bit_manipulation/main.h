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

/* Function that prints the binary representation of a number - Task 1 */
void print_binary(unsigned long int n);

/* Function that returns the value of a bit at a given index - Task 2 */
int get_bit(unsigned long int n, unsigned int index);

/* Function that sets the value of a bit to 1 at a given index - Task 3 */
int set_bit(unsigned long int *n, unsigned int index);

/* Function that sets the value of a bit to 0 at a given index - Task 4 */
int clear_bit(unsigned long int *n, unsigned int index);

/* Function that returns the number of bits you would need to flip to get from one number to another - Task 5 */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

#endif /* MAIN_H */
