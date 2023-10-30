#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int  *e_type, unsigned char *e_ident);
void print_version(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - This checks if a file is an ELF file
 * @e_ident: A pointer to an array containing the ELF magic number
 *
 * Description: if the file is not an ELF file - exit code 98.
 */
void chec_elf(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		  if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F' )
		 {
			 	dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
				exit(98);
		  }
	}
}
/**
 * print_magic - prints the magic number of an ELF header
 * @e_ident: A pointer to an array containing the ELF magic numbers
 * 
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int index;

	printf(" Magic: ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x" o_ident[index]);
		if (index == EI_NIDENT -1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_class(unsigned char *e_ident)
{
	printf(" class class:                 ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("EELF32\n");
	case ELFCLASS64:
		printf("ELF64\n");
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - print the data of an ELF header
 * @e_ident: A pointer to an array containing the Elf class.
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data:                               ");

	switch (e_ident[EI_DATA])
	{
	case ELDATAONE:
		printf("none\n");
		break;
	caseELDATA2LSB:
		printf("2' s complement, little ending\n");
		break;
	case ELFDATA2MSB:
		printf("2' s compliment, big ending\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - prints the virsion of an ELF header
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI :                           ");
	
	switch (E_ident[EL_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - system V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - LINUS\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX -solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX -IRIX\n");
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
		printf("standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}
/**
 * print_version - prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf(" version:                        %d",
			e_ident[EI_VERSION]);
	
	switch (e_ident[EI_VERSION]);
	{
	case EV_CURRENT:
		printf("(current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}
