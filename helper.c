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

	if (str[0] == '-')
		i = 1;
	else
		i = 0;

	for (; str[i] != '\0'; i++)
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

/**
 * global_mode - sets the mode if it is a stack or queue
 * @mode: mode of the program if it is STACK or QUEUE
 *
 * Return: void
 */
void set_mode(char *command)
{
	if (strcmp(command, "queue") == 0)
		GLOBAL_var.mode = QUEUE;
	else
		GLOBAL_var.mode = STACK;	
}
