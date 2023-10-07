#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 * @b: size of memory
 * Return: pointer to the memory allocated
 */

void *malloc_checked(unsigned int b)
{
	char *output;

	output = malloc(b);
	if (output == NULL)
		exit(98);
	else
		return (output);
}
