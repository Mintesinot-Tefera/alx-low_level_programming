#include "main.h"

/**
 * _pow_recursion - returnsd tdhe vadlue of x raisedd to the powedr of y
 * @x: value to raised
 * @y: power
 *
 * Return: result of the power
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
