#include "monty.h"


/**
 * do_pall - function that prints all the values in the stack, starting from
 * the top of the stack
 * @stack: pointer to the top of the stack
 * @UNUSED: unused line number
 *
 * Return: void
 */
void do_pall(stack_t **stack, unsigned int line_number UNUSED)
{
	stack_t *h = *stack;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}


/**
 * do_push - function that pushes an element to the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	char *str_num;
	int num;

	if (newnode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_fp_line();
		exit(EXIT_FAILURE);
	}

	str_num = strtok(NULL, DELIMS);
	if (str_num == NULL || _isdigit(str_num) == 0)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free_fp_line();
		free(newnode);
		exit(EXIT_FAILURE);
	}

	num = atoi(str_num);
	newnode->n = num;
	newnode->prev = NULL;

	if (stack == NULL || *stack == NULL)
	{
		*stack = newnode;
		newnode->next = NULL;
		return;
	}

	newnode->next = *stack;
	(*stack)->prev = newnode;
	*stack = newnode;
}


/**
 * do_pint - function that prints the first element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}


/**
 * do_pop - function that removes the first element of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	temp->prev = NULL;

	free(temp);
}


/**
 * do_swap - function that swaps the first two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: error line number
 *
 * Return: void
 */
void do_swap(stack_t **stack, unsigned int line_number)
{
	int temp1, temp2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp1 = (*stack)->n;
	temp2 = (*stack)->next->n;

	(*stack)->n = temp2;
	(*stack)->next->n = temp1;

}
