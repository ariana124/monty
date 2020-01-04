#include "monty.h"

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

void free_fp_line(void)
{
	fclose(GLOBAL_var.fp);

	if (GLOBAL_var.line)
		free(GLOBAL_var.line);
}
