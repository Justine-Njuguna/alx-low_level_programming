#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>  /* for malloc, free, and exit */
#include <unistd.h>  /* for read, write, close, and STDIN_FILENO constants */
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

/* Task 0 */
ssize_t read_textfile(const char *filename, size_t letters);

/* Task 1 */
int create_file(const char *filename, char *text_content);

/* Task 2 */
int append_text_to_file(const char *filename, char *text_content);

/* Task 3 */
void handle_error(int exit_code, const char *message);

/* Task 3 */
void copy_file(const char *file_from, const char *file_to);

/* Task 4 */
void display_elf_header(const char *elf_filename);

#endif /* MAIN_H */

