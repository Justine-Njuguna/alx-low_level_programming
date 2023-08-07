#ifndef MAIN_H
#define MAIN_H

/* All header files */
/* =============================== */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/* All Prototypes */
/* ================================ */

/* Prototype for _putchar */
int _putchar(char c);

/* Function that reads a text file and prints it to the POSIX STD_OUT */
ssize_t read_textfile(const char *filename, size_t letters);

#endif /* End of the main.h */
