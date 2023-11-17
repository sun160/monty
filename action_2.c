#include "monty.h"

/**
 * nothing - Does nothing.
 * @stack: Pointer to a to node of stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * change_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void change_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		 ex_error(8, line_number, "swap");
	x = (*stack)->next;
	(*stack)->next = x->next;
	if (x->next != NULL)
		x->next->prev = *stack;
	x->next = *stack;
	(*stack)->prev = x;
	x->prev = NULL;
	*stack = x;
}

/**
 * node_inc - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void node_inc(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		 ex_error(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_sub - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nodes_sub(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		 ex_error(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ex_error(8, line_number, "div");

	if ((*stack)->n == 0)
		ex_error(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
