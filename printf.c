#include "holberton.h"

/**
 * _printf - prints all the types of character
 * @format: pointer to string to print
 * Return: numbers of printed bytes
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, k = 0, bfc = 0;
	char *buffer = malloc(2048);
	va_list args;
	s options[] = {
		{'%', print_opc}, {'s', print_strings}, {'c', print_char},
		{'i', print_integers}, {'d', print_integers},
		{'u', print_unintegers}, {'b', print_bin}, {'x', print_hexa},
		{'X', print_hexaM}, {'o', print_octal}};

	va_start(args, format);
	if (!format || !buffer || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; j < 10; j++)
			{
				if (format[i + 1] == options[j].p)
				{
					k = options[j].f(args, buffer, bfc);
					bfc += k, i++;
					if (k == -1)
						return (-1);
					break;
				}
			}
		if (j == 10)
		buffer[bfc] = 37, bfc++, buffer[bfc] = format[i];
		}
		else
		{
			buffer[bfc] = format[i], bfc++;
		}
	}
	buffer[bfc] = '\0';
	write(1, buffer, bfc);
	return (va_end(args), free(buffer), bfc);
}
