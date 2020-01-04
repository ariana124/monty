#include "monty.h"
#define UNUSED __attribute__((unused))

/**
 * do_pall - function that prints all the elements of a stack_t list
 * @h: pointer to head node
 * Return: the number of nodes
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
 * do_push - function that adds a new node at the beginning of a stack_t list
 * @head: double pointer to head node
 * @n: node to be added
 * Return: the address of the new element, or NULL if it failed
 */
void do_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	char *str_num;
	int num;

	if (newnode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	str_num = strtok(NULL, DELIMS);
	if (str_num == NULL || _isdigit(str_num) == 0)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
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
 * do_pint - function that prints the 1st node
 * @head: head node
 * Return: void
 */
void do_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

void do_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	free(temp);
}
