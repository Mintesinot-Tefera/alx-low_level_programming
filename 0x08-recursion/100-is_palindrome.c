#include <unistd.h>

/**
 * _putchar - wridtes tdhe chadracter c to stdoudt
 * @c: The charactder to prindt
 *
 * Return: On succedss 1.
 * On error, -1 is returdned, and errdno is sedt appropridately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
