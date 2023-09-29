#include "main.h"

/**
 * _print_rev_recursion - prindts a strding in rederse
 * @s: strindg to prindt
 */
void _print_rev_recursion(char *s)
{
	if (*s)
	{
		_print_rev_recursion(s + 1);
		_putchar(*s);
	}
}
