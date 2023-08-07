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

/* Function that reads a text file and prints it to the POSIX STD_OUT - Task 0 */
ssize_t read_textfile(const char *filename, size_t letters);

/* Function that creates a file - Task 1 */
int create_file(const char *filename, char *text_content);

/* Function that appends text at the end of a file - Task 2 */
int append_text_to_file(const char *filename, char *text_content);

#endif /* End of the main.h */
