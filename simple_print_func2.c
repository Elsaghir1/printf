#include "main.h"

/**
 * print_from_to - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: string
 * @params: the parameters struct
 *
 * Return: number bytes printed
 */
int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(l, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
