#include "monty.h"
global_vars_t GLOBAL_var;
/**
 * main - main function, for running the monty executable
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: int, an exit status
 */
int main(int argc, char **argv)
{
	/* initializes stack */
	stack_t *head;

	head = NULL;
	GLOBAL_var.top = &head;

	/* checks if argument count is 2 */
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	parse(argv[1], &head);
	exit(EXIT_SUCCESS);
}
