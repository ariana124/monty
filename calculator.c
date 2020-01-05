#include "monty.h"

/**
 * do_add - function that adds the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_add(stack_t **stack, unsigned int line_number)
{
	int a, b, sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	sum = a + b;

	do_pop(stack, line_number);

	(*stack)->n = sum;
}


/**
 * do_sub - function that subtracts the second element by the first element
 * of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void do_sub(stack_t **stack, unsigned int line_number)
{
	int a, b, difference;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	difference = b - a;

	do_pop(stack, line_number);

	(*stack)->n = difference;
}


/**
 * do_mul - function that multiplies the first two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void do_mul(stack_t **stack, unsigned int line_number)
{
	int a, b, product;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;
	product = a * b;

	do_pop(stack, line_number);

	(*stack)->n = product;
}


/**
 * do_div - function that divides the second element by the first element
 * of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void do_div(stack_t **stack, unsigned int line_number)
{
	int a, b, quotient;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	if (a == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	quotient = b / a;

	do_pop(stack, line_number);

	(*stack)->n = quotient;
}


/**
 * do_mod - function that divides the second element by the first element of
 * the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void do_mod(stack_t **stack, unsigned int line_number)
{
	int a, b, mod;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	a = (*stack)->n;
	b = (*stack)->next->n;

	if (a == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	mod = b % a;

	do_pop(stack, line_number);

	(*stack)->n = mod;
}
