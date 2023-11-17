#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger of the line munber
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *x;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	x = head;
	head = *new_node;
	head->next = x;
	x->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *x;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	x = *stack;
	while (x != NULL)
	{
		printf("%d\n", x->n);
		x = x->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *x;

	if (stack == NULL || *stack == NULL)
		ex_error(7, line_number);

	x = *stack;
	*stack = x->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(x);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		ex_error(6, line_number);
	printf("%d\n", (*stack)->n);
}
