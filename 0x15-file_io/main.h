#ifndef MAIN_H
#define MAIN_H

/* All header files */
/* =============================== */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

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

/* ============== Last Task ==================== */
/* Prints an error message provided as a string to STD_ERR and exit(98) */
void error_exit(char *msg);

/* Checks if the given array contains valid ELF magic numbers. */
void check_elf(unsigned char *e_ident);

/* Prints the magic numbers from the ELF header. */
void print_magic(unsigned char *e_ident);

/*  Prints the class of the ELF header. */
void print_class(unsigned char *e_ident);

/*  Prints the data format of the ELF header. */
void print_data(unsigned char *e_ident);

/* Prints the version of the ELF header. */
void print_version(unsigned char *e_ident);

/* Prints the OS/ABI of the ELF header. */
void print_osabi(unsigned char *e_ident);

/* Prints the ABI version of the ELF header. */
void print_abi(unsigned char *e_ident);

/*  Prints the type of the ELF header. */
void print_type(unsigned int e_type, unsigned char *e_ident);

/* Prints the entry point address of the ELF header. */
void print_entry(unsigned long int e_entry, unsigned char *e_ident);

/* Closes an open ELF file. */
void close_elf(int elf);

/* ============================================= */


#endif /* End of the main.h */
