#include "monty.h"

/**
 * _isdigit - checks for a digit
 * @str: string
 *
 * Return: 0 means NO digit, 1 means there IS digit
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}

	return (1);
}


/**
 * dropnl - function that removes the newline at the end of a string
 * @src: source string
 *
 * Return: void
 */
void dropnl(char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		if (src[i] == '\n')
		{
			*(src + i) = '\0';
			return;
		}
	}
}
