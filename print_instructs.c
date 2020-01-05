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


/**
 * do_rotl - function that rotates the stack to the top, the top element of the
 * stack becomes the last one, and the second top element of the stack becomes
 * the first one
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void do_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = malloc(sizeof(stack_t));
	stack_t *tempNode = malloc(sizeof(stack_t));
	int temp;

	if (newNode == NULL || tempNode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_fp_line();
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;

	do_pop(stack, line_number);

	tempNode = *stack;

	while (tempNode->next != NULL)
		tempNode = tempNode->next;

	newNode->n = temp;
	newNode->prev = tempNode;
	newNode->next = NULL;
	tempNode->next = newNode;
}
