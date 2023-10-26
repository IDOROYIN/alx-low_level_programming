#include "main.h"

/**
 * get_endianness - check the system Byte order
 * Return: 0 if big ending and 1 if little ending
 */

int get_endianness(void)
{
	int x = 1;
	int little_or_big;

	little_or_big = (int) (((char *)&x)[0]);
	return (little_or_big);
}
