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
	stack_t *head, *tail;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		do_nop(stack, line_number);
		return;
	}

	head = *stack;
	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	tail->next = head;
	head->next = NULL;
	head->prev = tail;
}


/**
 * do_rotr - function that rotates the stack to the top, the top element of the
 * stack becomes the last one, and the second top element of the stack becomes
 * the first one
 * @stack: pointer to the stack
 * @line_number: line number
 *
 * Return: void
 */
void do_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		do_nop(stack, line_number);
		return;
	}

	head = *stack;
	tail = *stack;

	while (tail->next != NULL)
		tail = tail->next;

	tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head = tail;
	*stack = head;
}


/**
 * do_pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @UNUSED: line number
 *
 * Return: void
 */
void do_pstr(stack_t **stack, unsigned int line_number UNUSED)
{
	stack_t *h;
	int num;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	h = *stack;
	while (h != NULL)
	{
		num = h->n;
		if (num == 0 || !(num >= 0 && num <= 127))
			break;

		printf("%c", num);
		h = h->next;
	}
	printf("\n");
}
