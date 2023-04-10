#ifndef MAIN_H
#define MAIN_H

/*
 * File: Main.h
 * Author: Justine Njuguna
 * Desc: Header file that contains prototypes for all funtions written
 *		in the file i/o directory.
 */

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

ssize_t read_textfile(const char *filename, size_t letters);

int create_file(const char *filename, char *text_content);

#endif /* Ending my MAIN_H */