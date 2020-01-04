#include "monty.h"
stack_t **GLOBAL_head;
/**
 * main - main function, for running the monty executable
 *
 * Return: int, an exit status
 **/
int main(int argc, char **argv)
{
	/* initialize stack */
	stack_t *head;
	head = NULL;
	GLOBAL_head = &head;

	/* checks if argument count is 2 */
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	parse(argv[1], &head);
	exit(EXIT_SUCCESS);
}
