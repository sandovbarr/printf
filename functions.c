#include "holberton.h"

/**
 * print_strings - print strings
 * @list: list of arguments
 * @p: pointer to buffer
 * @g: counter to return
 * Return: integer or counter
 */

int print_strings(va_list list, char *p, int g)
{
	int i = 0;
	char *j = va_arg(list, char*);

	if (j == NULL)
	{
		j = "(null)";
	}
	for (i = 0; j[i]; i++)
	{
		p[g + i] = j[i];
	}
	return (i);
}

/**
 * print_char - print chars
 * @list: list of arguments
 * @p: pointer to buffer
 * @g: counter to return
 * Return: integer or counter
 */

int print_char(va_list list, char *p, int g)
{
	char j = va_arg(list, int);

	p[g] = j;
	return (1);
}


/**
 * print_opc - print chars
 * @list: list of arguments
 * @p: pointer to buffer
 * @g: counter to return
 * Return: integer or counter
 */

int print_opc(va_list list, char *p, int g)
{
	(void)list;
	p[g] = 37;
	return (1);
}

/**
 * print_bin - print in binaries
 * @list: list of arguments
 * @p: pointer to buffer
 * @g: counter to return
 * Return: integer or counter
 */

int print_bin(va_list list, char *p, int g)
{
	unsigned int var = va_arg(list, int);
	int count = 0;
	int j = 0;
	char *numero = malloc(100);

	while (var >= 2)
	{
		*(numero + count) = var % 2 + '0';
		var /= 2;
		count++;
	}
	if (var == 1)
	{
		*(numero + count) = var + '0';
	}

	for (j = 0; count >= 0; j++, count--)
	{
		p[g + j] = numero[count];
	}
	free(numero);
	return (j);
}

/**
 * print_octal - print in binaries
 * @list: list of arguments
 * @p: pointer to buffer
 * @g: counter to return
 * Return: integer or counter
 */

int print_octal(va_list list, char *p, int g)
{
	unsigned int var = va_arg(list, unsigned int);
	int count = 0;
	int j = 0;
	char *numero = malloc(100);

	while (var >= 8)
	{
		*(numero + count) = var % 8 + '0';
		var /= 8;
		count++;
	}
	if (var > 0)
	{
		*(numero + count) = var + '0';
	}

	for (j = 0; count >= 0; j++, count--)
	{
		p[g + j] = numero[count];
	}
	free(numero);
	return (j);
}
