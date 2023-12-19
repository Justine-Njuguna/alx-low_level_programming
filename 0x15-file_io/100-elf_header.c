#include "main.h"

/**
 * validate_elf_magic - Validates if a file is an ELF file.
 * @magic_numbers: A ptr to an arr containing ELF magic nums.
 *
 * Return: code 98  if not ELF file
 */

void validate_elf_magic(unsigned char *magic_numbers)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (magic_numbers[index] != 127 &&
				magic_numbers[index] != 'E' &&
				magic_numbers[index] != 'L' &&
				magic_numbers[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_elf_magic - Prints the magic numbers of an ELF header.
 * @magic_numbers: A ptr to an arr containing the ELF magic nums.
 */

void print_elf_magic(unsigned char *magic_numbers)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", magic_numbers[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
 * print_elf_class - prints the class of an ELF header
 * @magic_numbers: A ptr to an arr containing the ELF class.
 */

void print_elf_class(unsigned char *magic_numbers)
{
	printf("  Class:                             ");

	switch (magic_numbers[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", magic_numbers[EI_CLASS]);
	}
}

/**
 * print_elf_data - Prints the data of an ELF header
 * @magic_numbers: A ptr to an array containing ELF CLASS.
 */

void print_elf_data(unsigned char *magic_numbers)
{
	printf("  Data:                              ");

	switch (magic_numbers[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", magic_numbers[EI_DATA]);
	}
}

/**
 * print_elf_version - Prints the version of an ELF header
 * @magic_numbers: A ptr to an Arr of the ELF version
 */

void print_elf_version(unsigned char *magic_numbers)
{
	printf("  Version:                           %d",
			magic_numbers[EI_VERSION]);

	switch (magic_numbers[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_elf_osabi - Prints the OS/ABI of an ELF header
 * @magic_numbers: A ptr to an arr containing the ELF version
 */

void print_elf_osabi(unsigned char *magic_numbers)
{
	printf("  OS/ABI:                            ");

	switch (magic_numbers[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown %x>\n", magic_numbers[EI_OSABI]);
			break;
	}
}

/**
 * print_elf_abi_version - Prints the ABI version of an ELF header.
 * @magic_numbers: A ptr to an arr containing the ELF ABI version.
 */

void print_elf_abi_version(unsigned char *magic_numbers)
{
	printf("  ABI Version:                       %d\n",
			magic_numbers[EI_ABIVERSION]);
}

/**
 * print_elf_type - Prints the type of an ELF header.
 * @elf_type: The ELF type.
 * @magic_numbers: A ptr to an arr containing the ELF class.
 */

void print_elf_type(unsigned int elf_type, unsigned char *magic_numbers)
{
	if (magic_numbers[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf("  Type:                              ");

	switch (elf_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown %x>\n", elf_type);
	}
}

/**
 * print_elf_entry - Prints the entry point of an ELF header.
 * @entry_point: The address of the ELF entry point.
 * @magic_numbers: A ptr to an arr containing the ELF Class.
 */

void print_elf_entry(unsigned long int entry_point,
		unsigned char *magic_numbers)
{
	printf("  Entry point address:               ");

	if (magic_numbers[EI_DATA] == ELFDATA2MSB)
	{
		entry_point = ((entry_point << 8) & 0xFF00FF00) |
			((entry_point >> 8) & 0xFF00FF);
		entry_point = (entry_point << 16) | (entry_point >> 16);
	}

	if (magic_numbers[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int) entry_point);
	else
		printf("%#lx\n", entry_point);
}

/**
 * close_elf_file - Closes an ELF file
 * @file_descriptor: The fd of the ELF file.
 *
 * Return: code 98 if file cannot be closed.
 */

void close_elf_file(int file_descriptor)
{
	if (close(file_descriptor) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", file_descriptor);
		exit(98);
	}
}

/**
 * main - Displays info from the ELF header of and ELF file.
 * @argc: The argument count supplied to the program.
 * @argv: An arr of ptrs to the args.
 *
 * Return: 0 on success.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int file_descriptor, read_result;

	file_descriptor = open(argv[1], O_RDONLY);
	if (file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_result = read(file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		close_elf_file(file_descriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	validate_elf_magic(header->e_ident);

	printf("ELF Header:\n");
	print_elf_magic(header->e_ident);
	print_elf_class(header->e_ident);
	print_elf_data(header->e_ident);
	print_elf_version(header->e_ident);
	print_elf_osabi(header->e_ident);
	print_elf_abi_version(header->e_ident);
	print_elf_type(header->e_type, header->e_ident);
	print_elf_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf_file(file_descriptor);
	return (0);
}
