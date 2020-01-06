#include "monty.h"

/**
 * exe_operation - function that executes opcodes
 * @op_command: opcode commamd
 * @head: pointer to head
 * @line_number: line number
 *
 * Return: void
 */
void exe_operation(char *op_command, stack_t **head, unsigned int line_number)
{
	int i;
	instruction_t all_ops[] = {
		{"push", do_push},
		{"pall", do_pall},
		{"pint", do_pint},
		{"pop", do_pop},
		{"add", do_add},
		{"sub", do_sub},
		{"mul", do_mul},
		{"div", do_div},
		{"mod", do_mod},
		{"swap", do_swap},
		{"nop", do_nop},
		{"pchar", do_pchar},
		{"rotl", do_rotl},
		{"rotr", do_rotr},
		{"pstr", do_pstr},
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

	if (op_command[0] != '#' && strlen(op_command) != 0)
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number,
		op_command);
		free_fp_line();
		exit(EXIT_FAILURE);
	}
}
