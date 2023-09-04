#include "main.h"

/**
 * error_exit - Print error message and exit with status code 98.
 * @msg: Error messages
 */

void error_exit(char *msg)
{
	dprintf(STDERR_FILENO, "Error: %s\n", msg);
	exit(98);
}

/**
 * display_elf_header - Display information from the ELF header.
 * @header: Pointer to the ELF header structure.
 */

void display_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
			header->e_ident[0], header->e_ident[1],
			header->e_ident[2], header->e_ident[3],
			header->e_ident[4], header->e_ident[5],
			header->e_ident[6], header->e_ident[7],
			header->e_ident[8], header->e_ident[9],
			header->e_ident[10], header->e_ident[11],
			header->e_ident[12]);
	printf("  Class:                             %s\n",
			(header->e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n",
			(header->e_ident[EI_DATA] == ELFDATA2LSB)
			? "2's complement, little endian" : "unknown");
	printf("  Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n",
			header->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
			(header->e_type == ET_REL) ? "REL (Relocatable file)" :
			(header->e_type == ET_EXEC) ? "EXEC (Executable file)" :
			(header->e_type == ET_DYN) ? "DYN (Shared object file)" :
			(header->e_type == ET_CORE) ? "CORE (Core file)" : "unknown");
	printf("  Entry point address:               0x%lx\n",
			header->e_entry);
}

/**
 * main - Entry
 * @argc: Num of cli args
 * @argv: Array of ptrs
 *
 * Return: 0 on success, 98 on error.
 */

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Cannot open file");

	if (read(fd, &header, sizeof(header)) != sizeof(header))
		error_exit("Cannot read ELF header");
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Not an ELF file");

	display_elf_header(&header);

	close(fd);
	return (0);
}

