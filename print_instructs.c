#include "monty.h"

/**
 * do_pchar - function that prints the char at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (!(num >= 0 && num <= 127))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", num);
}
