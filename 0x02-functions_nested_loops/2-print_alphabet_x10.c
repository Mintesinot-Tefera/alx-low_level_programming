 #include "main.h"
/**
 * print_alphabet_x10-prints lowercase alphabets 10 times 
 */
void print_alphabet_x10(void)
{   
    int i;
    char la;

    i = 0;

    while (i < 10)
	{
		ch = 'a';
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		i++;
      } 
 } 
