#ifndef MONTY_H
#define MONTY_H

#define DELIMS " \t\n\r"
#define UNUSED __attribute__((unused))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* helper functions */
void parse(char *fileName, stack_t **head);
void dropnl(char *src);
void exe_operation(char *operation, stack_t **head, unsigned int line_number);
int _isdigit(char *str);
void free_dataStructure(void);
void free_fp_line(void);

/* instructions */
void do_push(stack_t **stack, unsigned int line_number);
void do_pall(stack_t **stack, unsigned int line_number);
void do_pint(stack_t **stack, unsigned int line_number);
void do_pop(stack_t **stack, unsigned int line_number);
void do_add(stack_t **stack, unsigned int line_number);
void do_sub(stack_t **stack, unsigned int line_number);
void do_mul(stack_t **stack, unsigned int line_number);
void do_div(stack_t **stack, unsigned int line_number);
void do_mod(stack_t **stack, unsigned int line_number);
void do_swap(stack_t **stack, unsigned int line_number);
void do_nop(stack_t **stack, unsigned int line_number);
void do_pchar(stack_t **stack, unsigned int line_number);
void do_rotl(stack_t **stack, unsigned int line_number);
void do_pstr(stack_t **stack, unsigned int line_number);
void do_rotr(stack_t **stack, unsigned int line_number);

/* extern or global variable */

/**
 * struct global_vars_s - global structure
 * @top: points to the top of the stack
 * @fp: points to the file pointer
 * @line: points to the current line of the script
 *
 */

typedef struct global_vars_s
{
	stack_t **top;
	FILE *fp;
	char *line;
} global_vars_t;

extern global_vars_t GLOBAL_var;

#endif /* MONTY_H */
