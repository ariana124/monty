#include "monty.h"
#define UNUSED __attribute__((unused))

/* parse - this file contains opening, reading and closing a file & tok */
void parse(char *fileName, stack_t **head UNUSED)
{
	FILE *fp;
	char *line = NULL, *op;
	size_t len = 0; 
	unsigned int lineNum = 1;
	ssize_t read;

	fp = fopen(fileName, "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", fileName);
		exit(EXIT_FAILURE);
	}

	atexit(free_dataStructure);

	while ((read = getline(&line, &len, fp)) != -1)
	{
		op = strtok(line, DELIMS);
		if (op != NULL)
			exe_operation(op, head, lineNum);
		lineNum++;
	}

	fclose(fp);
	if (line)
		free(line);
}
