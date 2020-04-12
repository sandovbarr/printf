#include "holberton.h"

/**
 * print_integers - print integers
 * @list: list of arguments
 * @p: pointer to buffer
 * @g: counter to return
 * Return: integer or counter
 */

int print_integers(va_list list, char *p, int g)
{
	long int j = va_arg(list, int), i = 0;
	long int aux = j, retorno = 0;

	if (j < 0)
	{
		aux = j *= -1;
		p[g] = '-';
		i++;
	}

	while (aux / 10 > 0)
	{
		aux = aux / 10;
		i++;
	}
	retorno = i;
	while (j / 10 > 0)
	{
		p[g + i] = j % 10 + '0';
		j = j / 10;
		i--;
	}
	p[g + i] = j % 10 + '0';
	retorno++;
	return (retorno);
}

/**
 * print_unintegers - print unsigned integers
 * @list: list of arguments
 * @p: pointer to buffer
 * @g: counter to return
 * Return: integer or counter
 */

int print_unintegers(va_list list, char *p, int g)
{
	unsigned int j = va_arg(list, int);
	int i = 0;
	unsigned int aux = j, retorno = 0;

	while (aux / 10 > 0)
	{
		aux = aux / 10;
		i++;
	}
	retorno = i;
	while (j / 10 > 0)
	{
		p[g + i] = j % 10 + '0';
		j = j / 10;
		i--;
	}
	p[g + i] = j % 10 + '0';
	retorno++;
	return (retorno);
}

/**
 * print_hexa - print in hexadecimal format
 * @list: list of arguments
 * @p: pointer to buffer
 * @g: counter to return
 * Return: integer or counter
 */

int print_hexa(va_list list, char *p, int g)
{
	unsigned int var = va_arg(list, unsigned int);
	int count = 0;
	int j = 0;
	int x = 0;
	char *numero = malloc(100);

	while (var >= 16)
	{
		if (var %  16 > 9)
			x = 87;
		else
			x =  48;

		*(numero + count) = var % 16 + x;
		var /= 16;
		count++;
	}

	if (var > 0)
	{
		if (var %  16 > 9)
			x = 87;
		else
			x =  48;

		*(numero + count) = var + x;
	}

	for (j = 0; count >= 0; j++, count--)
	{
		p[g + j] = numero[count];
	}
	free(numero);
	return (j);
}

/**
 * print_hexaM - print in hexadecimal format
 * @list: list of arguments
 * @p: pointer to buffer
 * @g: counter to return
 * Return: integer or counter
 */

int print_hexaM(va_list list, char *p, int g)
{
	unsigned int var = va_arg(list, unsigned int);
	int count = 0;
	int j = 0;
	int x = 0;
	char *numero = malloc(100);

	while (var >= 16)
	{
		if (var %  16 > 9)
			x = 55;
		else
			x =  48;

		*(numero + count) = var % 16 + x;
		var /= 16;
		count++;
	}

	if (var > 0)
	{
		if (var %  16 > 9)
			x = 55;
		else
			x =  48;

		*(numero + count) = var + x;
	}

	for (j = 0; count >= 0; j++, count--)
	{
		p[g + j] = numero[count];
	}
	free(numero);
	return (j);
}
