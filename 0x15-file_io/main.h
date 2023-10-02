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


#endif
