#include "monty.h"

/**
 * value_pr - Prints the Ascii value.
 * @stack: Pointer to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void value_pr(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		value_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		value_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * string_pr - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void string_pr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *x;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	x = *stack;
	while (x != NULL)
	{
		ascii = x->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		x = x->next;
	}
	printf("\n");
}

/**
 * rotate_n - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotate_n(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	x = *stack;
	while (x->next != NULL)
		x = x->next;

	x->next = *stack;
	(*stack)->prev = x;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotate_l - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotate_l(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *x;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	x = *stack;

	while (x->next != NULL)
		x = x->next;

	x->next = *stack;
	x->prev->next = NULL;
	x->prev = NULL;
	(*stack)->prev = x;
	(*stack) = x;
}
