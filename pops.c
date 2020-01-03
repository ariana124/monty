#include "monty.h"

/**
 * do_pall - function that prints all the elements of a stack_t list
 * @h: pointer to head node
 * Return: the number of nodes
 */
int do_pall(stack_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	return (count);
}


/**
 * do_push - function that adds a new node at the beginning of a stack_t list
 * @head: double pointer to head node
 * @n: node to be added
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *do_push(stack_t **head, const int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));

	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->prev = NULL;
	if (*head == NULL)
	{
		*head = newnode;
		return (*head);
	}
	newnode->next = *head;
	(*head)->prev = newnode;
	*head = newnode;

	return (*head);
}


/**
 * do_pop - function that deletes node at a given index
 * @head: double pointer to head node
 * @index: the index of the node that should be deleted, index starts at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int do_pop(stack_t **head, unsigned int index)
{
	stack_t *temp, *link;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
		return (1);
	}

	temp = *head;

	for (i = 0; temp != NULL; i++)
	{
		if (i == index - 1)
		{
			if (temp->next == NULL)
				return (-1);
			link = temp->next->next;
			free(temp->next);
			temp->next = link;
			return (1);
		}
		temp = temp->next;
	}
	return (-1);
}


/**
 * do_pint - function that prints the 1st node
 * @head: head node
 * Return: void
 */
void do_pint(stack_t *head)
{
	printf("%d\n", head->n);
}
