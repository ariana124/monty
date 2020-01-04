#include "monty.h"

/**
 * parse - function that parses and reads the bytecode files
 * @fileName: file to be opened
 * @UNUSED: unused pointer to head
 *
 * Return: void
 */
void parse(char *fileName, stack_t **head UNUSED)
{
	FILE *fp;
	char *line = NULL, *op;
	size_t len = 0;
	unsigned int lineNum = 1;

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	GLOBAL_var.fp = fp;

	atexit(free_dataStructure);

	while (getline(&line, &len, fp) != -1)
	{
		GLOBAL_var.line = line;
		op = strtok(line, DELIMS);
		if (op != NULL)
			exe_operation(op, head, lineNum);
		lineNum++;
	}

	fclose(fp);
	if (line)
		free(line);
}
