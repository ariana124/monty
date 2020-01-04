#include "monty.h"


void exe_operation(char *op_command, stack_t **head, unsigned int line_number)
{
	int i;
	instruction_t all_ops[] = {
		{"push", do_push},
		{"pall", do_pall},
		{"pint", do_pint},
		{"pop", do_pop},
		{NULL, NULL}
	};

	for (i = 0; all_ops[i].opcode; i++)
	{
		if (strcmp(op_command, all_ops[i].opcode) == 0)
		{
			all_ops[i].f(head, line_number);
			return;
		}
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number,
	op_command);
	free_fp_line();	
	exit(EXIT_FAILURE);
}

