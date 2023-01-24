#include "main.h"
#include "_itoa.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - a function that produces
 * output according to a format
 * @format: a character string
 * Return: Number of characters printed
 * except the null byte used to end output
 * to strings
 */

int _printf(const char *format, ...)
{
	va_list aug;
	int n = 0;
	int l = 0;
	char buff[100] = {0};
	char * st;
	char tmp[100];

	va_start(aug, format);

	while (format && format[n])
	{
		if (format[n] == '%')
		{
			n++;
			switch (format[n])
			{
				case 'c':buff[l] = (char)va_arg(aug, int);
					 l++;
					 break;
				case 's':st = va_arg(aug, char*);
					 strcpy(&buff[l], st);
					 l += strlen(st);
					 break;
				case 'd':_itoa(va_arg(aug, int), tmp, 10);
					 strcpy(&buff[l], tmp);
					 l += strlen(tmp);
					 break;
			}
		}
		else
		{
			buff[l] = format[n];
			l++;
		}
		n++;
	}
	fwrite(buff, l, 1, stdout);
	va_end(aug);
	return (l);
}
