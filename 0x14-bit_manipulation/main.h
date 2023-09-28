#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

/* putchar */
int _putchar(char c);

/* Function prototypes */
unsigned int binary_to_uint(const char *b);

void print_binary(unsigned long int n);

int get_bit(unsigned long int n, unsigned int index);

#endif /* MAIN_H */
