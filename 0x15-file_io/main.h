#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <elf.h>
#define BUFFER_SIZE 1024


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
void display_elf_header(Elf64_Ehdr *header);

#endif /* MAIN_H */

