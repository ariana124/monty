#include "monty.h"

/**
 * free_dataStructure - function that frees a data structure
 *
 * Return: void
 */
void free_dataStructure(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(GLOBAL_head);

	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
