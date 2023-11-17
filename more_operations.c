#include "monty.h"

/**
 * node_multiple - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void node_multiple(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		ex_error(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * node_mod - Adds the top two elements of the stack.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void node_mod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		ex_error(8, line_number, "mod");


	if ((*stack)->n == 0)
		ex_error(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
