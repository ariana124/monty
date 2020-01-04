#include "monty.h"

/**
 * free_dataStructure - function that frees a data structure
 *
 * Return: void
 */
void free_dataStructure(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(GLOBAL_var.top);

	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}


/**
 * free_fp_line - function that frees the file pointer and line
 *
 * Return: void
 */
void free_fp_line(void)
{
	fclose(GLOBAL_var.fp);

	if (GLOBAL_var.line)
		free(GLOBAL_var.line);
}
