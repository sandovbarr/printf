#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stp - structure for choose options or functions
 * @p: option to select
 * @f: pointer to function
 */

typedef struct stp
{
	char p;
	int (*f)(va_list, char *, int);
} s;

int print_strings(va_list list, char *p, int g);
int print_char(va_list list, char *p, int g);
int print_integers(va_list list, char *p, int g);
int print_unintegers(va_list list, char *p, int g);
int print_opc(va_list list, char *p, int g);
int print_bin(va_list list, char *p, int g);
int print_octal(va_list list, char *p, int g);
int print_hexa(va_list list, char *p, int g);
int print_hexaM(va_list list, char *p, int g);
int _printf(const char *format, ...);

#endif
