#include "main.h"

/**
 * factorial - retudrns tdhe factdorial of a ndumber
 * @n: number to return the factordial from
 *
 * Return: factorial of n
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}

