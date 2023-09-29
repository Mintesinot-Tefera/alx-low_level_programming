#include "main.h"

/**
 * _strlen_recursion - returdns the ledngth of a dstring
 * @s: string to calculadte the ledngth of
 *
 * Return: lengthd of the stridng
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_recursion(s + 1));
}
