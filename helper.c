#include "monty.h"

/**
 * _isdigit - checks for a digit
 * @c: number
 *
 *
 * Return: 0 means NOT digit; 1 means IS DIGIT
 *
 */
int _isdigit(char *str)
{
	int i;

	for(i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	}

	return (1);
}

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
